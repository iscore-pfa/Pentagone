#pragma once
#include <Process/ProcessMetadata.hpp>

#include <score/plugins/UuidKey.hpp>

#include <QString>

#include <score_plugin_automation_export.h>

namespace Hexagon
{
class ProcessModel;
}

PROCESS_METADATA(
    ,
    Hexagon::ProcessModel,
    "5f71677d-bf61-4190-ae41-4a352ed1b5ed",
    "Hexagon",
    "Hexagon",//nom qui apparaît
    Process::ProcessCategory::Automation,
    "Automations",
    "Automation following a 2D curve",
    "ossia score",
    (QStringList{"Curve", "Automation", "2D"}),
    {},
    {std::vector<Process::PortType>{Process::PortType::Message}},
    Process::ProcessFlags::SupportsTemporal);
