#pragma once
#include <shapes/Square/SquareMetadata.hpp>
#include <shapes/ShapeModel.hpp>
namespace Square
{
class ProcessModel
    : public Shapes::ProcessModel
{
  SCORE_SERIALIZE_FRIENDS
  PROCESS_METADATA_IMPL(Square::ProcessModel)

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
