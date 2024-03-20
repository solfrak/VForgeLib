cmake_minimum_required(VERSION 3.28)
project(VForgeLib)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

add_library(VForgeLib STATIC
        include/glad/glad.h
        src/glad/glad.cpp
        src/Window.cpp
        include/Window.h
        src/Window.cpp)

target_link_libraries(VForgeLib glfw)
