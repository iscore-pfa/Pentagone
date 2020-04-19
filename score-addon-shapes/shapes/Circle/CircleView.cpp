// This is an open source non-commercial project. Dear PVS-Studio, please check
// it. PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <Process/Style/ScenarioStyle.hpp>

#include <QPainter>

#include <shapes/Circle/CircleView.hpp>
#include <cmath>
// Disclaimer:
// Part of the code comes from splineeditor.cpp from
// the Qt project:
// Copyright (C) 2016 The Qt Company Ltd.
// https://github.com/qt/qtdeclarative/blob/dev/tools/qmleasing/splineeditor.cpp
#include <wobjectimpl.h>
W_OBJECT_IMPL(Circle::View)
namespace Circle
{
View::View(QGraphicsItem* parent) : Shapes::View{parent}
{
  static_assert(std::is_same<tinyspline::real, qreal>::value, "");
  this->setFlags(
      QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemClipsToShape);


}
void View::paint_impl(QPainter* p) const
{
  printf("HELLO \n");
    // TODO optimize painting here
    if (m_spline.points.empty())
      return;

    auto& skin = Process::Style::instance();
    QPainter& painter = *p;

    painter.setRenderHint(QPainter::Antialiasing);

    QPen segmt = skin.skin.Base4.main.pen2;

    QPainterPath path;
    auto p0 = m_spl.evaluate(0).result();
    path.moveTo(mapToCanvas(ossia::nodes::spline_point{p0[0], p0[1]}));
    const constexpr auto N = 500;
    for (std::size_t i = 1U; i < N; i++)
    {
      auto pt = m_spl.evaluate(double(i) / N).result();
      path.lineTo(mapToCanvas(ossia::nodes::spline_point{pt[0], pt[1]}));
    }
    painter.strokePath(path, segmt);

    const auto pts = m_spline.points.size();

    // Handle first point
    auto fp = mapToCanvas(m_spline.points[0]);

    const auto pointSize = 3.;

    if (m_clicked && 0 != *m_clicked)
      painter.setBrush(QColor(170, 220, 20));
    else
        painter.setBrush(QColor(170, 220, 220));

    painter.drawEllipse(QRectF{
        fp.x() - pointSize, fp.y() - pointSize, pointSize * 2., pointSize * 2.});

    // Remaining points
    //for (std::size_t i = 4U; i < pts-3; i++)
    for (std::size_t i = 1U; i < pts; i++)
    {
      painter.setPen(skin.skin.Emphasis3.darker.pen2_dotted_square_miter);
      QPointF p = mapToCanvas(m_spline.points[i]);
      painter.drawLine(fp, p);

      if (i != m_clicked) // Si i n'est pas cliqué
        if (i != 2) // Si i n'est pas le point to handle
          painter.setBrush(QColor(170, 220, 20)); // Point jaune
        else
          painter.setBrush(QColor(255, 0, 0)); // Point rouge
      else
        painter.setBrush(QColor(170, 220, 220)); // Bleu si cliqué
        //painter.setBrush(Qcolor(0, 0,255));


        painter.setPen(skin.TransparentPen());
        painter.drawEllipse(QRectF{
            p.x() - pointSize, p.y() - pointSize, pointSize * 2., pointSize * 2.});

      fp = p;
    }
}

void View::mouseMoveEvent(QGraphicsSceneMouseEvent* e)
{
  printf("Im here \n");
  auto p = mapFromCanvas(e->pos());
  if (!m_clicked)
    // If there is no click on a point
    return;
  const auto mp = *m_clicked;
  const auto N = m_spline.points.size();


  if (mp < N && mp == 2 && p.x() < 1 && p.y() < 1)
  {
    m_spline.points[mp] = {p.x(),p.x()};
    m_spline.points[0] = {p.x()/2,0};
    m_spline.points[1] = {p.x(),0};
    m_spline.points[3] = {p.x()/2,p.x()};
    m_spline.points[4] = {0,p.x()};
    m_spline.points[6] = {p.x()/2,0};

    std::cout << "Coords de p : " << p.x() << " " << p.y();

    updateShape();
    update();
  }
}
}
