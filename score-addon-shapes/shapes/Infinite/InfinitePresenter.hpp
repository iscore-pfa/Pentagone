#pragma once
#include <Device/Address/AddressSettings.hpp>
#include <Process/LayerPresenter.hpp>

#include <shapes/ShapePresenter.hpp>
#include <shapes/Infinite/InfiniteModel.hpp>

namespace Infinite
{

class View;
class Presenter : public Shapes::Presenter
{
public:

  explicit Presenter(
      const Infinite::ProcessModel& model,
      Infinite::View* view,
      const Process::Context& ctx,
      QObject* parent);

private:

  const Infinite::ProcessModel& m_layer;
  View* m_view{};
};
}
