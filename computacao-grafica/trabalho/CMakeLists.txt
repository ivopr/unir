cmake_minimum_required(VERSION 3.21)
project(trabalho)

set(CMAKE_CXX_STANDARD 14)
find_package(assimp CONFIG REQUIRED)
add_executable(trabalho main.cpp)

target_link_libraries(main PRIVATE assimp::assimp)
target_link_libraries(trabalho opengl32 glu32 freeglut)