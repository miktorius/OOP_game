#include "controller.hpp"
#include <iostream>
#include <stdlib.h>
#include "../map/field.hpp"
#include "../graphics/field_view.hpp"

Controller::Controller(GameMediator *mediator, int w, int h) 
    : field(Field(w, h)), 
    player(Player()), 
    playerPosition({0,0}), 
    w(w), h(h),
    mediator(mediator),
    view(FieldView()) {}

Controller::Controller(GameMediator *mediator) 
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

    switch(cmd) {
    case UserCommand::UP:
        playerPosition.y -= 1;
        break;
    case UserCommand::LEFT:
        playerPosition.x -= 1;
        break;
    case UserCommand::DOWN:
        playerPosition.y += 1;
        break;
    case UserCommand::RIGHT:
        playerPosition.x += 1;
        break;
    case UserCommand::ESC:
        mediator->endGame();
        break;
    }
    playerPosition.x = (playerPosition.x + w) % w;
    playerPosition.y = (playerPosition.y + h) % h;
    view.drawField(field, playerPosition);
}
