// This is an open source non-commercial project. Dear PVS-Studio, please check
// it. PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <Process/Focus/FocusDispatcher.hpp>

#include <score/command/Dispatchers/CommandDispatcher.hpp>
#include <score/document/DocumentContext.hpp>
#include <score/document/DocumentInterface.hpp>

#include <ossia/detail/math.hpp>

#include <shapes/Hexagon/HexagonModel.hpp>
#include <shapes/Hexagon/HexagonPresenter.hpp>
#include <shapes/Hexagon/HexagonView.hpp>
#include <wobjectimpl.h>
namespace Hexagon
{
Presenter::Presenter(
    const Hexagon::ProcessModel& layer,
    View* view,
    const Process::Context& ctx,
    QObject* parent)
    : LayerPresenter{layer, view, ctx, parent}, m_layer{layer}, m_view{view}
{
  putToFront();
  connect(&m_layer, &ProcessModel::splineChanged, this, [&] {
    m_view->setHexagon(m_layer.spline());
  });

  m_view->setHexagon(m_layer.spline());
  connect(m_view, &View::changed, this, [&] {
    CommandDispatcher<>{context().context.commandStack}.submit<ChangeHexagon>(
        layer, m_view->spline());
  });

  connect(m_view, &View::pressed, this, [&] {
    m_context.context.focusDispatcher.focus(this);
  });
  connect(
      m_view, &View::askContextMenu, this, &Presenter::contextMenuRequested);
}

void Presenter::setWidth(qreal val, qreal defaultWidth)
{
  m_view->setWidth(val);
}

void Presenter::setHeight(qreal val)
{
  m_view->setHeight(val);
}

void Presenter::putToFront()
{
  m_view->setEnabled(true);
}

void Presenter::putBehind()
{
  m_view->setEnabled(false);
}

void Presenter::on_zoomRatioChanged(ZoomRatio r)
{
  m_zoomRatio = r;
  parentGeometryChanged();
}

void Presenter::parentGeometryChanged() {}

}
