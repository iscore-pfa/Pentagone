#pragma once
#include "Spline/SplinePresenter.hpp"

namespace Triangle{


class ChangeSplineTriangle final : public ::Spline::ChangeSpline
{
  SCORE_COMMAND_DECL(
      Automation::CommandFactoryName(),
      ChangeSplineTriangle,
      "ChangeSplineTriangle")
public:
  ChangeSplineTriangle(
      const ProcessModel& autom,
      const ossia::nodes::spline_data& newval)
      : m_path{autom}, m_old{autom.spline()}, m_new{newval}
  {
  }

protected:
  void serializeImpl(DataStreamInput& s) const override
  {
    s << m_path << m_old << m_new;
  }
  void deserializeImpl(DataStreamOutput& s) override
  {
    s >> m_path >> m_old >> m_new;
  }

private:
  Path<ProcessModel> m_path;/////////////////////////////////////////////////
  ossia::nodes::spline_data m_old, m_new;
};

class ViewTriangle;
class PresenterTriangle final : public ::Spline::Presenter
{
public:
  explicit PresenterTriangle(
      const ProcessModel& model,
      ViewTriangle* view,
      const Process::ProcessPresenterContext& ctx,
      QObject* parent);

private:
  const ProcessModel& m_layer;
  ViewTriangle* m_view{};
  ZoomRatio m_zoomRatio{};
};
}
