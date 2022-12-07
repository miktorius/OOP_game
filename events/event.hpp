#ifndef EVENT_HPP
#define EVENT_HPP

class Event;

#include "../core/controller.hpp"
#include "../log/observable.hpp"

class Event : public Observable {
public:
    virtual void execute(Controller& ctrl) = 0;
    // virtual ~Event() = default;
};

#endif