#ifndef CELL_HPP
#define CELL_HPP

#include "../events/event.hpp"

class Cell{
public:
    Cell(bool passable = true);
    void setPassable(bool passable);
    void setEvent();
    bool isPassable() const;
    ~Cell();
private:
    bool passability;
    Event event;
};

#endif