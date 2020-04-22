#pragma once
#include <Device/Address/AddressSettings.hpp>
#include <Process/LayerPresenter.hpp>

#include <shapes/ShapePresenter.hpp>
#include <shapes/Circle/CircleModel.hpp>

namespace Circle
{

class View;
class Presenter : public Shapes::Presenter
{
public:

  explicit Presenter(
      const Circle::ProcessModel& model,
      Circle::View* view,
      const Process::Context& ctx,
      QObject* parent);

private:

  const Circle::ProcessModel& m_layer;
  View* m_view{};
};
}
