#pragma once
#include <Process/LayerView.hpp>

#include <ossia/editor/automation/tinysplinecpp.h>

#include <Heart/HeartModel.hpp>
#include <verdigris>
namespace Heart
{
class View : public Process::LayerView
{
  W_OBJECT(View)
public:
  View(QGraphicsItem* parent);

  void setHeart(ossia::nodes::spline_data d)
  {
    if (d != m_spline)
      m_spline = std::move(d);
    updateHeart();
    update();
  }

  const ossia::nodes::spline_data& spline() const { return m_spline; }

public:
  void changed() W_SIGNAL(changed);

private:
  void paint_impl(QPainter*) const override;
  void updateHeart();

  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
  //void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;

  optional<std::size_t> findControlPoint(QPointF point);
  void addPoint(const QPointF point);
  template <typename T>
  QPointF mapToCanvas(const T& point) const
  {
    return QPointF(point.x() * width(), height() - point.y() * height());
  }
  ossia::nodes::spline_point mapFromCanvas(const QPointF& point) const;

  ossia::nodes::spline_data m_spline;
  tinyspline::BSpline m_spl;
  optional<std::size_t> m_clicked;
};
}
