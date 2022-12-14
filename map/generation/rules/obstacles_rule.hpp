#ifndef OBSTACLES_RULE
#define OBSTACLES_RULE

#include "../../field.hpp"
#include "../../../utils/vector2i.hpp"

enum class ObstaclesVariant {
    SPIRAL, ROOMS
};

template <ObstaclesVariant variant>
class ObstaclesRule {
public:
    static void changeMap(Field &field) {
        const auto &size = field.getSize();
        if (variant == ObstaclesVariant::ROOMS) {
            // BORDERS
            for (int i = 0; i < size.y; i ++) {
                field.changeCellPassability({0,i}, false);
                field.changeCellPassability({(int)size.x-1,i}, false);
            }
            for (int i = 0; i < size.x; i ++) {
                field.changeCellPassability({i,0}, false);
                field.changeCellPassability({i,(int)size.y-1}, false);
            }

            for(int i = 0; i < size.x; i ++) {
                if (i != size.x / 2)
                field.changeCellPassability({i,(int)size.y/2}, false);
            }
        } 
        else if (variant == ObstaclesVariant::SPIRAL) {
            
            int dirInd = 0;
            std::vector<Vector2i> dirs = { {1,0}, {0,1}, {-1,0}, {0,-1} };
            int stepsX = size.x, stepsY = size.y;
            Vector2i pos = {0,0};

            while(stepsX > 0 || stepsY > 0) {
                for (int i = 0; i < (dirInd % 2 == 0 ? stepsX : stepsY); i ++) {
                    field.changeCellPassability(pos, false);
                    pos.x += dirs[dirInd].x;
                    pos.y += dirs[dirInd].y;
                }
                stepsX --;
                stepsY --;
                dirInd ++;
                dirInd %= 4;
            }
        }
    }
};



#endif