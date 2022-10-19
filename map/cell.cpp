#include "cell.hpp"

Cell::Cell(bool passable/*, bool detection*/) : passability(passable)/*, playerDetected(detection)*/ {}

void Cell::setPassable(bool passable) { passability = passable; }

void Cell::setEvent() {}

void Cell::activateEvent() {}

// bool Cell::isPlayerDetected() { return playerDetected; }

// void Cell::detectPlayer() { playerDetected = !playerDetected; }

bool Cell::isPassable() const { return passability; }

Cell::~Cell() {}