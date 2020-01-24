#pragma once
#include "../Spline/SplineExecution.hpp"

#include <Triangle/TriangleModel.hpp>

namespace Device
{
class DeviceList;
}

namespace Triangle
{
namespace RecreateOnPlay
{

class ComponentTriangle
: public ::Execution::
      ProcessComponent_T<Triangle::ProcessModel, ossia::node_process>
{
  COMPONENT_METADATA("fe635d49-cdb9-471c-88b2-80d4d45712f9")
public:
  ComponentTriangle(
      Triangle::ProcessModel& element,
      const ::Execution::Context& ctx,
      const Id<score::Component>& id,
      QObject* parent);
  ~ComponentTriangle() override;

private:
  void recompute();
};
using ComponentFactory = ::Execution::ProcessComponentFactory_T<ComponentTriangle>;
}



SCORE_CONCRETE_COMPONENT_FACTORY(
    Execution::ProcessComponentFactory,
    Triangle::RecreateOnPlay::ComponentFactory)
