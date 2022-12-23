#ifndef EVENT_HPP
#define EVENT_HPP

class Event;

#include "../core/controller.hpp"
#include "../log/observable.hpp"
#include "../utils/saveable_component.hpp"

class Event : public Observable, public SaveableComponent{
public:
    virtual void execute(Controller& ctrl) = 0;
    // virtual ~Event() = default;
};

#endif