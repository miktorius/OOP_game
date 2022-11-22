#include "eventTrap.hpp"

void eventTrap::execute(Controller& ctrl){
    Field* f = ctrl.getField();
    Vector2i wh = f->getSize();
    Vector2i pos = f->getPlayerPosition();
    f->changeCellPassability({(pos.x + 1)%wh.x, pos.y}, false);
    f->changeCellPassability({(pos.x - 1)%wh.x, pos.y}, false);
    f->changeCellPassability({pos.x, (pos.y + 1)%wh.y}, false);
    f->changeCellPassability({pos.x, (pos.y - 1)%wh.y}, false);
}

char eventTrap::getSymbol(){
    return sym;
}