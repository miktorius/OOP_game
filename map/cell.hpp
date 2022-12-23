#ifndef CELL_HPP
#define CELL_HPP

class Cell;

#include "../events/event.hpp"
#include "../utils/eventType.hpp"
#include "../utils/saveable_component.hpp"
#include "../events/event_creator.hpp"

class Cell : public SaveableComponent{
public:
    Cell(bool passable = true);
    void setPassable(bool passable);
    void setEvent(Event* evnt);
    void activateEvent(Controller& ctrl);
    void setType(eventType tileType);
    eventType getType();
    Event* getEvent();
    bool isPassable() const;
    ~Cell();
    friend std::ostream &operator<<(std::ostream &stream, const Cell &cell);
    std::string toString() const;
    static Cell fromString(const std::string& data, EventCreator* eventCreator); 

private:
    bool passability;
    bool playerDetected;
    eventType type;
    Event* event;
};

#endif