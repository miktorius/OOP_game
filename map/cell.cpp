#include "cell.hpp"

Cell::Cell(bool passable) : isPassable(passable) {}

void Cell::setPassable(bool passable) {isPassable = passable;}

void Cell::setEvent() {};

bool Cell::isPassable() const { return isPassable; }

Cell::~Cell() {}