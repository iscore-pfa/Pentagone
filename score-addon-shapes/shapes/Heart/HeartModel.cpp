// This is an open source non-commercial project. Dear PVS-Studio, please check
// it. PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <Process/Dataflow/Port.hpp>

#include <ossia/editor/state/destination_qualifiers.hpp>

#include <math.h>
#include <shapes/Heart/HeartModel.hpp>
#include <shapes/Heart/HeartPresenter.hpp>
#include <wobjectimpl.h>

W_OBJECT_IMPL(Heart::ProcessModel)
namespace Heart
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
  m_spline.points.push_back({0.5, 0.});
  m_spline.points.push_back({1, 0.75});
  m_spline.points.push_back({0.75, 1}); // 2 : Point to handle
  m_spline.points.push_back({0.5, 0.75}); // 3
  m_spline.points.push_back({0.5, 0.75}); // 4
  m_spline.points.push_back({0.25, 1}); // 5
  m_spline.points.push_back({0, 0.75}); // 6
  m_spline.points.push_back({0.5, 0}); // 7
  metadata().setInstanceName(*this);
}

  ProcessModel::~ProcessModel()
  {}
  }

  template <>
  void DataStreamReader::read(const Heart::ProcessModel& autom)
  {
    read((Shapes::ProcessModel&)autom);
  }

  template <>
  void DataStreamWriter::write(Heart::ProcessModel& autom)
  {
    write((Shapes::ProcessModel&)autom);
  }

  template <>
  void JSONObjectReader::read(const Heart::ProcessModel& autom)
  {
    read((Shapes::ProcessModel&)autom);
  }

  template <>
  void JSONObjectWriter::write(Heart::ProcessModel& autom)
  {
    write((Shapes::ProcessModel&)autom);
  }
