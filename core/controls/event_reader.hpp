#ifndef EVENT_READER_HPP
#define EVENT_READER_HPP

class EventReader;

#include <iostream>
#include "../mediator.hpp"
#include "controls_storage.hpp"

class EventReader {
public:
    virtual void readCommands() const = 0;
};

#endif