#include "cell.hpp"
#include <sstream>
#include "../exceptions/slon_exception.hpp"
#include "../utils/string_utilities.hpp"


Cell::Cell(bool passable) : passability(passable), event(nullptr) {}

void Cell::setPassable(bool passable) { passability = passable; }

void Cell::setEvent(Event* evnt) { event = evnt; }

void Cell::activateEvent(Controller& ctrl) {
    if (event!=nullptr) { event->execute(ctrl); }
}

void Cell::setType(eventType tileType){ type = tileType; }

eventType Cell::getType(){ return type; }


Event* Cell::getEvent(){
    return event;
}

// bool Cell::isPlayerDetected() { return playerDetected; }

// void Cell::detectPlayer() { playerDetected = !playerDetected; }

bool Cell::isPassable() const { return passability; }

std::string Cell::toString() const {
    std::stringstream stream;
    stream << "<Cell solid={" << isPassable() << "}"
            << " contains_event={" << (event == nullptr ? "null" : event->toString()) << "}" 
            << ">";
    return stream.str();
}

std::ostream &operator<<(std::ostream &stream, const Cell &cell) {

    stream << cell.toString();
    return stream;
}

Cell Cell::fromString(const std::string& data, EventCreator* eventCreator) {
    auto mp = StringUtilities::stringToMap(data);
    Cell obj;
    obj.passability = mp["solid"] == "1";
    try {
        obj.event = eventCreator->fromString( mp["contains_event"] );
    } catch(const Exceptions::SlonException& ex) {
        obj.event = nullptr;
    }
    return obj;
}

Cell::~Cell() {}