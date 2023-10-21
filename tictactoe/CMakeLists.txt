cmake_minimum_required(VERSION 3.5.0)
project(TicTacToe VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

add_executable(TicTacToe ${SRC_DIR}/TicTacToe.cpp ${SRC_DIR}/Board.cpp)

target_include_directories(TicTacToe PUBLIC "${INCLUDE_DIR}")
