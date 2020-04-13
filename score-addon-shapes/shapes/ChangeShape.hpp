#pragma once
#include <shapes/ShapeModel.hpp>
#include <score/model/path/PathSerialization.hpp>
#include <shapes/CommandFactory.hpp>
namespace Shapes
{

class ChangeShape : public score::Command
{
  SCORE_COMMAND_DECL(
      Shapes::CommandFactoryName(),
      ChangeShape,
      "ChangeCircle")
public:
  ChangeShape(
      const ProcessModel& autom,
      const ossia::nodes::spline_data& newval)
      : m_path{autom}, m_old{autom.spline()}, m_new{newval}
  {
  }

public:
  void undo(const score::DocumentContext& ctx) const override
  {
    m_path.find(ctx).setShape(m_old);
  }
  void redo(const score::DocumentContext& ctx) const override
  {
    m_path.find(ctx).setShape(m_new);
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
  Path<ProcessModel> m_path;
  ossia::nodes::spline_data m_old, m_new;
};

}
