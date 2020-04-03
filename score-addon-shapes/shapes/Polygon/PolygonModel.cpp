// This is an open source non-commercial project. Dear PVS-Studio, please check
// it. PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <Process/Dataflow/Port.hpp>

#include <ossia/editor/state/destination_qualifiers.hpp>

#include <math.h>
#include <shapes/Polygon/PolygonModel.hpp>
#include <shapes/Polygon/PolygonPresenter.hpp>
#include <wobjectimpl.h>
W_OBJECT_IMPL(Polygon::ProcessModel)
namespace Polygon
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
  m_spline.points.push_back({0.4, 0.075});
  m_spline.points.push_back({0.4, 0.075});
  m_spline.points.push_back({0.4, 0.075});
  m_spline.points.push_back({0.45, 0.24});
  m_spline.points.push_back({0.45, 0.24});
  m_spline.points.push_back({0.45, 0.24});
  m_spline.points.push_back({0.5, 0.5});
  m_spline.points.push_back({0.5, 0.5});
  m_spline.points.push_back({0.5, 0.5});
  metadata().setInstanceName(*this);
}

  ProcessModel::~ProcessModel()
  {}
  }

  template <>
  void DataStreamReader::read(const Polygon::ProcessModel& autom)
  {
    read((Shapes::ProcessModel&)autom);
  }

  template <>
  void DataStreamWriter::write(Polygon::ProcessModel& autom)
  {
    write((Shapes::ProcessModel&)autom);
  }

  template <>
  void JSONObjectReader::read(const Polygon::ProcessModel& autom)
  {
    read((Shapes::ProcessModel&)autom);
  }

  template <>
  void JSONObjectWriter::write(Polygon::ProcessModel& autom)
  {
    write((Shapes::ProcessModel&)autom);
  }
