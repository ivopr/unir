cmake_minimum_required(VERSION 3.21)
project(atv_30_12_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(atv_30_12_2 main.cpp)

target_link_libraries(atv_30_12_2 opengl32 glu32 freeglut)