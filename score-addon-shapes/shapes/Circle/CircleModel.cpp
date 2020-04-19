// This is an open source non-commercial project. Dear PVS-Studio, please check
// it. PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <Process/Dataflow/Port.hpp>

#include <ossia/editor/state/destination_qualifiers.hpp>

#include <shapes/Circle/CircleModel.hpp>
#include <shapes/Circle/CirclePresenter.hpp>
#include <wobjectimpl.h>

W_OBJECT_IMPL(Circle::ProcessModel)
namespace Circle
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
  m_spline.points.push_back({0.5, 0.}); // Point 0
  m_spline.points.push_back({1, 0.});
  m_spline.points.push_back({1, 1}); // Point 2
  m_spline.points.push_back({0.5, 1});
  m_spline.points.push_back({0, 1});
  m_spline.points.push_back({0.0, 0.0});
  m_spline.points.push_back({0.5, 0.});

  metadata().setInstanceName(*this);
}

  ProcessModel::~ProcessModel()
  {

  }
  }

  

  template <>
  void DataStreamReader::read(const Circle::ProcessModel& autom)
  {
    read((Shapes::ProcessModel&)autom);
  }

  template <>
  void DataStreamWriter::write(Circle::ProcessModel& autom)
  {
    write((Shapes::ProcessModel&)autom);
  }

  template <>
  void JSONObjectReader::read(const Circle::ProcessModel& autom)
  {
    read((Shapes::ProcessModel&)autom);
  }

  template <>
  void JSONObjectWriter::write(Circle::ProcessModel& autom)
  {
    write((Shapes::ProcessModel&)autom);
  }
