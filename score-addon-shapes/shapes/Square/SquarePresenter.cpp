// This is an open source non-commercial project. Dear PVS-Studio, please check
// it. PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <Process/Focus/FocusDispatcher.hpp>

#include <score/command/Dispatchers/CommandDispatcher.hpp>
#include <score/document/DocumentContext.hpp>
#include <score/document/DocumentInterface.hpp>

#include <ossia/detail/math.hpp>

#include <shapes/ChangeShape.hpp>
#include <shapes/Square/SquareModel.hpp>
#include <shapes/Square/SquarePresenter.hpp>
#include <shapes/Square/SquareView.hpp>
#include <wobjectimpl.h>
namespace Square
{

Presenter::Presenter(
    const Square::ProcessModel& layer,
    View* view,
    const Process::Context& ctx,
    QObject* parent)
    : Shapes::Presenter{layer, view, ctx, parent}, m_layer{layer}, m_view{view}

{
  putToFront();
  connect(&m_layer, &ProcessModel::splineChanged, this, [&] {
    m_view->setShape(m_layer.spline());
  });

  m_view->setShape(m_layer.spline());
  connect(m_view, &View::changed, this, [&] {
    CommandDispatcher<>{context().context.commandStack}.submit<Shapes::ChangeShape>(
        layer, m_view->spline());
  });

  connect(m_view, &View::pressed, this, [&] {
    m_context.context.focusDispatcher.focus(this);
  });
  connect(
      m_view, &View::askContextMenu, this, &Presenter::contextMenuRequested);
}

}
