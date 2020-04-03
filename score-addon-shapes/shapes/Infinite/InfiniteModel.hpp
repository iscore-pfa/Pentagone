#pragma once
#include <shapes/Infinite/InfiniteMetadata.hpp>
#include <shapes/ShapeModel.hpp>
namespace Infinite
{
class ProcessModel
    : public Shapes::ProcessModel
{
  SCORE_SERIALIZE_FRIENDS
  PROCESS_METADATA_IMPL(Infinite::ProcessModel)

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
