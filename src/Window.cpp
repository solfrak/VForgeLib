//
// Created by samuel on 19/03/24.
//

#include "glad/glad.h"
#include "Window.h"

namespace vforge
{

    Window::Window(int width, int height, const char *name) {
        width_ = width;
        height_ = height;

        if(width_ && height_)
        {

        }

        if(!glfwInit())
        {
            //TODO log error failed to init GLFW
        }

        window_ = std::make_unique<GLFWwindow*>(glfwCreateWindow(width, height, name, nullptr, nullptr));

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

        glfwSetWindowUserPointer(*window_, this);
        glfwSetKeyCallback(*window_,Window::WindowKeyCallback);

    }


    void Window::Run(UpdateCallback callback)
    {
        while(!glfwWindowShouldClose(*window_))
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            callback();
            glfwSwapBuffers(*window_);
            glfwPollEvents();
        }
        glfwTerminate();
    }

    void Window::SetKeyboardCallback(KeyboardCallback callback)
    {
        this->keyboardCallback.push_back(callback);
    }

    void Window::WindowKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        Window *window_instance = static_cast<Window*>(glfwGetWindowUserPointer(window));
        for(auto callback : window_instance->keyboardCallback)
        {
            callback(new KeyPressedEvent(key, action));
        }
    }


}


