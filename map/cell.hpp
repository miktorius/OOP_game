#ifndef CELL_HPP
#define CELL_HPP

#include "../events/event.hpp"

class Cell{
private:
    bool isPassable;
    Event event;
public:
    Cell(bool passable = true);
    void set_passable(bool passable);
    void set_event();
    bool is_passable() const;
    ~Cell();
};

#endif