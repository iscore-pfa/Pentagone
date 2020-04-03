// This is an open source non-commercial project. Dear PVS-Studio, please check
// it. PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "HexagonExecution.hpp"

#include <Process/ExecutionContext.hpp>
#include <score/tools/Bind.hpp>

#include <ossia/dataflow/nodes/spline.hpp>
namespace Hexagon
{
namespace RecreateOnPlay
{
using spline = ossia::nodes::spline;
Component::Component(
    ::Hexagon::ProcessModel& element,
    const ::Execution::Context& ctx,
    const Id<score::Component>& id,
    QObject* parent)
    : ::Execution::
          ProcessComponent_T<Hexagon::ProcessModel, ossia::node_process>{
              element,
              ctx,
              id,
              "Executor::HexagonComponent",
              parent}
{
  auto node = std::make_shared<spline>();
  this->node = node;
  m_ossia_process = std::make_shared<ossia::node_process>(node);

  con(element, &Hexagon::ProcessModel::splineChanged, this, [this] {
    this->recompute();
  });

  recompute();
}

Component::~Component() {}

void Component::recompute()
{
  const Execution::Context& s = this->system();
  auto g = process().spline();
  s.executionQueue.enqueue(
      [proc = std::dynamic_pointer_cast<spline>(OSSIAProcess().node), g] {
        proc->set_spline(g);
      });
}
}
}
