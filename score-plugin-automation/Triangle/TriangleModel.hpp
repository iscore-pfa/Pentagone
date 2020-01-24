#pragma once
#include "../Spline/SplineModel.hpp"

namespace Triangle {

class SCORE_PLUGIN_AUTOMATION_EXPORT ProcessModel final
    : public ::Spline::ProcessModel
{
  SCORE_SERIALIZE_FRIENDS
  PROCESS_METADATA_IMPL(Triangle::ProcessModel)
  W_OBJECT(ProcessModel)

  public:

    ~ProcessModel() override;

    template <typename Impl>
    ProcessModel(Impl& vis, QObject* parent) : Process::ProcessModel{vis, parent}
    {
      vis.writeTo(*this);
      init();
    }
    ProcessModel(const TimeVal& duration,
        const Id<Process::ProcessModel>& id,
        QObject* parent);
    void init();

  private:
    //// ProcessModel ////
    void setDurationAndScale(const TimeVal& newDuration) noexcept override;
    void setDurationAndGrow(const TimeVal& newDuration) noexcept override;
    void setDurationAndShrink(const TimeVal& newDuration) noexcept override;

    bool contentHasDuration() const noexcept override;
    TimeVal contentDuration() const noexcept override;

    ossia::nodes::spline_data m_spline;

    bool m_tween = false;

    //W_PROPERTY(State::Unit, unit READ unit WRITE setUnit NOTIFY unitChanged)

    //W_PROPERTY(bool, tween READ tween WRITE setTween NOTIFY tweenChanged)

    //W_PROPERTY(State::AddressAccessor,address READ address WRITE setAddress NOTIFY addressChanged)

};
}
