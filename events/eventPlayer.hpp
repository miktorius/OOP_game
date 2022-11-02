#ifndef EVENT_PLAYER_HPP
#define EVENT_PLAYER_HPP
#include "event.hpp"

class playerEvent : public Event{
public:
    void execute() override = 0;
};

#endif