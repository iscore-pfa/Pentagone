#pragma once
#include <Process/ProcessMetadata.hpp>

#include <score/plugins/UuidKey.hpp>

#include <QString>

#include <score_plugin_automation_export.h>

namespace Rectangle
{
class ProcessModel;
}

PROCESS_METADATA(
    ,
    Rectangle::ProcessModel,
    "c393c4d4-d916-484f-aa4c-ab7dfd1e83a3",
    "Rectangle",
    "Rectangle",//nom qui apparaît
    Process::ProcessCategory::Automation,
    "Automations",
    "Automation following a 2D curve",
    "ossia score",
    (QStringList{"Curve", "Automation", "2D"}),
    {},
    {std::vector<Process::PortType>{Process::PortType::Message}},
    Process::ProcessFlags::SupportsTemporal);
