#pragma once
#include <Device/Address/AddressSettings.hpp>
#include <Process/LayerPresenter.hpp>

#include <shapes/Circle/CircleModel.hpp>

namespace Circle
{

class View;
class Presenter : public Process::LayerPresenter
{
public:
  explicit Presenter(
      const Circle::ProcessModel& model,
      Circle::View* view,
      const Process::Context& ctx,
      QObject* parent);

  void setWidth(qreal width, qreal defaultWidth) override;
  void setHeight(qreal height) override;

  void putToFront() override;
  void putBehind() override;

  void on_zoomRatioChanged(ZoomRatio) override;

  void parentGeometryChanged() override;

private:
  const Circle::ProcessModel& m_layer;
  View* m_view{};
  ZoomRatio m_zoomRatio{};
};
}
