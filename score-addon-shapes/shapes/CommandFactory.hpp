#pragma once
#include <score/command/Command.hpp>
namespace Shapes
{
inline const CommandGroupKey& CommandFactoryName()
{
  static const CommandGroupKey key{"Midi"};
  return key;
}
}
