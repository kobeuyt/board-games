cmake_minimum_required(VERSION 3.0.0)
project(TicTacToe VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories($PROJECT_SOURCE_DIR/src $PROJECT_SOURCE_DIR/include)

file(GLOB SOURCE "${PROJECT_SOURCE_DIR}/include/*.h" "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(TicTacToe ${SOURCE})