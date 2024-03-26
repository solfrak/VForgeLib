//
// Created by samuel on 25/03/24.
//

#ifndef VFORGEMAIN_KEYEVENT_H
#define VFORGEMAIN_KEYEVENT_H

#include "Events/Event.h"

namespace vforge
{
    class KeyEvent : public Event
    {
    public:

        KeyEvent(int keycode) : keycode_(keycode) {}
        int GetKeyCode() { return keycode_; }

    protected:
        int keycode_;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), repeatCount_(repeatCount) {}
        virtual EventType GetEventType() const override { return KeyPressed; }
    private:
        int repeatCount_;
    };
}
#endif //VFORGEMAIN_KEYEVENT_H
