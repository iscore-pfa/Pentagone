#pragma once
#include <Process/LayerView.hpp>

#include <ossia/editor/automation/tinysplinecpp.h>

#include <shapes/ShapeModel.hpp>
#include <shapes/ShapeView.hpp>
#include <verdigris>

#include <wobjectimpl.h>


namespace Circle
{
class View : public Shapes::View
{
  W_OBJECT(View)
public:
  View(QGraphicsItem* parent);

  //using Shapes::View::View;
  void paint_impl(QPainter* p) const override;

};


}
