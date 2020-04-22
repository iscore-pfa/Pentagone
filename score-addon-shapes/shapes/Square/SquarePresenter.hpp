#pragma once
#include <Device/Address/AddressSettings.hpp>
#include <Process/LayerPresenter.hpp>

#include <shapes/ShapePresenter.hpp>
#include <shapes/Square/SquareModel.hpp>

namespace Square
{

class View;
class Presenter : public Shapes::Presenter
{
public:

  explicit Presenter(
      const Square::ProcessModel& model,
      Square::View* view,
      const Process::Context& ctx,
      QObject* parent);

private:

  const Square::ProcessModel& m_layer;
  View* m_view{};
};
}
