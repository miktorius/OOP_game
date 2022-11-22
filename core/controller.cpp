#include "controller.hpp"
#include <iostream>
#include <stdlib.h>
#include "../map/field.hpp"
#include "../graphics/field_view.hpp"
#include "../utils/vector2i.hpp"
#include "../events/playerEvents/eventHeal.hpp"
#include "../events/playerEvents/eventHurt.hpp"
#include "../events/stateEvents/eventVictory.hpp"
#include "../events/stateEvents/eventDefeat.hpp"

Controller::Controller(Mediator *mediator, int w, int h) 
    : field(new Field(w, h)), 
    player(Player()), 
    mediator(mediator),
    gameState(GameState::Playing){}

Controller::Controller(Mediator *mediator) 
    : field(new Field), 
    player(Player()),
    mediator(mediator),
    gameState(GameState::Playing){}

void Controller::run() {
    Event* eventHPDec = new eventHurt;
    Event* eventHPInc = new eventHeal;
    Event* eventWin = new eventVictory;
    Event* eventLose = new eventDefeat;
    field->changeCellPassability({1,1}, false);
    field->setCellEvent({2, 2}, eventHPDec);
    field->setCellEvent({3, 3}, eventHPInc);
    field->setCellEvent({5, 5}, eventWin);
    field->setCellEvent({6, 6}, eventLose);
    FieldView::drawField(*field, field->getPlayerPosition(), player);
}

Player& Controller::getPlayer(){
    return player;
}

StateMediator* Controller::getStateMediator() {
    return stateMediator;
}

void Controller::onStateChange(GameState newState) {
    if (newState == GameState::Win) {
        system("cls");
        std::cout << "You won!";
        mediator->endGame();
    }
    else if(newState == GameState::Loss){
        //system("cls");
        std::cout << "You lost!";
        mediator->endGame();
    }
}

void Controller::onCommand(UserCommand cmd){
    Vector2i tmpPos = field->getPlayerPosition();
    //field->getMap()[tmpPos.x][tmpPos.y].detectPlayer();
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
    if (cmd == UserCommand::ESC) {
        system("cls");
    }
    else {
        auto size = field->getSize();
        tmpPos.x = (tmpPos.x + size.x) % size.x;
        tmpPos.y = (tmpPos.y + size.y) % size.y;
        if (field->getCellPassability(tmpPos)){
            field->setPlayerPosition(tmpPos);
            field->activateCellEvent(tmpPos, *this);
        }
        if (player.getHP() == 0) {
            stateMediator->changeState(GameState::Loss);
        }

        FieldView::drawField(*field, field->getPlayerPosition(), player);
    }
}
