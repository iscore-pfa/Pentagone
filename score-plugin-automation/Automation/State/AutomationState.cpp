// This is an open source non-commercial project. Dear PVS-Studio, please check
// it. PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "AutomationState.hpp"

#include <Automation/AutomationModel.hpp>
#include <Explorer/DocumentPlugin/DeviceDocumentPlugin.hpp>
#include <Explorer/Explorer/DeviceExplorerModel.hpp>
#include <Process/State/ProcessStateDataInterface.hpp>
#include <State/Address.hpp>
#include <State/Message.hpp>
#include <State/Value.hpp>
#include <State/ValueConversion.hpp>

#include <score/document/DocumentContext.hpp>
#include <score/document/DocumentInterface.hpp>
#include <score/model/IdentifiedObjectMap.hpp>
#include <score/tools/Bind.hpp>

#include <ossia/network/dataspace/dataspace_visitors.hpp>

class QObject;
namespace Automation
{
ProcessState::ProcessState(
    ProcessModel& model,
    double watchedPoint,
    QObject* parent)
    : ProcessStateDataInterface{model, parent}, m_point{watchedPoint}
{
  SCORE_ASSERT(0 <= watchedPoint && watchedPoint <= 1);

  con(this->process(),
      &ProcessModel::curveChanged,
      this,
      &ProcessStateDataInterface::stateChanged);

  con(this->process(),
      &ProcessModel::addressChanged,
      this,
      &ProcessStateDataInterface::stateChanged);
}

// TESTME
::State::Message ProcessState::message() const
{
  if (m_point == 0. && process().tween())
    return {};

  // Set-up a message
  ::State::Message m;
  m.address = process().address();

  // Look in the tree if there is a corresponding node,
  // so that we can get the type that we should convert to.
  // Default is float.
  ossia::value treeValue = ossia::value(0.f);
  auto& ctx = score::IDocument::documentContext(process());
  auto tree = ctx.findPlugin<Explorer::DeviceDocumentPlugin>();
  if (tree)
  {
    auto node
        = Device::try_getNodeFromAddress(tree->rootNode(), m.address.address);
    if (node && node->is<Device::AddressSettings>())
    {
      treeValue = node->get<Device::AddressSettings>().value;
    }
  }

  for (const auto& seg : process().curve().segments())
  {
    // OPTIMIZEME introduce another index on that has an ordering on curve
    // segments
    // to make this fast (just checking for the first and the last).
    if (seg.start().x() <= m_point && seg.end().x() >= m_point)
    {
      m.value = float(
          seg.valueAt(m_point) * (process().max() - process().min())
          + process().min());

      return m;
    }
  }

  return {};
}

double ProcessState::point() const
{
  return m_point;
}

ProcessModel& ProcessState::process() const
{
  return static_cast<ProcessModel&>(ProcessStateDataInterface::process());
}

std::vector<State::AddressAccessor> ProcessState::matchingAddresses()
{
  // TODO have a better check of "address validity"
  if (!process().address().address.device.isEmpty())
    return {process().address()};
  return {};
}

::State::MessageList ProcessState::messages() const
{
  if (!process().address().address.device.isEmpty())
  {
    auto mess = message();
    if (!mess.address.address.device.isEmpty())
      return {mess};
  }

  return {};
}

// TESTME
::State::MessageList ProcessState::setMessages(
    const ::State::MessageList& received,
    const Process::MessageNode&)
{
  if (m_point != 0. && m_point != 1.)
    return messages();

  const auto& segs = process().curve().segments();
  for (const auto& mess : received)
  {
    if (mess.address == process().address())
    {
      // Scale min, max, and the value
      // TODO convert to the real type of the curve.
      auto val = State::convert::value<float>(mess.value);
      if (val < process().min() && std::abs(val - process().min()) > 1e-9)
        process().setMin(val);
      if (val > process().max() && std::abs(val - process().max()) > 1e-9)
        process().setMax(val);

      val = (val - process().min()) / (process().max() - process().min());

      if (m_point == 0.)
      {
        // Find first segment
        // TODO ordering would help, here.
        auto seg_it = std::find_if(
            segs.begin(), segs.end(), [](Curve::SegmentModel& segt) {
              return segt.start().x() == 0.;
            });
        if (seg_it != segs.end())
        {
          if (val != seg_it->start().y())
          {
            seg_it->setStart({0, val});
          }
        }
      }
      else if (m_point == 1)
      {
        // Find last segment
        auto seg_it = std::find_if(
            segs.begin(), segs.end(), [](Curve::SegmentModel& segt) {
              return segt.end().x() == 1;
            });
        if (seg_it != segs.end())
        {
          if (val != seg_it->end().y())
            seg_it->setEnd({1, val});
        }
      }
      return messages();
    }
  }
  return messages();
}
}
