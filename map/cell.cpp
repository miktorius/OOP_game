#include "cell.hpp"

Cell::Cell(bool passable) : passability(passable) {}

void Cell::setPassable(bool passable) { passability = passable; }

void Cell::setEvent() {};

bool Cell::isPassable() const { return passability; }

Cell::~Cell() {}