#ifndef LOSE_POSITION_RULE
#define LOSE_POSITION_RULE

#include "../../field.hpp"
#include "../../../events/stateEvents/eventDefeat.hpp"


template <int x, int y>
class LoseEventPositionRule {
public:
    static void changeMap(Field &field) {
        field.setCellEvent({x,y}, new eventDefeat(), eventType::DEFEAT);
    }
};


#endif