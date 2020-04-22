#pragma once
#include <Device/Address/AddressSettings.hpp>
#include <Process/LayerPresenter.hpp>

#include <shapes/ShapePresenter.hpp>
#include <shapes/Rectangle/RectangleModel.hpp>

namespace Rectangle
{

class View;
class Presenter : public Shapes::Presenter
{
public:

  explicit Presenter(
      const Rectangle::ProcessModel& model,
      Rectangle::View* view,
      const Process::Context& ctx,
      QObject* parent);

private:

  const Rectangle::ProcessModel& m_layer;
  View* m_view{};
};
}
