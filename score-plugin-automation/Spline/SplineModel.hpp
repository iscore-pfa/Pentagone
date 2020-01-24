#pragma once
#include <Process/Process.hpp>
#include <State/Address.hpp>
#include <State/Unit.hpp>

#include <ossia/dataflow/nodes/spline.hpp>

#include <Spline/SplineMetadata.hpp>
#include <score_plugin_automation_export.h>
#include <verdigris>

namespace Spline
{

class SCORE_PLUGIN_AUTOMATION_EXPORT ProcessModel
    : public Process::ProcessModel
{
  SCORE_SERIALIZE_FRIENDS
  PROCESS_METADATA_IMPL(Spline::ProcessModel)

  W_OBJECT(ProcessModel)

public:
  ProcessModel(
      const TimeVal& duration,
      const Id<Process::ProcessModel>& id,
      QObject* parent);
  ~ProcessModel() override;

  template <typename Impl>
  ProcessModel(Impl& vis, QObject* parent) : Process::ProcessModel{vis, parent}
  {
    vis.writeTo(*this);
    init();
  }

  void init();
  State::AddressAccessor address() const;
  void setAddress(const State::AddressAccessor& arg);
  State::Unit unit() const;
  void setUnit(const State::Unit&);

  bool tween() const { return m_tween; }
  void setTween(bool tween)
  {
    if (m_tween == tween)
      return;

    m_tween = tween;
    tweenChanged(tween);
  }

  QString prettyName() const noexcept override;

  const ossia::nodes::spline_data& spline() const noexcept { return m_spline; }
  void setSpline(const ossia::nodes::spline_data& c)
  {
    if (m_spline != c)
    {
      m_spline = c;
      splineChanged();
    }
  }

  std::unique_ptr<Process::Outlet> outlet;

public:
  void addressChanged(const ::State::AddressAccessor& arg_1)
      E_SIGNAL(SCORE_PLUGIN_AUTOMATION_EXPORT, addressChanged, arg_1);
  void tweenChanged(bool tween)
      E_SIGNAL(SCORE_PLUGIN_AUTOMATION_EXPORT, tweenChanged, tween);
  void unitChanged(const State::Unit& arg_1)
      E_SIGNAL(SCORE_PLUGIN_AUTOMATION_EXPORT, unitChanged, arg_1);
  void splineChanged() E_SIGNAL(SCORE_PLUGIN_AUTOMATION_EXPORT, splineChanged);

private:
  //// ProcessModel ////
  void setDurationAndScale(const TimeVal& newDuration) noexcept override;
  void setDurationAndGrow(const TimeVal& newDuration) noexcept override;
  void setDurationAndShrink(const TimeVal& newDuration) noexcept override;

  bool contentHasDuration() const noexcept override;
  TimeVal contentDuration() const noexcept override;

  ossia::nodes::spline_data m_spline;

  bool m_tween = false;

  W_PROPERTY(State::Unit, unit READ unit WRITE setUnit NOTIFY unitChanged)

  W_PROPERTY(bool, tween READ tween WRITE setTween NOTIFY tweenChanged)

  W_PROPERTY(
      State::AddressAccessor,
      address READ address WRITE setAddress NOTIFY addressChanged)
};
}
