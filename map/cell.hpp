#ifndef CELL_HPP
#define CELL_HPP

#include "../events/event.hpp"

class Cell{
private:
    bool isPassable;
    Event event;
public:
    Cell(bool passable = true);
    void setPassable(bool passable);
    void setEvent();
    bool isPassable() const;
    ~Cell();
};

#endif