#include "controller.hpp"
#include <iostream>
#include <stdlib.h>
#include "../map/field.hpp"
#include "../graphics/field_view.hpp"
#include "../utils/vector2i.hpp"

Controller::Controller(Mediator *mediator, int w, int h) 
    : field(Field(w, h)), 
    player(Player()), 
    playerPosition({0,0}), 
    w(w), h(h),
    mediator(mediator),
    view(FieldView()) {}

Controller::Controller(Mediator *mediator) 
    : field(Field()), 
    player(Player()), 
    playerPosition({0,0}), 
    w(field.get_size().x), h(field.get_size().y),
    mediator(mediator),
    view(FieldView()) {}

void Controller::run() {
    field.change_cell_passability({1,1}, false);
    view.drawField(field, playerPosition);
}

void Controller::onCommand(UserCommand cmd){
    Vector2i tmpPos = playerPosition;
    switch(cmd) {
    case UserCommand::UP:
        tmpPos.y -= 1;
        break;
    case UserCommand::LEFT:
        tmpPos.x -= 1;
        break;
    case UserCommand::DOWN:
        tmpPos.y += 1;
        break;
    case UserCommand::RIGHT:
        tmpPos.x += 1;
        break;
    case UserCommand::ESC:
        mediator->endGame();
        break;
    }
    tmpPos.x = (tmpPos.x + w) % w;
    tmpPos.y = (tmpPos.y + h) % h;
    if (field.get_cell_passability(tmpPos)){
        playerPosition.x = tmpPos.x;
        playerPosition.y = tmpPos.y;
    }
    view.drawField(field, playerPosition);
}
