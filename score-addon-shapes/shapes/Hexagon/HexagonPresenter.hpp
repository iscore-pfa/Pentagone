#pragma once
#include <Device/Address/AddressSettings.hpp>
#include <Process/LayerPresenter.hpp>

#include <shapes/ShapePresenter.hpp>
#include <shapes/Hexagon/HexagonModel.hpp>

namespace Hexagon
{

class View;
class Presenter : public Shapes::Presenter
{
public:

  explicit Presenter(
      const Hexagon::ProcessModel& model,
      Hexagon::View* view,
      const Process::Context& ctx,
      QObject* parent);

private:

  const Hexagon::ProcessModel& m_layer;
  View* m_view{};
};
}
