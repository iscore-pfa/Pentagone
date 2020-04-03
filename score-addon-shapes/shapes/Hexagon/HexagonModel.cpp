// This is an open source non-commercial project. Dear PVS-Studio, please check
// it. PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <Process/Dataflow/Port.hpp>

#include <ossia/editor/state/destination_qualifiers.hpp>

#include <math.h>
#include <shapes/Hexagon/HexagonModel.hpp>
#include <shapes/Hexagon/HexagonPresenter.hpp>
#include <wobjectimpl.h>

W_OBJECT_IMPL(Hexagon::ProcessModel)
#define PI 3.14159265359
namespace Hexagon
{
ProcessModel::ProcessModel(
    const TimeVal& duration,
    const Id<Process::ProcessModel>& id,
    QObject* parent)
    : Shapes::ProcessModel{duration,
                            id,
                            Metadata<ObjectKey_k, ProcessModel>::get(),
                            parent}
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
  metadata().setInstanceName(*this);
}

  ProcessModel::~ProcessModel()
  {

  }
  }

  template <>
  void DataStreamReader::read(const Hexagon::ProcessModel& autom)
  {
    read((Shapes::ProcessModel&)autom);
  }

  template <>
  void DataStreamWriter::write(Hexagon::ProcessModel& autom)
  {
    write((Shapes::ProcessModel&)autom);
  }

  template <>
  void JSONObjectReader::read(const Hexagon::ProcessModel& autom)
  {
    read((Shapes::ProcessModel&)autom);
  }

  template <>
  void JSONObjectWriter::write(Hexagon::ProcessModel& autom)
  {
    write((Shapes::ProcessModel&)autom);
  }
