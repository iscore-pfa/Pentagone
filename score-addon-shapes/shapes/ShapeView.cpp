#include <Process/Style/ScenarioStyle.hpp>

#include <QPainter>

#include <shapes/ShapeView.hpp>
#include <cmath>
#include <wobjectimpl.h>


W_OBJECT_IMPL(Shapes::View)
namespace Shapes
{
View::View(QGraphicsItem* parent) : LayerView{parent}
{
  static_assert(std::is_same<tinyspline::real, qreal>::value, "");
  this->setFlags(
      QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemClipsToShape);
}


ossia::nodes::spline_point View::mapFromCanvas(const QPointF& point) const
{
  return ossia::nodes::spline_point{(double)point.x() / width(),
                                    1. - point.y() / height()};
}


void View::updateShape()
{
  m_spl = tinyspline::BSpline{3, 2, m_spline.points.size(), TS_CLAMPED};
  ts_bspline_set_ctrlp(
      m_spl.data(),
      reinterpret_cast<const tinyspline::real*>(m_spline.points.data()),
      m_spl.data());
}

void View::mousePressEvent(QGraphicsSceneMouseEvent* e)
{
  // Allow to "catch" points"
  auto btn = e->button();
  if (btn == Qt::LeftButton)
  {
    if ((m_clicked = findControlPoint(e->pos())))
    {
      mouseMoveEvent(e);
    }
    e->accept();
  }
  else if (btn == Qt::RightButton)
  {
    // Delete

    updateShape();
  }
}

void View::mouseMoveEvent(QGraphicsSceneMouseEvent* e)
{
  auto p = mapFromCanvas(e->pos());
  if (!m_clicked)
    // If there is no click on a point
    return;
  const auto mp = *m_clicked;
  const auto N = m_spline.points.size();

/*
  if (mp < N && mp == 2)
  {
    m_spline.points[mp] = {p.x(),p.x()};
    m_spline.points[0] = {p.x()/2,0};
    m_spline.points[1] = {p.x(),0};
    m_spline.points[3] = {p.x()/2,p.x()};
    m_spline.points[4] = {0,p.x()};
    m_spline.points[6] = {p.x()/2,0};

    std::cout << "Coords de p : " << p.x() << " " << p.y();

    updateCircle();
    update();
    */



  }

void View::mouseReleaseEvent(QGraphicsSceneMouseEvent* e)
{
  if (m_clicked)
  {
    changed();
    m_clicked = ossia::none;
  }
  e->accept();
}

optional<std::size_t> View::findControlPoint(QPointF point)
{
  int pointIndex = -1;
  qreal distance = -1;

  const auto N = m_spline.points.size();
  for (std::size_t i = 0; i < N; ++i)
  {
    qreal d = QLineF{point, mapToCanvas(m_spline.points.at(i))}.length();
    if ((distance < 0 && d < 10) || d < distance)
    {
      distance = d;
      pointIndex = i;
    }
  }

  if (pointIndex != -1)
    return pointIndex;
  return {};
}
}
