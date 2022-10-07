cmake_minimum_required(VERSION 3.20)
project(atv_16_12)

set(CMAKE_CXX_STANDARD 17)

add_executable(atv_16_12 main.cpp main.cpp)

target_link_libraries(atv_16_12 opengl32 glu32 freeglut)
