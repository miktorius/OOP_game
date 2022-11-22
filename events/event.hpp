#ifndef EVENT_HPP
#define EVENT_HPP

class Event;

#include "../core/controller.hpp"

class Event {
public:
    virtual void execute(Controller& ctrl) = 0;
    virtual char getSymbol() = 0;
    // virtual ~Event() = default;
};

#endif
// Event *ev = HealPlayerEvent(...); ev->call(...)
// 