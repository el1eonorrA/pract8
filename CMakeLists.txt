cmake_minimum_required(VERSION 3.10)
project(TicTacToe)


option(BUILD_SHARED_LIBS "Build shared libraries instead of static ones" OFF)


include_directories(include)


add_subdirectory(src)
add_subdirectory(app)
