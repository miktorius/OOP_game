#ifndef EVENT_CREATOR
#define EVENT_CREATOR

class EventCreator;

#include "event.hpp"

class EventCreator {
public:
    virtual Event* fromString(std::string str) = 0;
};


#endif