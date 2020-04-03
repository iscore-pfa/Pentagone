#include "score_addon_shapes.hpp"

#include <score/plugins/FactorySetup.hpp>
#include <Process/GenericProcessFactory.hpp>
#include <Process/Inspector/ProcessInspectorWidgetDelegateFactory.hpp>
#include <Process/Inspector/ProcessInspectorWidgetDelegate.hpp>

#include <shapes/Polygon/PolygonExecution.hpp>
#include <shapes/Polygon/PolygonModel.hpp>
#include <shapes/Polygon/PolygonPresenter.hpp>
#include <shapes/Polygon/PolygonView.hpp>
#include <shapes/Pentagone/PentagoneExecution.hpp>
#include <shapes/Pentagone/PentagoneModel.hpp>
#include <shapes/Pentagone/PentagonePresenter.hpp>
#include <shapes/Pentagone/PentagoneView.hpp>
#include <shapes/Hexagon/HexagonExecution.hpp>
#include <shapes/Hexagon/HexagonModel.hpp>
#include <shapes/Hexagon/HexagonPresenter.hpp>
#include <shapes/Hexagon/HexagonView.hpp>
#include <shapes/Square/SquareExecution.hpp>
#include <shapes/Square/SquareModel.hpp>
#include <shapes/Square/SquarePresenter.hpp>
#include <shapes/Square/SquareView.hpp>
#include <shapes/Circle/CircleModel.hpp>
#include <shapes/Circle/CirclePresenter.hpp>
#include <shapes/Circle/CircleView.hpp>
#include <shapes/Infinite/InfiniteExecution.hpp>
#include <shapes/Infinite/InfiniteModel.hpp>
#include <shapes/Infinite/InfinitePresenter.hpp>
#include <shapes/Infinite/InfiniteView.hpp>
#include <shapes/Heart/HeartExecution.hpp>
#include <shapes/Heart/HeartModel.hpp>
#include <shapes/Heart/HeartPresenter.hpp>
#include <shapes/Heart/HeartView.hpp>
#include <shapes/Rectangle/RectangleExecution.hpp>
#include <shapes/Rectangle/RectangleModel.hpp>
#include <shapes/Rectangle/RectanglePresenter.hpp>
#include <shapes/Rectangle/RectangleView.hpp>
#include <shapes/Triangle/TriangleExecution.hpp>
#include <shapes/Triangle/TriangleModel.hpp>
#include <shapes/Triangle/TrianglePresenter.hpp>
#include <shapes/Triangle/TriangleView.hpp>
#include <shapes/ShapeExecution.hpp>
#include <score_addon_shapes_commands_files.hpp>
#include <Inspector/InspectorWidgetFactoryInterface.hpp>
#include <Process/Inspector/ProcessInspectorWidgetDelegateFactory.hpp>

namespace Polygon
{
using PolygonFactory = Process::ProcessFactory_T<Polygon::ProcessModel>;
using PolygonLayerFactory = Process::
    LayerFactory_T<Polygon::ProcessModel, Polygon::Presenter, Polygon::View>;
}

namespace Pentagone
{
using PentagoneFactory = Process::ProcessFactory_T<Pentagone::ProcessModel>;
using PentagoneLayerFactory = Process::
    LayerFactory_T<Pentagone::ProcessModel, Pentagone::Presenter, Pentagone::View>;
}

namespace Hexagon
{
using HexagonFactory = Process::ProcessFactory_T<Hexagon::ProcessModel>;
using HexagonLayerFactory = Process::
    LayerFactory_T<Hexagon::ProcessModel, Hexagon::Presenter, Hexagon::View>;
}

namespace Square
{
using SquareFactory = Process::ProcessFactory_T<Square::ProcessModel>;
using SquareLayerFactory = Process::
    LayerFactory_T<Square::ProcessModel, Square::Presenter, Square::View>;
}

namespace Circle
{
using CircleFactory = Process::ProcessFactory_T<Circle::ProcessModel>;
using CircleLayerFactory = Process::
    LayerFactory_T<Circle::ProcessModel, Circle::Presenter, Circle::View>;
}

namespace Infinite
{
using InfiniteFactory = Process::ProcessFactory_T<Infinite::ProcessModel>;
using InfiniteLayerFactory = Process::
    LayerFactory_T<Infinite::ProcessModel, Infinite::Presenter, Infinite::View>;
}

namespace Heart
{
using HeartFactory = Process::ProcessFactory_T<Heart::ProcessModel>;
using HeartLayerFactory = Process::
    LayerFactory_T<Heart::ProcessModel, Heart::Presenter, Heart::View>;
}

namespace Rectangle
{
using RectangleFactory = Process::ProcessFactory_T<Rectangle::ProcessModel>;
using RectangleLayerFactory = Process::
    LayerFactory_T<Rectangle::ProcessModel, Rectangle::Presenter, Rectangle::View>;
}

namespace Triangle
{
using TriangleFactory = Process::ProcessFactory_T<Triangle::ProcessModel>;
using TriangleLayerFactory = Process::
    LayerFactory_T<Triangle::ProcessModel, Triangle::Presenter, Triangle::View>;
}
score_addon_shapes::score_addon_shapes()
{
}

score_addon_shapes::~score_addon_shapes()
{
}

std::vector<std::unique_ptr<score::InterfaceBase>>
score_addon_shapes::factories(
    const score::ApplicationContext& ctx, const score::InterfaceKey& key) const
{
  return instantiate_factories<
      score::ApplicationContext,
      FW<Process::ProcessModelFactory,
         Polygon::PolygonFactory,
         Pentagone::PentagoneFactory,
         Hexagon::HexagonFactory,
         Square::SquareFactory,
         Circle::CircleFactory,
         Infinite::InfiniteFactory,
         Heart::HeartFactory,
         Rectangle::RectangleFactory,
         Triangle::TriangleFactory>,

      FW<Process::LayerFactory,
         Polygon::PolygonLayerFactory,
         Pentagone::PentagoneLayerFactory,
         Hexagon::HexagonLayerFactory,
         Square::SquareLayerFactory,
         Circle::CircleLayerFactory,
         Infinite::InfiniteLayerFactory,
         Heart::HeartLayerFactory,
         Rectangle::RectangleLayerFactory,
         Triangle::TriangleLayerFactory>,

      FW<Execution::ProcessComponentFactory,
         Shapes::ExecutorFactory
      >
      >(ctx, key);
}

std::pair<const CommandGroupKey, CommandGeneratorMap>
score_addon_shapes::make_commands()
{
  using namespace Circle;
  using namespace Polygon;
  using namespace Pentagone;
  using namespace Hexagon;
  using namespace Square;
  using namespace Circle;
  using namespace Infinite;
  using namespace Heart;
  using namespace Rectangle;
  using namespace Triangle;
  std::pair<const CommandGroupKey, CommandGeneratorMap> cmds{
      Shapes::CommandFactoryName(), CommandGeneratorMap{}};

  ossia::for_each_type<
#include <score_addon_shapes_commands.hpp>
      >(score::commands::FactoryInserter{cmds.second});

  return cmds;
}

#include <score/plugins/PluginInstances.hpp>
SCORE_EXPORT_PLUGIN(score_addon_shapes)
