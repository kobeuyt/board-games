cmake_minimum_required(VERSION 3.0.0)
project(TicTacToe VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

add_executable(TicTacToe ${SRC_DIR}/TicTacToe.cpp)

target_include_directories(TicTacToe PUBLIC "${INCLUDE_DIR}")

add_library(Board ${SRC_DIR}/Board.cpp)

target_include_directories(Board PUBLIC "${INCLUDE_DIR}")

target_link_libraries(TicTacToe PUBLIC Board)