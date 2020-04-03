#pragma once
#include <shapes/Rectangle/RectangleMetadata.hpp>
#include <shapes/ShapeModel.hpp>
namespace Rectangle
{
class ProcessModel
    : public Shapes::ProcessModel
{
  SCORE_SERIALIZE_FRIENDS
  PROCESS_METADATA_IMPL(Rectangle::ProcessModel)

  W_OBJECT(ProcessModel)

public:
  ProcessModel(
      const TimeVal& duration,
      const Id<Process::ProcessModel>& id,
      QObject* parent);

  using Shapes::ProcessModel::ProcessModel;
  ~ProcessModel() override;
};
}
