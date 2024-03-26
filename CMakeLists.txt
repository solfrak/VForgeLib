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
        include/Camera.h
        include/Components/MeshRenderer.h
        include/Object.h
        include/Mesh.h
        src/Mesh.h.cpp
        src/Object.cpp
        include/Application.h
        src/Application.cpp
        include/Events/Event.h
        include/Events/KeyEvent.h
)

target_link_libraries(VForgeLib glfw assimp)
