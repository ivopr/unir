cmake_minimum_required(VERSION 3.19)
project(spiral)

set(CMAKE_CXX_STANDARD 14)

add_executable(spiral main.cpp)

target_link_libraries(spiral opengl32 glu32 freeglut)