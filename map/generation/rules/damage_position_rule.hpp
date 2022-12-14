#ifndef DAMAGE_EVENT_RULE
#define DAMAGE_EVENT_RULE

#include "../../field.hpp"
#include "../../../events/playerEvents/eventHurt.hpp"

#include <cstdlib>
#include <iostream>
#include <time.h>


// template <int x, int y>
// class DamagePositionRule {
// public:
//     static void changeMap(Field &field) {
//         field.setCellEvent({x,y}, new eventHurt, eventType::HURT);
//     }
// };

template <int probability>
class DamageEventRule {
public:
    static void changeMap(Field &field) {
        srand(time(NULL));
        Vector2i size = field.getSize();
        for(int i = 0; i < size.y; i++) {
            for (int j = 0; j < size.x; j++) {
                if (rand() % 100 < probability && field.getCell({j,i}).getEvent() == nullptr && field.getCell({j,i}).isPassable() == true) {
                    field.setCellEvent({j,i}, new eventHurt, eventType::HURT);
                }
            }
        }                
    }
};



#endif 