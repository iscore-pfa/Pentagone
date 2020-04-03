#pragma once
#include <shapes/ShapeModel.hpp>

#include <Process/Execution/ProcessComponent.hpp>
#include <Process/ExecutionContext.hpp>

#include <score/tools/Bind.hpp>
#include <ossia/dataflow/node_process.hpp>
#include <ossia/dataflow/nodes/spline.hpp>

namespace Shapes
{
class Executor
    : public ::Execution::
    ProcessComponent_T<Shapes::ProcessModel, ossia::node_process>
{
  COMPONENT_METADATA("7a8119fb-c65b-4952-bcb5-c38a9e1fdc08")
public:
  Executor(
      Shapes::ProcessModel& element,
      const ::Execution::Context& ctx,
      const Id<score::Component>& id,
      QObject* parent)
    :  Execution::ProcessComponent_T<Shapes::ProcessModel, ossia::node_process>{
         element,
         ctx,
         id,
         "Executor::ShapesComponent",
         parent}
  {
    auto node = std::make_shared<ossia::nodes::spline>();
    this->node = node;
    m_ossia_process = std::make_shared<ossia::node_process>(node);

    con(element, &Shapes::ProcessModel::splineChanged, this, [this] {
      this->recompute();
    });

    recompute();
  }

  ~Executor() override
  {

  }

  void recompute()
  {
    const Execution::Context& s = this->system();
    auto g = process().spline();
    s.executionQueue.enqueue(
        [proc = std::dynamic_pointer_cast<ossia::nodes::spline>(OSSIAProcess().node), g] {
          proc->set_spline(g);
        });
  }

};
using ExecutorFactory = ::Execution::ProcessComponentFactory_T<Executor>;
}

SCORE_CONCRETE_COMPONENT_FACTORY(
    Execution::ProcessComponentFactory,
    Shapes::ComponentFactory)
