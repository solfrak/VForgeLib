//
// Created by samuel on 19/03/24.
//

#ifndef VFORGEMAIN_WINDOW_H
#define VFORGEMAIN_WINDOW_H

#include "memory"
#include "GLFW/glfw3.h"
#include <vector>
#include "Events/KeyEvent.h"
namespace vforge
{
    typedef void (*KeyboardCallback)(KeyEvent *event);
    class Window
    {
    private:
        int width_, height_;
        std::unique_ptr<GLFWwindow*> window_;
        std::vector<KeyboardCallback> keyboardCallback;
        static void WindowKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);




    public:
        Window(int width, int height, const char* name);

        typedef void (*UpdateCallback)();
        void Run(UpdateCallback callback);

        GLFWwindow* Get()
        {
            return window_.operator*();
        }


        void SetKeyboardCallback(KeyboardCallback callback);

    };

}

#endif //VFORGEMAIN_WINDOW_H
