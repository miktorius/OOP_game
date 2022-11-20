#ifndef CELL_HPP
#define CELL_HPP

class Cell;

#include "../events/event.hpp"

class Cell{
public:
    Cell(bool passable = true/*,bool detection = false*/);
    void setPassable(bool passable);
    void setEvent(Event* evnt);
    void activateEvent(Controller& ctrl);
    // bool isPlayerDetected();
    // void detectPlayer();
    bool isPassable() const;
    ~Cell();
private:
    bool passability;
    bool playerDetected;
    Event* event;
};

#endif