#pragma once
#include <Device/Address/AddressSettings.hpp>
#include <Process/LayerPresenter.hpp>

#include <shapes/ShapePresenter.hpp>
#include <shapes/Polygon/PolygonModel.hpp>

namespace Polygon
{

class View;
class Presenter : public Shapes::Presenter
{
public:

  explicit Presenter(
      const Polygon::ProcessModel& model,
      Polygon::View* view,
      const Process::Context& ctx,
      QObject* parent);

private:

  const Polygon::ProcessModel& m_layer;
  View* m_view{};
};
}
