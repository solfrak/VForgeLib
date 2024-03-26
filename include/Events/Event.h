//
// Created by samuel on 25/03/24.
//

#ifndef VFORGEMAIN_EVENT_H
#define VFORGEMAIN_EVENT_H

namespace vforge
{
    enum EventType
    {
        KeyPressed, KeyReleased
    };


    class Event
    {
    public:
        virtual EventType GetEventType() const = 0;
    };
}

#endif //VFORGEMAIN_EVENT_H
