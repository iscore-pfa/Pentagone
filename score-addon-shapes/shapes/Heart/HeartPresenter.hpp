#pragma once
#include <Device/Address/AddressSettings.hpp>
#include <Process/LayerPresenter.hpp>

#include <shapes/ShapePresenter.hpp>
#include <shapes/Heart/HeartModel.hpp>

namespace Heart
{

class View;
class Presenter : public Shapes::Presenter
{
public:

  explicit Presenter(
      const Heart::ProcessModel& model,
      Heart::View* view,
      const Process::Context& ctx,
      QObject* parent);

private:

  const Heart::ProcessModel& m_layer;
  View* m_view{};
};
}
