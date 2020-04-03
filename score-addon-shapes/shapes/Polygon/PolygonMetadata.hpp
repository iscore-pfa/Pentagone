#pragma once
#include <Process/ProcessMetadata.hpp>

#include <score/plugins/UuidKey.hpp>

#include <QString>

#include <score_plugin_automation_export.h>

namespace Polygon
{
class ProcessModel;
}

PROCESS_METADATA(
    ,
    Polygon::ProcessModel,
    "f83e7e67-7b0d-48b2-8584-d17349cdb0d3",
    "Polygon",
    "Polygon",
    Process::ProcessCategory::Automation,
    "Automations",
    "Automation following a 2D curve",
    "ossia score",
    (QStringList{"Curve", "Automation", "2D"}),
    {},
    {std::vector<Process::PortType>{Process::PortType::Message}},
    Process::ProcessFlags::SupportsTemporal);
