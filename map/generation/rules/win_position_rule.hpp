#ifndef WIN_POSITION_RULE
#define WIN_POSITION_RULE

#include "../../field.hpp"
#include "../../../events/stateEvents/eventVictory.hpp"

template <int x, int y>
class WinEventPositionRule {
public:
    static void changeMap(Field &field) {
        field.setCellEvent({x,y}, new eventVictory(), eventType::VICTORY);
    }
};


#endif