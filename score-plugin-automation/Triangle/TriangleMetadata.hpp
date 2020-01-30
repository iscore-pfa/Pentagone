#pragma once
#include <Process/ProcessMetadata.hpp>

#include <score/plugins/UuidKey.hpp>

#include <QString>

#include <score_plugin_automation_export.h>

namespace Triangle
{
class ProcessModel;
}

PROCESS_METADATA(
    SCORE_PLUGIN_AUTOMATION_EXPORT,
    Triangle::ProcessModel,
    "a3ac72db-6c44-4508-a4ac-4da6f8b0cfa3",
    "Triangle",
    "Triangle",//nom qui apparaît
    Process::ProcessCategory::Automation,
    "Automations",
    "Automation following a 2D curve",
    "ossia score",
    (QStringList{"Curve", "Automation", "2D"}),
    {},
    {std::vector<Process::PortType>{Process::PortType::Message}},
    Process::ProcessFlags::SupportsTemporal);
