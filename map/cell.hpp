#ifndef CELL_HPP
#define CELL_HPP

class Cell;

#include "../events/event.hpp"
#include "../utils/eventType.hpp"

class Cell{
public:
    Cell(bool passable = true);
    void setPassable(bool passable);
    void setEvent(Event* evnt);
    void activateEvent(Controller& ctrl);
    void setType(eventType tileType);
    eventType getType();
    Event* getEvent();
    bool isPassable() const;
    ~Cell();
private:
    bool passability;
    bool playerDetected;
    eventType type;
    Event* event;
};

#endif