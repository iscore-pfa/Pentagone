project(score_addon_shapes LANGUAGES CXX)

# General initialization
score_common_setup()

# Source files
set(HDRS
    shapes/Circle/CircleMetadata.hpp
    shapes/Circle/CircleModel.hpp
    shapes/Circle/CirclePresenter.hpp
    shapes/Circle/CircleView.hpp
    shapes/Heart/HeartMetadata.hpp
    shapes/Heart/HeartModel.hpp
    shapes/Heart/HeartPresenter.hpp
    shapes/Heart/HeartView.hpp
    shapes/Hexagon/HexagonMetadata.hpp
    shapes/Hexagon/HexagonModel.hpp
    shapes/Hexagon/HexagonPresenter.hpp
    shapes/Hexagon/HexagonView.hpp
    shapes/Infinite/InfiniteMetadata.hpp
    shapes/Infinite/InfiniteModel.hpp
    shapes/Infinite/InfinitePresenter.hpp
    shapes/Infinite/InfiniteView.hpp
    shapes/Pentagone/PentagoneMetadata.hpp
    shapes/Pentagone/PentagoneModel.hpp
    shapes/Pentagone/PentagonePresenter.hpp
    shapes/Pentagone/PentagoneView.hpp
    shapes/Polygon/PolygonMetadata.hpp
    shapes/Polygon/PolygonModel.hpp
    shapes/Polygon/PolygonPresenter.hpp
    shapes/Polygon/PolygonView.hpp
    shapes/Rectangle/RectangleMetadata.hpp
    shapes/Rectangle/RectangleModel.hpp
    shapes/Rectangle/RectanglePresenter.hpp
    shapes/Rectangle/RectangleView.hpp
    shapes/Square/SquareMetadata.hpp
    shapes/Square/SquareModel.hpp
    shapes/Square/SquarePresenter.hpp
    shapes/Square/SquareView.hpp
    shapes/Triangle/TriangleMetadata.hpp
    shapes/Triangle/TriangleModel.hpp
    shapes/Triangle/TrianglePresenter.hpp
    shapes/Triangle/TriangleView.hpp

    shapes/CommandFactory.hpp
    shapes/ShapeExecution.hpp

    score_addon_shapes.hpp
)
set(SRCS
    shapes/Circle/CircleModel.cpp
    shapes/Circle/CirclePresenter.cpp
    shapes/Circle/CircleView.cpp
    shapes/Heart/HeartModel.cpp
    shapes/Heart/HeartPresenter.cpp
    shapes/Heart/HeartView.cpp
    shapes/Hexagon/HexagonModel.cpp
    shapes/Hexagon/HexagonPresenter.cpp
    shapes/Hexagon/HexagonView.cpp
    shapes/Infinite/InfiniteModel.cpp
    shapes/Infinite/InfinitePresenter.cpp
    shapes/Infinite/InfiniteView.cpp
    shapes/Pentagone/PentagoneModel.cpp
    shapes/Pentagone/PentagonePresenter.cpp
    shapes/Pentagone/PentagoneView.cpp
    shapes/Polygon/PolygonModel.cpp
    shapes/Polygon/PolygonPresenter.cpp
    shapes/Polygon/PolygonView.cpp
    shapes/Rectangle/RectangleModel.cpp
    shapes/Rectangle/RectanglePresenter.cpp
    shapes/Rectangle/RectangleView.cpp
    shapes/Square/SquareModel.cpp
    shapes/Square/SquarePresenter.cpp
    shapes/Square/SquareView.cpp
    shapes/Triangle/TriangleModel.cpp
    shapes/Triangle/TrianglePresenter.cpp
    shapes/Triangle/TriangleView.cpp

    shapes/ShapeModel.cpp
    shapes/ShapeView.cpp

    score_addon_shapes.cpp
)


# Creation of the library
add_library(${PROJECT_NAME} ${SRCS} ${HDRS})

# Code generation
score_generate_command_list_file(${PROJECT_NAME} "${HDRS}")

# Link
target_link_libraries(${PROJECT_NAME} PUBLIC score_plugin_engine)

# Target-specific options
setup_score_plugin(${PROJECT_NAME})
