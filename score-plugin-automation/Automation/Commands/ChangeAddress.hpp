#pragma once
#include <Automation/Commands/AutomationCommandFactory.hpp>
#include <Curve/Palette/CurvePoint.hpp>
#include <Device/Address/AddressSettings.hpp>

#include <score/command/Command.hpp>
#include <score/model/path/Path.hpp>

struct DataStreamInput;
struct DataStreamOutput;
namespace State
{
struct Address;
} // namespace score

namespace Automation
{
class ProcessModel;
class ChangeAddress final : public score::Command
{
  SCORE_COMMAND_DECL(CommandFactoryName(), ChangeAddress, "ChangeAddress")
public:
  ChangeAddress(
      const ProcessModel& autom,
      const State::AddressAccessor& newval);
  ChangeAddress(
      const ProcessModel& autom,
      Device::FullAddressAccessorSettings newval);
  ChangeAddress(
      const ProcessModel& autom,
      const Device::FullAddressSettings& newval);

public:
  void undo(const score::DocumentContext& ctx) const override;
  void redo(const score::DocumentContext& ctx) const override;

protected:
  void serializeImpl(DataStreamInput&) const override;
  void deserializeImpl(DataStreamOutput&) override;

private:
  Path<ProcessModel> m_path;
  Device::FullAddressAccessorSettings m_old, m_new;
};
}

namespace Spline
{
class ProcessModel;
class ChangeSplineAddress final : public score::Command
{
  SCORE_COMMAND_DECL(
      Automation::CommandFactoryName(),
      ChangeSplineAddress,
      "ChangeSplineAddress")
public:
  ChangeSplineAddress(
      const ProcessModel& autom,
      const State::AddressAccessor& newval);

public:
  void undo(const score::DocumentContext& ctx) const override;
  void redo(const score::DocumentContext& ctx) const override;

protected:
  void serializeImpl(DataStreamInput&) const override;
  void deserializeImpl(DataStreamOutput&) override;

private:
  Path<ProcessModel> m_path;
  State::AddressAccessor m_old, m_new;
};
}

namespace Polygon
{
class ProcessModel;
class ChangePolygonAddress final : public score::Command
{
  SCORE_COMMAND_DECL(
      Automation::CommandFactoryName(),
      ChangePolygonAddress,
      "ChangePolygonAddress")
public:
  ChangePolygonAddress(
      const ProcessModel& autom,
      const State::AddressAccessor& newval);

public:
  void undo(const score::DocumentContext& ctx) const override;
  void redo(const score::DocumentContext& ctx) const override;

protected:
  void serializeImpl(DataStreamInput&) const override;
  void deserializeImpl(DataStreamOutput&) override;

private:
  Path<ProcessModel> m_path;
  State::AddressAccessor m_old, m_new;
};
}

namespace Pentagone
{
class ProcessModel;
class ChangePentagoneAddress final : public score::Command
{
  SCORE_COMMAND_DECL(
      Automation::CommandFactoryName(),
      ChangePentagoneAddress,
      "ChangePentagoneAddress")
public:
  ChangePentagoneAddress(
      const ProcessModel& autom,
      const State::AddressAccessor& newval);

public:
  void undo(const score::DocumentContext& ctx) const override;
  void redo(const score::DocumentContext& ctx) const override;

protected:
  void serializeImpl(DataStreamInput&) const override;
  void deserializeImpl(DataStreamOutput&) override;

private:
  Path<ProcessModel> m_path;
  State::AddressAccessor m_old, m_new;
};
}

namespace Hexagon
{
class ProcessModel;
class ChangeHexagonAddress final : public score::Command
{
  SCORE_COMMAND_DECL(
      Automation::CommandFactoryName(),
      ChangeHexagonAddress,
      "ChangeHexagonAddress")
public:
  ChangeHexagonAddress(
      const ProcessModel& autom,
      const State::AddressAccessor& newval);

public:
  void undo(const score::DocumentContext& ctx) const override;
  void redo(const score::DocumentContext& ctx) const override;

protected:
  void serializeImpl(DataStreamInput&) const override;
  void deserializeImpl(DataStreamOutput&) override;

private:
  Path<ProcessModel> m_path;
  State::AddressAccessor m_old, m_new;
};
}

namespace Square
{
class ProcessModel;
class ChangeSquareAddress final : public score::Command
{
  SCORE_COMMAND_DECL(
      Automation::CommandFactoryName(),
      ChangeSquareAddress,
      "ChangeSquareAddress")
public:
  ChangeSquareAddress(
      const ProcessModel& autom,
      const State::AddressAccessor& newval);

public:
  void undo(const score::DocumentContext& ctx) const override;
  void redo(const score::DocumentContext& ctx) const override;

protected:
  void serializeImpl(DataStreamInput&) const override;
  void deserializeImpl(DataStreamOutput&) override;

private:
  Path<ProcessModel> m_path;
  State::AddressAccessor m_old, m_new;
};
}


namespace Circle
{
class ProcessModel;
class ChangeCircleAddress final : public score::Command
{
  SCORE_COMMAND_DECL(
      Automation::CommandFactoryName(),
      ChangeCircleAddress,
      "ChangeCircleAddress")
public:
  ChangeCircleAddress(
      const ProcessModel& autom,
      const State::AddressAccessor& newval);

public:
  void undo(const score::DocumentContext& ctx) const override;
  void redo(const score::DocumentContext& ctx) const override;

protected:
  void serializeImpl(DataStreamInput&) const override;
  void deserializeImpl(DataStreamOutput&) override;

private:
  Path<ProcessModel> m_path;
  State::AddressAccessor m_old, m_new;
};
}

namespace Infinite
{
class ProcessModel;
class ChangeInfiniteAddress final : public score::Command
{
  SCORE_COMMAND_DECL(
      Automation::CommandFactoryName(),
      ChangeInfiniteAddress,
      "ChangeInfiniteAddress")
public:
  ChangeInfiniteAddress(
      const ProcessModel& autom,
      const State::AddressAccessor& newval);

public:
  void undo(const score::DocumentContext& ctx) const override;
  void redo(const score::DocumentContext& ctx) const override;

protected:
  void serializeImpl(DataStreamInput&) const override;
  void deserializeImpl(DataStreamOutput&) override;

private:
  Path<ProcessModel> m_path;
  State::AddressAccessor m_old, m_new;
};
}


namespace Heart
{
class ProcessModel;
class ChangeHeartAddress final : public score::Command
{
  SCORE_COMMAND_DECL(
      Automation::CommandFactoryName(),
      ChangeHeartAddress,
      "ChangeHeartAddress")
public:
  ChangeHeartAddress(
      const ProcessModel& autom,
      const State::AddressAccessor& newval);

public:
  void undo(const score::DocumentContext& ctx) const override;
  void redo(const score::DocumentContext& ctx) const override;

protected:
  void serializeImpl(DataStreamInput&) const override;
  void deserializeImpl(DataStreamOutput&) override;

private:
  Path<ProcessModel> m_path;
  State::AddressAccessor m_old, m_new;
};
}

namespace Rectangle
{
class ProcessModel;
class ChangeRectangleAddress final : public score::Command
{
  SCORE_COMMAND_DECL(
      Automation::CommandFactoryName(),
      ChangeRectangleAddress,
      "ChangeRectangleAddress")
public:
  ChangeRectangleAddress(
      const ProcessModel& autom,
      const State::AddressAccessor& newval);

public:
  void undo(const score::DocumentContext& ctx) const override;
  void redo(const score::DocumentContext& ctx) const override;

protected:
  void serializeImpl(DataStreamInput&) const override;
  void deserializeImpl(DataStreamOutput&) override;

private:
  Path<ProcessModel> m_path;
  State::AddressAccessor m_old, m_new;
};
}

namespace Triangle
{
class ProcessModel;
class ChangeTriangleAddress final : public score::Command
{
  SCORE_COMMAND_DECL(
      Automation::CommandFactoryName(),
      ChangeTriangleAddress,
      "ChangeTriangleAddress")
public:
  ChangeTriangleAddress(
      const ProcessModel& autom,
      const State::AddressAccessor& newval);

public:
  void undo(const score::DocumentContext& ctx) const override;
  void redo(const score::DocumentContext& ctx) const override;

protected:
  void serializeImpl(DataStreamInput&) const override;
  void deserializeImpl(DataStreamOutput&) override;

private:
  Path<ProcessModel> m_path;
  State::AddressAccessor m_old, m_new;
};
}


namespace Metronome
{
class ProcessModel;
class ChangeMetronomeAddress final : public score::Command
{
  SCORE_COMMAND_DECL(
      Automation::CommandFactoryName(),
      ChangeMetronomeAddress,
      "ChangeMetronomeAddress")
public:
  ChangeMetronomeAddress(
      const ProcessModel& autom,
      const State::Address& newval);

public:
  void undo(const score::DocumentContext& ctx) const override;
  void redo(const score::DocumentContext& ctx) const override;

protected:
  void serializeImpl(DataStreamInput&) const override;
  void deserializeImpl(DataStreamOutput&) override;

private:
  Path<ProcessModel> m_path;
  State::Address m_old, m_new;
};
}
