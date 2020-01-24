#pragma once
#include <Process/ProcessMetadata.hpp>

#include <score/plugins/UuidKey.hpp>

#include <QString>

#include <score_plugin_automation_export.h>

namespace Triangle{
class ProcessModel;
}


PROCESS_METADATA(
      SCORE_PLUGIN_AUTOMATION_EXPORT,
      Triangle::ProcessModel, //triangle
      "fe635d49-cdb9-471c-88b2-80d4d45712f9",
      "Spline",
      "triangle",
      Process::ProcessCategory::Automation,
      "Automations",
      "Automation following a 2D triangle",
      "ossia score",
      (QStringList{"Curve", "Automation", "2D"}),
      {},
      {std::vector<Process::PortType>{Process::PortType::Message}},
      Process::ProcessFlags::SupportsTemporal);
