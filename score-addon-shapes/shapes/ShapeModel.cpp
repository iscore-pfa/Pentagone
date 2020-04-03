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
  QString circle = "Circle";
  QString heart = "Heart";
  QString hexagon = "Hexagon";
  QString infinite = "Infinite";
  QString pentagone = "Pentagone";
  QString polygon = "Polygon";
  QString rectangle = "Rectangle";
  QString square = "Square";
  if (QString::compare(name,circle) == 0)
  {
    m_spline.points.push_back({0.5, 0.}); // Point 0
    m_spline.points.push_back({1, 0.});
    m_spline.points.push_back({1, 1}); // Point 2
    m_spline.points.push_back({0.5, 1});
    m_spline.points.push_back({0, 1});
    m_spline.points.push_back({0.0, 0.0});
    m_spline.points.push_back({0.5, 0.});
  }
  if (QString::compare(name,heart) == 0)
  {
    m_spline.points.push_back({0.5, 0.});
    m_spline.points.push_back({1, 0.75});
    m_spline.points.push_back({0.75, 1}); // 2 : Point to handle
    m_spline.points.push_back({0.5, 0.75}); // 3
    m_spline.points.push_back({0.5, 0.75}); // 4
    m_spline.points.push_back({0.25, 1}); // 5
    m_spline.points.push_back({0, 0.75}); // 6
    m_spline.points.push_back({0.5, 0}); // 7
  }
  if (QString::compare(name,hexagon) == 0)
  {
      double xCenter = 0.5;
      double yCenter = 0.5;
      double longueur = 0.5;
      double angle = 0;
      double anglefixe = (2*PI)/6;
      //"p2" 2->4
      m_spline.points.push_back({xCenter+ cos(angle+4*anglefixe)*longueur,yCenter+ sin(angle+4*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+4*anglefixe)*longueur,yCenter+ sin(angle+4*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+4*anglefixe)*longueur,yCenter+ sin(angle+4*anglefixe)*longueur});
      //"p3" 5->7
      m_spline.points.push_back({xCenter+ cos(angle+5*anglefixe)*longueur,yCenter+ sin(angle+5*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+5*anglefixe)*longueur,yCenter+ sin(angle+5*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+5*anglefixe)*longueur,yCenter+ sin(angle+5*anglefixe)*longueur});

      m_spline.points.push_back({xCenter+ cos(angle+6*anglefixe)*longueur,yCenter+ sin(angle+6*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+6*anglefixe)*longueur,yCenter+ sin(angle+6*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+6*anglefixe)*longueur,yCenter+ sin(angle+6*anglefixe)*longueur});
      //"p4" 8->10
      m_spline.points.push_back({xCenter+ cos(angle+anglefixe)*longueur,yCenter+ sin(angle+anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+anglefixe)*longueur,yCenter+ sin(angle+anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+anglefixe)*longueur,yCenter+ sin(angle+anglefixe)*longueur});
      //"p5" 11->13
      m_spline.points.push_back({xCenter+ cos(angle+2*anglefixe)*longueur,yCenter+ sin(angle+2*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+2*anglefixe)*longueur,yCenter+ sin(angle+2*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+2*anglefixe)*longueur,yCenter+ sin(angle+2*anglefixe)*longueur});
      //"p6" 14->16
      m_spline.points.push_back({xCenter+ cos(angle+3*anglefixe)*longueur,yCenter+ sin(angle+3*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+3*anglefixe)*longueur,yCenter+ sin(angle+3*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+3*anglefixe)*longueur,yCenter+ sin(angle+3*anglefixe)*longueur});
      //"p7" 17->19
      m_spline.points.push_back({xCenter+ cos(angle+4*anglefixe)*longueur,yCenter+ sin(angle+4*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+4*anglefixe)*longueur,yCenter+ sin(angle+4*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+4*anglefixe)*longueur,yCenter+ sin(angle+4*anglefixe)*longueur});
  }
  if (QString::compare(name,infinite) == 0)
  {
      m_spline.points.push_back({0.5, 0.5}); // 0
      m_spline.points.push_back({0.75, 0.25}); // 1
      m_spline.points.push_back({1, 0.5}); // 2
      m_spline.points.push_back({0.75, 0.75}); // 3 -- Point to handle
      m_spline.points.push_back({0.5, 0.5}); // 4
      m_spline.points.push_back({0.25, 0.25}); // 5
      m_spline.points.push_back({0, 0.5}); // 6
      m_spline.points.push_back({0.25, 0.75}); // 7
      m_spline.points.push_back({0.5, 0.5}); // 8
  }
  if (QString::compare(name,pentagone) == 0)
  {
      double xCenter = 0.5;
      double yCenter = 0.5;
      double longueur = 0.5;
      double angle = 0;
      double anglefixe = (2*M_PI)/5;
    //"p2" 2->4
      m_spline.points.push_back({xCenter+ cos(angle+4*anglefixe)*longueur,yCenter+ sin(angle+4*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+4*anglefixe)*longueur,yCenter+ sin(angle+4*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+4*anglefixe)*longueur,yCenter+ sin(angle+4*anglefixe)*longueur});
    //"p3" 5->7
      m_spline.points.push_back({xCenter+ cos(angle+5*anglefixe)*longueur,yCenter+ sin(angle+5*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+5*anglefixe)*longueur,yCenter+ sin(angle+5*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+5*anglefixe)*longueur,yCenter+ sin(angle+5*anglefixe)*longueur});
    //"p4" 8->10
      m_spline.points.push_back({xCenter+ cos(angle+anglefixe)*longueur,yCenter+ sin(angle+anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+anglefixe)*longueur,yCenter+ sin(angle+anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+anglefixe)*longueur,yCenter+ sin(angle+anglefixe)*longueur});
    //"p5" 11->13
      m_spline.points.push_back({xCenter+ cos(angle+2*anglefixe)*longueur,yCenter+ sin(angle+2*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+2*anglefixe)*longueur,yCenter+ sin(angle+2*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+2*anglefixe)*longueur,yCenter+ sin(angle+2*anglefixe)*longueur});
    //"p6" 14->16
      m_spline.points.push_back({xCenter+ cos(angle+3*anglefixe)*longueur,yCenter+ sin(angle+3*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+3*anglefixe)*longueur,yCenter+ sin(angle+3*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+3*anglefixe)*longueur,yCenter+ sin(angle+3*anglefixe)*longueur});
    //"p7" 17->19
      m_spline.points.push_back({xCenter+ cos(angle+4*anglefixe)*longueur,yCenter+ sin(angle+4*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+4*anglefixe)*longueur,yCenter+ sin(angle+4*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+4*anglefixe)*longueur,yCenter+ sin(angle+4*anglefixe)*longueur});
  }
  if (QString::compare(name,polygon) == 0)
  {
    m_spline.points.push_back({0.4, 0.075});
    m_spline.points.push_back({0.4, 0.075});
    m_spline.points.push_back({0.4, 0.075});
    m_spline.points.push_back({0.45, 0.24});
    m_spline.points.push_back({0.45, 0.24});
    m_spline.points.push_back({0.45, 0.24});
    m_spline.points.push_back({0.5, 0.5});
    m_spline.points.push_back({0.5, 0.5});
    m_spline.points.push_back({0.5, 0.5});

  }
  if (QString::compare(name,rectangle) == 0)
  {
    double xCenter = 0.5;
    double yCenter = 0.5;
    double longueur = 0.5;
    double angle = 0;
    double anglefixe = (2*M_PI)/4;
  //"p2" 2->4
    m_spline.points.push_back({xCenter+ cos(angle+1*anglefixe)*longueur,yCenter+ sin(angle+1*anglefixe)*longueur});
    m_spline.points.push_back({xCenter+ cos(angle+1*anglefixe)*longueur,yCenter+ sin(angle+1*anglefixe)*longueur});
    m_spline.points.push_back({xCenter+ cos(angle+1*anglefixe)*longueur,yCenter+ sin(angle+1*anglefixe)*longueur});
  //"p3" 5->7
    m_spline.points.push_back({xCenter+ cos(angle+2*anglefixe)*longueur,yCenter+ sin(angle+2*anglefixe)*longueur});
    m_spline.points.push_back({xCenter+ cos(angle+2*anglefixe)*longueur,yCenter+ sin(angle+2*anglefixe)*longueur});
    m_spline.points.push_back({xCenter+ cos(angle+2*anglefixe)*longueur,yCenter+ sin(angle+2*anglefixe)*longueur});
  //"p4" 8->10
    m_spline.points.push_back({xCenter+ cos(angle+3*anglefixe)*longueur,yCenter+ sin(angle+3*anglefixe)*longueur});
    m_spline.points.push_back({xCenter+ cos(angle+3*anglefixe)*longueur,yCenter+ sin(angle+3*anglefixe)*longueur});
    m_spline.points.push_back({xCenter+ cos(angle+3*anglefixe)*longueur,yCenter+ sin(angle+3*anglefixe)*longueur});
  //"p5" 11->13
    m_spline.points.push_back({xCenter+ cos(angle+4*anglefixe)*longueur,yCenter+ sin(angle+4*anglefixe)*longueur});
    m_spline.points.push_back({xCenter+ cos(angle+4*anglefixe)*longueur,yCenter+ sin(angle+4*anglefixe)*longueur});
    m_spline.points.push_back({xCenter+ cos(angle+4*anglefixe)*longueur,yCenter+ sin(angle+4*anglefixe)*longueur});
  //"p6" 14->16
    m_spline.points.push_back({xCenter+ cos(angle+1*anglefixe)*longueur,yCenter+ sin(angle+1*anglefixe)*longueur});
    m_spline.points.push_back({xCenter+ cos(angle+1*anglefixe)*longueur,yCenter+ sin(angle+1*anglefixe)*longueur});
    m_spline.points.push_back({xCenter+ cos(angle+1*anglefixe)*longueur,yCenter+ sin(angle+1*anglefixe)*longueur});

  }
  if (QString::compare(name,square) == 0)
  {

      double xCenter = 0.5;
      double yCenter = 0.5;
      double longueur = 0.5;
      double angle = 0;
      double anglefixe = (2*M_PI)/4;
    //"p2" 2->4
      m_spline.points.push_back({xCenter+ cos(angle+1*anglefixe)*longueur,yCenter+ sin(angle+1*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+1*anglefixe)*longueur,yCenter+ sin(angle+1*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+1*anglefixe)*longueur,yCenter+ sin(angle+1*anglefixe)*longueur});
    //"p3" 5->7
      m_spline.points.push_back({xCenter+ cos(angle+2*anglefixe)*longueur,yCenter+ sin(angle+2*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+2*anglefixe)*longueur,yCenter+ sin(angle+2*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+2*anglefixe)*longueur,yCenter+ sin(angle+2*anglefixe)*longueur});
    //"p4" 8->10
      m_spline.points.push_back({xCenter+ cos(angle+3*anglefixe)*longueur,yCenter+ sin(angle+3*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+3*anglefixe)*longueur,yCenter+ sin(angle+3*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+3*anglefixe)*longueur,yCenter+ sin(angle+3*anglefixe)*longueur});
    //"p5" 11->13
      m_spline.points.push_back({xCenter+ cos(angle+4*anglefixe)*longueur,yCenter+ sin(angle+4*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+4*anglefixe)*longueur,yCenter+ sin(angle+4*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+4*anglefixe)*longueur,yCenter+ sin(angle+4*anglefixe)*longueur});
    //"p6" 14->16
      m_spline.points.push_back({xCenter+ cos(angle+1*anglefixe)*longueur,yCenter+ sin(angle+1*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+1*anglefixe)*longueur,yCenter+ sin(angle+1*anglefixe)*longueur});
      m_spline.points.push_back({xCenter+ cos(angle+1*anglefixe)*longueur,yCenter+ sin(angle+1*anglefixe)*longueur});

  }
  init();
}

ProcessModel::~ProcessModel() {}

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
