//
// Created by samuel on 25/03/24.
//

#ifndef VFORGEMAIN_APPLICATION_H
#define VFORGEMAIN_APPLICATION_H

#include "Window.h"
#include <memory>
namespace vforge
{
    class Application
    {
    private:
        std::unique_ptr<Window> window;


    public:
        Application(const char* name);
        void Run();
    };
}
#endif //VFORGEMAIN_APPLICATION_H
