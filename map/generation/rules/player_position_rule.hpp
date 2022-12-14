#ifndef PLAYER_POSITION_RULE
#define PLAYER_POSITION_RULE

#include "../../field.hpp"


template <int x, int y>
class PlayerPositionRule {
public:
    static void changeMap(Field &field) {
        // TODO: Place player on the nearest non-solid cell
        field.setPlayerPosition({x,y});
    }
};

#endif 