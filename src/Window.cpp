//
// Created by samuel on 19/03/24.
//

#include "glad/glad.h"
#include "Window.h"

namespace vforge
{

    Window::Window(int width, int height) {
        width_ = width;
        height_ = height;

        if(width_ && height_)
        {

        }

        if(!glfwInit())
        {
            //TODO log error failed to init GLFW
        }

        window_ = std::make_unique<GLFWwindow*>(glfwCreateWindow(width, height, "Hello World", nullptr, nullptr));

        if(*window_ == nullptr)
        {
            glfwTerminate();
            //TODO log error failed to create window
        }

        glfwMakeContextCurrent(*window_);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            //TODO log error failed to load open gl
        }

        glEnable(GL_DEPTH_TEST);
//        glfwSetInputMode(*window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    }


    void Window::Run(UpdateCallback callback) {
        while(!glfwWindowShouldClose(*window_))
        {
            glClear(GL_COLOR_BUFFER_BIT);

            callback();
            glfwSwapBuffers(*window_);
            glfwPollEvents();
        }
        glfwTerminate();
    }
}


