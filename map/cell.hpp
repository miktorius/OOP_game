#ifndef CELL_HPP
#define CELL_HPP

class Cell;

#include "../events/event.hpp"

class Cell{
public:
    Cell(bool passable = true);
    void setPassable(bool passable);
    void setEvent(Event* evnt);
    void activateEvent(Controller& ctrl);
    Event* getEvent();
    bool isPassable() const;
    ~Cell();
private:
    bool passability;
    bool playerDetected;
    Event* event;
};

#endif