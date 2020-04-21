// This is an open source non-commercial project. Dear PVS-Studio, please check
// it. PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <Process/Dataflow/Port.hpp>
#include <shapes/ShapeModel.hpp>
#include <ossia/editor/state/destination_qualifiers.hpp>

#include <wobjectimpl.h>

#define PI 3.14159265359

W_OBJECT_IMPL(Shapes::ProcessModel)
namespace Shapes
{
ProcessModel::ProcessModel(
    const TimeVal& duration,
    const Id<Process::ProcessModel>& id,
    QString name,
    QObject* parent)
    : Process::ProcessModel{duration, id, name, parent}
    , outlet{Process::make_value_outlet(Id<Process::Port>(0), this)}
{
  printf("I'm in ShapeModel \n");
  //init();
}

ProcessModel::~ProcessModel() {}

/*
void ProcessModel::init()
{
  outlet->setCustomData("Out");
  m_outlets.push_back(outlet.get());
  connect(
      outlet.get(),
      &Process::Port::addressChanged,
      this,
      [=](const State::AddressAccessor& arg) {
        addressChanged(arg);
        prettyNameChanged();
        unitChanged(arg.qualifiers.get().unit);
      });
}
*/


void ProcessModel::setDurationAndScale(const TimeVal& newDuration) noexcept
{
  // We only need to change the duration.
  setDuration(newDuration);
}

void ProcessModel::setDurationAndGrow(const TimeVal& newDuration) noexcept
{
  setDuration(newDuration);
}

void ProcessModel::setDurationAndShrink(const TimeVal& newDuration) noexcept
{
  setDuration(newDuration);
}

TimeVal ProcessModel::contentDuration() const noexcept
{
  return duration();
}

::State::AddressAccessor ProcessModel::address() const
{
  return outlet->address();
}

void ProcessModel::setAddress(const ::State::AddressAccessor& arg)
{
  outlet->setAddress(arg);
}

State::Unit ProcessModel::unit() const
{
  return outlet->address().qualifiers.get().unit;
}

void ProcessModel::setUnit(const State::Unit& u)
{
  if (u != unit())
  {
    auto addr = outlet->address();
    addr.qualifiers.get().unit = u;
    outlet->setAddress(addr);
    prettyNameChanged();
    unitChanged(u);
  }
}
}

template <>
void DataStreamReader::read(const Shapes::ProcessModel& autom)
{
  m_stream << *autom.outlet << autom.m_spline << autom.m_tween;

  insertDelimiter();
}
template <>
void DataStreamWriter::write(Shapes::ProcessModel& autom)
{
  autom.outlet = Process::load_value_outlet(*this, &autom);
  m_stream >> autom.m_spline >> autom.m_tween;

  checkDelimiter();
}

template <>
void JSONObjectReader::read(const Shapes::ProcessModel& autom)
{
  obj["Outlet"] = toJsonObject(*autom.outlet);
  JSONValueReader v{};
  v.readFrom(autom.m_spline);
  obj["Shape"] = v.val;
  obj["Tween"] = autom.tween();
}

template <>
void JSONObjectWriter::write(Shapes::ProcessModel& autom)
{
  JSONObjectWriter writer{obj["Outlet"].toObject()};
  autom.outlet = Process::load_value_outlet(writer, &autom);

  autom.setTween(obj["Tween"].toBool());
  JSONValueWriter v{};
  v.val = obj["Shape"];
  v.writeTo(autom.m_spline);
}
