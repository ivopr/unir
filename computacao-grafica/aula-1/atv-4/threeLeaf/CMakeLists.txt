cmake_minimum_required(VERSION 3.19)
project(threeleaf)

set(CMAKE_CXX_STANDARD 14)

add_executable(threeleaf main.cpp)

target_link_libraries(threeleaf opengl32 glu32 freeglut)