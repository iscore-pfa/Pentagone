#pragma once
#include "../Spline/SplineView.hpp"

namespace Triangle{

class ViewTriangle : public Spline::View
{
  W_OBJECT(ViewTriangle)
public:
  ViewTriangle(QGraphicsItem* parent);

private:
  void paint_impl(QPainter*) const override;
  void updateSpline();

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
