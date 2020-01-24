// This is an open source non-commercial project. Dear PVS-Studio, please check
// it. PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "TrianglePresenter.hpp"
#include <Process/Focus/FocusDispatcher.hpp>

#include <score/command/Dispatchers/CommandDispatcher.hpp>
#include <score/document/DocumentContext.hpp>
#include <score/document/DocumentInterface.hpp>

#include <ossia/detail/math.hpp>

#include <Spline/SplineModel.hpp>
#include <Spline/SplinePresenter.hpp>
#include <Spline/SplineView.hpp>
#include <wobjectimpl.h>

namespace Triangle{

PresenterTriangle::PresenterTriangle(
    const Triangle::ProcessModel& layer,
    ViewTriangle* view,
    const Process::ProcessPresenterContext& ctx,
    QObject* parent)
    : LayerPresenter{ctx, parent}, m_layer{layer}, m_view{view}
{
  putToFront();
  connect(&m_layer, &ProcessModel::splineChanged, this, [&] { /////////////////////////////
    m_view->setSpline(m_layer.spline());
  });

  m_view->setSpline(m_layer.spline());
  connect(m_view, &ViewTriangle::changed, this, [&] {
    CommandDispatcher<>{context().context.commandStack}.submit<ChangeSplineTriangle>(
        layer, m_view->spline());
  });

  connect(m_view, &ViewTriangle::pressed, this, [&] {
    m_context.context.focusDispatcher.focus(this);
  });
  connect(
      m_view, &ViewTriangle::askContextMenu, this, &PresenterTriangle::contextMenuRequested);////
}


const Triangle::ProcessModel& PresenterTriangle::model() const
{
  return m_layer;
}

}
