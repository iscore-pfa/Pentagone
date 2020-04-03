#pragma once
#include <Process/ProcessMetadata.hpp>

#include <score/plugins/UuidKey.hpp>

#include <QString>

#include <score_plugin_automation_export.h>

namespace Pentagone
{
class ProcessModel;
}

PROCESS_METADATA(
    ,
    Pentagone::ProcessModel,
    "fe635d49-cdb9-471c-88b2-80d4d45712f9",
    "Pentagone",
    "Pentagone",//nom qui apparaît
    Process::ProcessCategory::Automation,
    "Automations",
    "Automation following a 2D curve",
    "ossia score",
    (QStringList{"Curve", "Automation", "2D"}),
    {},
    {std::vector<Process::PortType>{Process::PortType::Message}},
    Process::ProcessFlags::SupportsTemporal);
