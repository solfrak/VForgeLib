cmake_minimum_required(VERSION 3.28)
project(VForgeLib)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
include_directories(/usr/include/stb)

add_library(VForgeLib STATIC
        include/glad/glad.h
        src/glad/glad.cpp
        src/Window.cpp
        include/Window.h
        src/Window.cpp
        src/Shader.cpp
        include/Shader.h
        include/Texture.h
        src/Texture.cpp
        include/Components/Transform.h
        include/Components/Texture2D.h
        include/Components/IComponent.h
        include/Camera.h)

target_link_libraries(VForgeLib glfw)
