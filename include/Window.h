//
// Created by samuel on 19/03/24.
//

#ifndef VFORGEMAIN_WINDOW_H
#define VFORGEMAIN_WINDOW_H

#include "memory"
#include "GLFW/glfw3.h"
namespace vforge
{
    class Window
    {
    private:
        int width_, height_;
        std::unique_ptr<GLFWwindow*> window_;

    public:
        Window(int width, int height);

        typedef void (*UpdateCallback)();
        void Run(UpdateCallback callback);

        GLFWwindow* Get()
        {
            return window_.operator*();
        }

    };

}

#endif //VFORGEMAIN_WINDOW_H
