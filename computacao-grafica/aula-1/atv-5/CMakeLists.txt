cmake_minimum_required(VERSION 3.19)
project(perspectivecube)

set(CMAKE_CXX_STANDARD 14)

add_executable(perspectivecube main.cpp)

target_link_libraries(perspectivecube opengl32 glu32 freeglut)