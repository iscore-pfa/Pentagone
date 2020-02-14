project(score_plugin_automation LANGUAGES CXX)

score_common_setup()

# Packages
find_package(Qt5 5.3 REQUIRED COMPONENTS Core Widgets)

# Files & main target
set(HDRS
  "${CMAKE_CURRENT_SOURCE_DIR}/Automation/AutomationColors.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Automation/AutomationModel.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Automation/AutomationPresenter.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Automation/AutomationProcessMetadata.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Automation/AutomationView.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Automation/AutomationExecution.hpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/Color/GradientModel.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Color/GradientPresenter.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Color/GradientView.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Color/GradientMetadata.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Color/GradientExecution.hpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/Spline/SplineModel.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Spline/SplinePresenter.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Spline/SplineView.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Spline/SplineMetadata.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Spline/SplineExecution.hpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/Polygon/PolygonModel.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Polygon/PolygonPresenter.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Polygon/PolygonView.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Polygon/PolygonMetadata.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Polygon/PolygonExecution.hpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/Pentagone/PentagoneModel.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Pentagone/PentagonePresenter.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Pentagone/PentagoneView.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Pentagone/PentagoneMetadata.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Pentagone/PentagoneExecution.hpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/Hexagon/HexagonModel.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Hexagon/HexagonPresenter.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Hexagon/HexagonView.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Hexagon/HexagonMetadata.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Hexagon/HexagonExecution.hpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/Square/SquareModel.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Square/SquarePresenter.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Square/SquareView.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Square/SquareMetadata.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Square/SquareExecution.hpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/Circle/CircleModel.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Circle/CirclePresenter.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Circle/CircleView.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Circle/CircleMetadata.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Circle/CircleExecution.hpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/Infinite/InfiniteModel.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Infinite/InfinitePresenter.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Infinite/InfiniteView.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Infinite/InfiniteMetadata.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Infinite/InfiniteExecution.hpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/Heart/HeartModel.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Heart/HeartPresenter.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Heart/HeartView.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Heart/HeartMetadata.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Heart/HeartExecution.hpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/Rectangle/RectangleModel.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Rectangle/RectanglePresenter.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Rectangle/RectangleView.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Rectangle/RectangleMetadata.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Rectangle/RectangleExecution.hpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/Triangle/TriangleModel.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Triangle/TrianglePresenter.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Triangle/TriangleView.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Triangle/TriangleMetadata.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Triangle/TriangleExecution.hpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/Metronome/MetronomeColors.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Metronome/MetronomeModel.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Metronome/MetronomePresenter.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Metronome/MetronomeView.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Metronome/MetronomeProcessMetadata.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Metronome/MetronomeExecution.hpp"

  "${CMAKE_CURRENT_SOURCE_DIR}/Automation/Commands/AutomationCommandFactory.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Automation/Commands/ChangeAddress.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Automation/Commands/InitAutomation.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Automation/Commands/SetAutomationMax.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Automation/Inspector/AutomationInspectorFactory.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Automation/Inspector/AutomationInspectorWidget.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Automation/Inspector/AutomationStateInspectorFactory.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Automation/Inspector/AutomationStateInspector.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Automation/Inspector/CurvePointInspectorFactory.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Automation/Inspector/CurvePointInspectorWidget.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Automation/State/AutomationState.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/score_plugin_automation.hpp"
)
set(SRCS
"${CMAKE_CURRENT_SOURCE_DIR}/Automation/AutomationSerialization.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/Automation/AutomationView.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Automation/AutomationModel.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Automation/AutomationExecution.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/Color/GradientModel.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Color/GradientPresenter.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Color/GradientView.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Color/GradientExecution.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/Spline/SplineModel.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Spline/SplinePresenter.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Spline/SplineView.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Spline/SplineExecution.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/Polygon/PolygonModel.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Polygon/PolygonPresenter.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Polygon/PolygonView.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Polygon/PolygonExecution.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/Pentagone/PentagoneModel.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Pentagone/PentagonePresenter.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Pentagone/PentagoneView.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Pentagone/PentagoneExecution.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/Hexagon/HexagonModel.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Hexagon/HexagonPresenter.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Hexagon/HexagonView.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Hexagon/HexagonExecution.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/Square/SquareModel.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Square/SquarePresenter.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Square/SquareView.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Square/SquareExecution.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/Circle/CircleModel.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Circle/CirclePresenter.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Circle/CircleView.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Circle/CircleExecution.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/Infinite/InfiniteModel.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Infinite/InfinitePresenter.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Infinite/InfiniteView.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Infinite/InfiniteExecution.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/Heart/HeartModel.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Heart/HeartPresenter.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Heart/HeartView.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Heart/HeartExecution.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/Rectangle/RectangleModel.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Rectangle/RectanglePresenter.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Rectangle/RectangleView.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Rectangle/RectangleExecution.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/Triangle/TriangleModel.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Triangle/TrianglePresenter.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Triangle/TriangleView.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Triangle/TriangleExecution.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/Metronome/MetronomeColors.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Metronome/MetronomeModel.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Metronome/MetronomeView.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Metronome/MetronomeExecution.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/Automation/Commands/InitAutomation.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Automation/Commands/ChangeAddress.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Automation/Commands/AutomationCommandFactory.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/Automation/State/AutomationState.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/Automation/Inspector/AutomationStateInspector.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Automation/Inspector/AutomationStateInspectorFactory.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Automation/Inspector/AutomationInspectorWidget.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Automation/Inspector/CurvePointInspectorWidget.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Automation/Inspector/CurvePointInspectorFactory.cpp"

"${CMAKE_CURRENT_SOURCE_DIR}/Automation/AutomationColors.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/score_plugin_automation.cpp"
)

add_library(${PROJECT_NAME} ${SRCS} ${HDRS})

score_generate_command_list_file(${PROJECT_NAME} "${HDRS}")

target_link_libraries(${PROJECT_NAME}
  PUBLIC Qt5::Core Qt5::Widgets
            score_lib_base score_lib_device
            score_plugin_deviceexplorer score_lib_process
            score_lib_state score_plugin_curve score_lib_inspector
            )

setup_score_plugin(${PROJECT_NAME})
