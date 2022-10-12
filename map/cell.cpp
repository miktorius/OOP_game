#include "cell.hpp"

Cell::Cell(bool passable) : isPassable(passable) {}

void Cell::set_passable(bool passable) {isPassable = passable;}

bool Cell::is_passable() const { return isPassable; }

Cell::~Cell() {}