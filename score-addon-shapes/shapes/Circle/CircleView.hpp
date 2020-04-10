#pragma once
#include <Process/LayerView.hpp>

#include <ossia/editor/automation/tinysplinecpp.h>

#include <shapes/ShapeModel.hpp>
#include <verdigris>

#include <wobjectimpl.h>


W_OBJECT_IMPL(Circle::View)
namespace Circle
{
class View : public Shapes::View
{
  W_OBJECT(View)
public:
  View(QGraphicsItem* parent);

  using Shapes::View::View;
};
}
