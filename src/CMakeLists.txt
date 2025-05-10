# Библиотека логики игры
file(GLOB SOURCES "*.cpp")
add_library(GameLogic ${SOURCES})
target_include_directories(GameLogic PUBLIC ${CMAKE_SOURCE_DIR}/include)
