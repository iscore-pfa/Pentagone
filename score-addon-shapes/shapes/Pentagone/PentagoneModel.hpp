#pragma once
#include <shapes/Pentagone/PentagoneMetadata.hpp>
#include <shapes/ShapeModel.hpp>
namespace Pentagone
{
class ProcessModel
    : public Shapes::ProcessModel
{
  SCORE_SERIALIZE_FRIENDS
  PROCESS_METADATA_IMPL(Pentagone::ProcessModel)

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
