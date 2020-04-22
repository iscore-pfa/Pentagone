#pragma once
#include <Device/Address/AddressSettings.hpp>
#include <Process/LayerPresenter.hpp>

#include <shapes/ShapePresenter.hpp>
#include <shapes/Pentagone/PentagoneModel.hpp>

namespace Pentagone
{

class View;
class Presenter : public Shapes::Presenter
{
public:

  explicit Presenter(
      const Pentagone::ProcessModel& model,
      Pentagone::View* view,
      const Process::Context& ctx,
      QObject* parent);

private:

  const Pentagone::ProcessModel& m_layer;
  View* m_view{};
};
}
