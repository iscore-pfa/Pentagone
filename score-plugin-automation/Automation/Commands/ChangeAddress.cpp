// This is an open source non-commercial project. Dear PVS-Studio, please check
// it. PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "ChangeAddress.hpp"

#include <Automation/AutomationModel.hpp>
#include <Curve/Point/CurvePointModel.hpp>
#include <Device/Address/AddressSettings.hpp>
#include <Device/Node/DeviceNode.hpp>
#include <Explorer/Explorer/DeviceExplorerModel.hpp>
#include <State/Address.hpp>
#include <State/Domain.hpp>
#include <State/Value.hpp>
#include <State/ValueConversion.hpp>

#include <score/model/path/Path.hpp>
#include <score/model/path/PathSerialization.hpp>
#include <score/model/tree/TreeNode.hpp>
#include <score/serialization/DataStreamVisitor.hpp>

#include <ossia/editor/state/destination_qualifiers.hpp>
#include <ossia/network/domain/domain.hpp>
#include <ossia/network/value/value_conversion.hpp>


#include <Color/GradientModel.hpp>
#include <Metronome/MetronomeModel.hpp>
#include <Spline/SplineModel.hpp>
#include <Polygon/PolygonModel.hpp>
#include <Pentagone/PentagoneModel.hpp>
#include <Hexagon/HexagonModel.hpp>
#include <Square/SquareModel.hpp>
#include <Rectangle/RectangleModel.hpp>
#include <Triangle/TriangleModel.hpp>

namespace Automation
{
ChangeAddress::ChangeAddress(
    const ProcessModel& autom,
    const State::AddressAccessor& newval)
    : m_path{autom}
    , m_old{autom.address(), autom.min(), autom.max()}
    , m_new(Explorer::makeFullAddressAccessorSettings(
          newval,
          score::IDocument::documentContext(autom),
          0.,
          1.))
{
  Curve::CurveDomain c(m_new.domain.get(), m_new.value);
  m_new.domain.get() = ossia::make_domain(c.min, c.max);
}

ChangeAddress::ChangeAddress(
    const ProcessModel& autom,
    Device::FullAddressAccessorSettings newval)
    : m_path{autom}
    , m_old{autom.address(), autom.min(), autom.max()}
    , m_new{std::move(newval)}
{
  Curve::CurveDomain c(m_new.domain.get(), m_new.value);
  m_new.domain.get() = ossia::make_domain(c.min, c.max);
}

ChangeAddress::ChangeAddress(
    const ProcessModel& autom,
    const Device::FullAddressSettings& newval)
    : m_path{autom}
{
  m_new.address = newval.address;
  m_new.domain = newval.domain;
  Curve::CurveDomain c(m_new.domain.get(), m_new.value);
  m_new.domain.get() = ossia::make_domain(c.min, c.max);
  m_new.address.qualifiers.get().unit = newval.unit;

  m_old.address = autom.address();
  m_old.domain = ossia::make_domain(autom.min(), autom.max());
}

void ChangeAddress::undo(const score::DocumentContext& ctx) const
{
  auto& autom = m_path.find(ctx);

  {
    // QSignalBlocker blck{autom.curve()};
    auto& dom = m_old.domain.get();
    autom.setMin(dom.convert_min<double>());
    autom.setMax(dom.convert_max<double>());

    autom.setAddress(m_old.address);
  }
  // autom.curve().changed();
}

void ChangeAddress::redo(const score::DocumentContext& ctx) const
{
  auto& autom = m_path.find(ctx);

  {
    // QSignalBlocker blck{autom.curve()};
    auto& dom = m_new.domain.get();
    autom.setMin(dom.convert_min<double>());
    autom.setMax(dom.convert_max<double>());
    autom.setAddress(m_new.address);
  }
  // autom.curve().changed();
}

void ChangeAddress::serializeImpl(DataStreamInput& s) const
{
  s << m_path << m_old << m_new;
}

void ChangeAddress::deserializeImpl(DataStreamOutput& s)
{
  s >> m_path >> m_old >> m_new;
}
}

namespace Spline
{
ChangeSplineAddress::ChangeSplineAddress(
    const ProcessModel& autom,
    const State::AddressAccessor& newval)
    : m_path{autom}, m_old{autom.address()}, m_new{newval}
{
}

void ChangeSplineAddress::undo(const score::DocumentContext& ctx) const
{
  auto& autom = m_path.find(ctx);
  autom.setAddress(m_old);
}

void ChangeSplineAddress::redo(const score::DocumentContext& ctx) const
{
  auto& autom = m_path.find(ctx);
  autom.setAddress(m_new);
}

void ChangeSplineAddress::serializeImpl(DataStreamInput& s) const
{
  s << m_path << m_old << m_new;
}

void ChangeSplineAddress::deserializeImpl(DataStreamOutput& s)
{
  s >> m_path >> m_old >> m_new;
}
}

namespace Polygon
{
ChangePolygonAddress::ChangePolygonAddress(
    const ProcessModel& autom,
    const State::AddressAccessor& newval)
    : m_path{autom}, m_old{autom.address()}, m_new{newval}
{
}

void ChangePolygonAddress::undo(const score::DocumentContext& ctx) const
{
  auto& autom = m_path.find(ctx);
  autom.setAddress(m_old);
}

void ChangePolygonAddress::redo(const score::DocumentContext& ctx) const
{
  auto& autom = m_path.find(ctx);
  autom.setAddress(m_new);
}

void ChangePolygonAddress::serializeImpl(DataStreamInput& s) const
{
  s << m_path << m_old << m_new;
}

void ChangePolygonAddress::deserializeImpl(DataStreamOutput& s)
{
  s >> m_path >> m_old >> m_new;
}
}

namespace Pentagone
{
ChangePentagoneAddress::ChangePentagoneAddress(
    const ProcessModel& autom,
    const State::AddressAccessor& newval)
    : m_path{autom}, m_old{autom.address()}, m_new{newval}
{
}

void ChangePentagoneAddress::undo(const score::DocumentContext& ctx) const
{
  auto& autom = m_path.find(ctx);
  autom.setAddress(m_old);
}

void ChangePentagoneAddress::redo(const score::DocumentContext& ctx) const
{
  auto& autom = m_path.find(ctx);
  autom.setAddress(m_new);
}

void ChangePentagoneAddress::serializeImpl(DataStreamInput& s) const
{
  s << m_path << m_old << m_new;
}

void ChangePentagoneAddress::deserializeImpl(DataStreamOutput& s)
{
  s >> m_path >> m_old >> m_new;
}
}

namespace Hexagon
{
ChangeHexagonAddress::ChangeHexagonAddress(
    const ProcessModel& autom,
    const State::AddressAccessor& newval)
    : m_path{autom}, m_old{autom.address()}, m_new{newval}
{
}

void ChangeHexagonAddress::undo(const score::DocumentContext& ctx) const
{
  auto& autom = m_path.find(ctx);
  autom.setAddress(m_old);
}

void ChangeHexagonAddress::redo(const score::DocumentContext& ctx) const
{
  auto& autom = m_path.find(ctx);
  autom.setAddress(m_new);
}

void ChangeHexagonAddress::serializeImpl(DataStreamInput& s) const
{
  s << m_path << m_old << m_new;
}

void ChangeHexagonAddress::deserializeImpl(DataStreamOutput& s)
{
  s >> m_path >> m_old >> m_new;
}
}

namespace Square
{
ChangeSquareAddress::ChangeSquareAddress(
    const ProcessModel& autom,
    const State::AddressAccessor& newval)
    : m_path{autom}, m_old{autom.address()}, m_new{newval}
{
}

void ChangeSquareAddress::undo(const score::DocumentContext& ctx) const
{
  auto& autom = m_path.find(ctx);
  autom.setAddress(m_old);
}

void ChangeSquareAddress::redo(const score::DocumentContext& ctx) const
{
  auto& autom = m_path.find(ctx);
  autom.setAddress(m_new);
}

void ChangeSquareAddress::serializeImpl(DataStreamInput& s) const
{
  s << m_path << m_old << m_new;
}

void ChangeSquareAddress::deserializeImpl(DataStreamOutput& s)
{
  s >> m_path >> m_old >> m_new;
}
}


namespace Rectangle
{
ChangeRectangleAddress::ChangeRectangleAddress(
    const ProcessModel& autom,
    const State::AddressAccessor& newval)
    : m_path{autom}, m_old{autom.address()}, m_new{newval}
{
}

void ChangeRectangleAddress::undo(const score::DocumentContext& ctx) const
{
  auto& autom = m_path.find(ctx);
  autom.setAddress(m_old);
}

void ChangeRectangleAddress::redo(const score::DocumentContext& ctx) const
{
  auto& autom = m_path.find(ctx);
  autom.setAddress(m_new);
}

void ChangeRectangleAddress::serializeImpl(DataStreamInput& s) const
{
  s << m_path << m_old << m_new;
}

void ChangeRectangleAddress::deserializeImpl(DataStreamOutput& s)
{
  s >> m_path >> m_old >> m_new;
}
}

namespace Triangle
{
ChangeTriangleAddress::ChangeTriangleAddress(
    const ProcessModel& autom,
    const State::AddressAccessor& newval)
    : m_path{autom}, m_old{autom.address()}, m_new{newval}
{
}

void ChangeTriangleAddress::undo(const score::DocumentContext& ctx) const
{
  auto& autom = m_path.find(ctx);
  autom.setAddress(m_old);
}

void ChangeTriangleAddress::redo(const score::DocumentContext& ctx) const
{
  auto& autom = m_path.find(ctx);
  autom.setAddress(m_new);
}

void ChangeTriangleAddress::serializeImpl(DataStreamInput& s) const
{
  s << m_path << m_old << m_new;
}

void ChangeTriangleAddress::deserializeImpl(DataStreamOutput& s)
{
  s >> m_path >> m_old >> m_new;
}
}

namespace Metronome
{
ChangeMetronomeAddress::ChangeMetronomeAddress(
    const ProcessModel& autom,
    const State::Address& newval)
    : m_path{autom}, m_old{autom.address()}, m_new{newval}
{
}

void ChangeMetronomeAddress::undo(const score::DocumentContext& ctx) const
{
  auto& autom = m_path.find(ctx);
  autom.setAddress(m_old);
}

void ChangeMetronomeAddress::redo(const score::DocumentContext& ctx) const
{
  auto& autom = m_path.find(ctx);
  autom.setAddress(m_new);
}

void ChangeMetronomeAddress::serializeImpl(DataStreamInput& s) const
{
  s << m_path << m_old << m_new;
}

void ChangeMetronomeAddress::deserializeImpl(DataStreamOutput& s)
{
  s >> m_path >> m_old >> m_new;
}
}
