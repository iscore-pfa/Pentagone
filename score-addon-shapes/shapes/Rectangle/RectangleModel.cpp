// This is an open source non-commercial project. Dear PVS-Studio, please check
// it. PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <Process/Dataflow/Port.hpp>

#include <ossia/editor/state/destination_qualifiers.hpp>

#include <QtMath>
#include <shapes/Rectangle/RectangleModel.hpp>
#include <shapes/Rectangle/RectanglePresenter.hpp>
#include <wobjectimpl.h>

W_OBJECT_IMPL(Rectangle::ProcessModel)
namespace Rectangle
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

  metadata().setInstanceName(*this);
}

  ProcessModel::~ProcessModel()
  {}
  }

  template <>
  void DataStreamReader::read(const Rectangle::ProcessModel& autom)
  {
    read((Shapes::ProcessModel&)autom);
  }

  template <>
  void DataStreamWriter::write(Rectangle::ProcessModel& autom)
  {
    write((Shapes::ProcessModel&)autom);
  }

  template <>
  void JSONObjectReader::read(const Rectangle::ProcessModel& autom)
  {
    read((Shapes::ProcessModel&)autom);
  }

  template <>
  void JSONObjectWriter::write(Rectangle::ProcessModel& autom)
  {
    write((Shapes::ProcessModel&)autom);
  }
