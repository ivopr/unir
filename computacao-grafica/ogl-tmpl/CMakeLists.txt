cmake_minimum_required(VERSION 3.19)
project(ogl-tmpl)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/cpp/main.cpp src/cpp/tga_load.cpp includes/tga_load.h)

set(TEXTURE_PATH "../ogl-tmpl/src/textures")

include_directories("includes")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/textures)

add_executable(ogl-tmpl ${SOURCE_FILES})


target_link_libraries(ogl-tmpl -lglut -lGL -lGLU -lGLEW -lglfw)