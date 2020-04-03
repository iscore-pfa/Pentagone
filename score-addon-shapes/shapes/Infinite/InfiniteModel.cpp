// This is an open source non-commercial project. Dear PVS-Studio, please check
// it. PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <Process/Dataflow/Port.hpp>

#include <ossia/editor/state/destination_qualifiers.hpp>

#include <math.h>
#include <shapes/Infinite/InfiniteModel.hpp>
#include <shapes/Infinite/InfinitePresenter.hpp>
#include <wobjectimpl.h>

W_OBJECT_IMPL(Infinite::ProcessModel)
namespace Infinite
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
  m_spline.points.push_back({0.5, 0.5}); // 0
  m_spline.points.push_back({0.75, 0.25}); // 1
  m_spline.points.push_back({1, 0.5}); // 2
  m_spline.points.push_back({0.75, 0.75}); // 3 -- Point to handle
  m_spline.points.push_back({0.5, 0.5}); // 4
  m_spline.points.push_back({0.25, 0.25}); // 5
  m_spline.points.push_back({0, 0.5}); // 6
  m_spline.points.push_back({0.25, 0.75}); // 7
  m_spline.points.push_back({0.5, 0.5}); // 8
  metadata().setInstanceName(*this);
}

  ProcessModel::~ProcessModel()
  {}
  }

  template <>
  void DataStreamReader::read(const Infinite::ProcessModel& autom)
  {
    read((Shapes::ProcessModel&)autom);
  }

  template <>
  void DataStreamWriter::write(Infinite::ProcessModel& autom)
  {
    write((Shapes::ProcessModel&)autom);
  }

  template <>
  void JSONObjectReader::read(const Infinite::ProcessModel& autom)
  {
    read((Shapes::ProcessModel&)autom);
  }

  template <>
  void JSONObjectWriter::write(Infinite::ProcessModel& autom)
  {
    write((Shapes::ProcessModel&)autom);
  }
