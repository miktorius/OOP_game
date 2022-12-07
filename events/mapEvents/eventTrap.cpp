#include "eventTrap.hpp"
#include "../../log/messages/event_messages.hpp"

void eventTrap::execute(Controller& ctrl){
    Field* f = ctrl.getField();
    Vector2i wh = f->getSize();
    Vector2i pos = f->getPlayerPosition();
    notify(EventMessages::playerTrapped());
    f->changeCellPassability({(pos.x + 1)%wh.x, pos.y}, false);
    f->changeCellPassability({(pos.x - 1)%wh.x, pos.y}, false);
    f->changeCellPassability({pos.x, (pos.y + 1)%wh.y}, false);
    f->changeCellPassability({pos.x, (pos.y - 1)%wh.y}, false);
}