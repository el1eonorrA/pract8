cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

option(USE_STATIC_LIB "Use static library" ON)

if (USE_STATIC_LIB)
    add_library(GameLogic STATIC lib/GameLogic.cpp)
else()
    add_library(GameLogic SHARED lib/GameLogic.cpp)
endif()

add_executable(TicTacToe src/main.cpp)
target_include_directories(TicTacToe PRIVATE lib)
target_link_libraries(TicTacToe PRIVATE GameLogic)