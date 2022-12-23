#include "test_event_creator.hpp"

#include <map>

#include "../utils/string_utilities.hpp"

#include "../events/playerEvents/eventHeal.hpp"
#include "../events/playerEvents/eventHurt.hpp"
#include "../events/playerEvents/eventGetWeight.hpp"
#include "../events/playerEvents/eventLoseWeight.hpp"
#include "../events/stateEvents/eventVictory.hpp"
#include "../events/stateEvents/eventDefeat.hpp"
#include "../events/mapEvents/eventTrap.hpp"


TestEventCreator::TestEventCreator(Field &field) : m_field(field) {}

Event* TestEventCreator::fromString(std::string slon) {
    std::map<std::string, std::string> mp = StringUtilities::stringToMap(slon);
    std::string name = mp["name"];
    Event *event = nullptr;

    if (name == "damage") {
        event = new eventHurt();
    }
    if (name == "win") {
        event = new eventVictory();
    }

    return event;
}
