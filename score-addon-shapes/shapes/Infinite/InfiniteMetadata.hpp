#pragma once
#include <Process/ProcessMetadata.hpp>

#include <score/plugins/UuidKey.hpp>

#include <QString>

#include <score_plugin_automation_export.h>

namespace Infinite
{
class ProcessModel;
}

PROCESS_METADATA(
    ,
    Infinite::ProcessModel,
    "44a5e912-ea55-48cb-87b8-5efe02b487d8",
    "Infinite",
    "Infinite",//nom qui apparaît
    Process::ProcessCategory::Automation,
    "Automations",
    "Automation following a 2D curve",
    "ossia score",
    (QStringList{"Curve", "Automation", "2D"}),
    {},
    {std::vector<Process::PortType>{Process::PortType::Message}},
    Process::ProcessFlags::SupportsTemporal);
