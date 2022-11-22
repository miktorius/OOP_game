#include "cell.hpp"

Cell::Cell(bool passable/*, bool detection*/) : passability(passable), event(nullptr)/*, playerDetected(detection)*/ {}

void Cell::setPassable(bool passable) { passability = passable; }

void Cell::setEvent(Event* evnt) { event = evnt; }

void Cell::activateEvent(Controller& ctrl) {
    if (event!=nullptr) { event->execute(ctrl); }
}

Event* Cell::getEvent(){
    return event;
}

// bool Cell::isPlayerDetected() { return playerDetected; }

// void Cell::detectPlayer() { playerDetected = !playerDetected; }

bool Cell::isPassable() const { return passability; }

Cell::~Cell() {}