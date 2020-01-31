#pragma once
#include <Automation/AutomationModel.hpp>
#include <Automation/Inspector/AutomationInspectorWidget.hpp>
#include <Process/Inspector/ProcessInspectorWidgetDelegateFactory.hpp>

namespace Automation
{
class InspectorFactory final
    : public Process::
          InspectorWidgetDelegateFactory_T<ProcessModel, InspectorWidget>
{
  SCORE_CONCRETE("2c5410ba-d3df-45b8-8444-6d8578b4e1a8")
};
}

namespace Gradient
{
class InspectorFactory final
    : public Process::
          InspectorWidgetDelegateFactory_T<ProcessModel, InspectorWidget>
{
  SCORE_CONCRETE("7d61cbcb-7980-4d50-86c9-3d54a0299fc5")
};
}

namespace Spline
{
class InspectorFactory final
    : public Process::
          InspectorWidgetDelegateFactory_T<ProcessModel, InspectorWidget>
{
  SCORE_CONCRETE("94c5afc5-c8c3-44e2-b8b4-6e53d8518677")
};
}

namespace Polygon
{
class InspectorFactory final
    : public Process::
          InspectorWidgetDelegateFactory_T<ProcessModel, InspectorWidget>
{
  SCORE_CONCRETE("f83e7e67-7b0d-48b2-8584-d17349cdb0d3")
};
}

namespace Pentagone
{
class InspectorFactory final
    : public Process::
          InspectorWidgetDelegateFactory_T<ProcessModel, InspectorWidget>
{
  SCORE_CONCRETE("fe635d49-cdb9-471c-88b2-80d4d45712f9")
};
}

namespace Hexagon
{
class InspectorFactory final
    : public Process::
          InspectorWidgetDelegateFactory_T<ProcessModel, InspectorWidget>
{
  SCORE_CONCRETE("5f71677d-bf61-4190-ae41-4a352ed1b5ed")
};
}

namespace Square
{
class InspectorFactory final
    : public Process::
          InspectorWidgetDelegateFactory_T<ProcessModel, InspectorWidget>
{
  SCORE_CONCRETE("90ae5381-0dcb-41f9-a630-b260c67d82cc")
};
}

namespace Rectangle
{
class InspectorFactory final
    : public Process::
          InspectorWidgetDelegateFactory_T<ProcessModel, InspectorWidget>
{
  SCORE_CONCRETE("c393c4d4-d916-484f-aa4c-ab7dfd1e83a3")
};
}


namespace Triangle
{
class InspectorFactory final
    : public Process::
          InspectorWidgetDelegateFactory_T<ProcessModel, InspectorWidget>
{
  SCORE_CONCRETE("a3ac72db-6c44-4508-a4ac-4da6f8b0cfa3")
};
}

namespace Metronome
{
class InspectorFactory final
    : public Process::
          InspectorWidgetDelegateFactory_T<ProcessModel, InspectorWidget>
{
  SCORE_CONCRETE("4c7c9f7d-50ff-4443-ae85-d2c340e17c44")
};
}
