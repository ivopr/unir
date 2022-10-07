cmake_minimum_required(VERSION 3.19)
project(cardioid)

set(CMAKE_CXX_STANDARD 14)

add_executable(cardioid main.cpp)

target_link_libraries(cardioid opengl32 glu32 freeglut)