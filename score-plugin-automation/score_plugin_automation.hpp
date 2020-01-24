#pragma once
#include <score/application/ApplicationContext.hpp>
#include <score/command/Command.hpp>
#include <score/command/CommandGeneratorMap.hpp>
#include <score/plugins/Interface.hpp>
#include <score/plugins/qt_interfaces/CommandFactory_QtInterface.hpp>
#include <score/plugins/qt_interfaces/FactoryInterface_QtInterface.hpp>
#include <score/plugins/qt_interfaces/GUIApplicationPlugin_QtInterface.hpp>
#include <score/plugins/qt_interfaces/PluginRequirements_QtInterface.hpp>


#include <verdigris>

#include <utility>
#include <vector>
/**
 * @namespace Automation
 * @brief Namespace related to the Automation process
 *
 * This namespace contains the Automation process, layer, and related edition
 * commands.
 *
 * The Automation is a process that sets the value of a parameter across time.
 * It is related to the \ref ossia::automation process.
 *
 *
 */
class score_plugin_automation final
    : public score::Plugin_QtInterface,
      public score::FactoryInterface_QtInterface,
      public score::CommandFactory_QtInterface
{
  SCORE_PLUGIN_METADATA(1, "255cbc40-c7e9-4bb2-87ea-8ad803fb9f2b")

public:
  score_plugin_automation();
  ~score_plugin_automation() override;

private:
  std::vector<std::unique_ptr<score::InterfaceBase>> factories(
      const score::ApplicationContext& ctx,
      const score::InterfaceKey& factoryName) const override;
  std::pair<const CommandGroupKey, CommandGeneratorMap>
  make_commands() override;
};
