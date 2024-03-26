//
// Created by samuel on 25/03/24.
//
#include "Application.h"
#include <iostream>

namespace vforge
{

    Application::Application(const char *name) {
        window = std::make_unique<Window>(800, 700, name);
        window->SetKeyboardCallback([](KeyEvent *event){
            EventType type = event->GetEventType();
            switch (type) {
                case EventType::KeyPressed:
                    KeyPressedEvent *myEvent = dynamic_cast<KeyPressedEvent*>(event);
                    if(myEvent)
                    {
                        std::cout << myEvent->GetKeyCode() << std::endl;
                    }
                    break;
                case KeyReleased:
                    break;
            }
        });
    }

    void Application::Run() {
        window->Run([](){

        });

    }


}
