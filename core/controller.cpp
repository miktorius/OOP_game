#include "controller.hpp"
#include <iostream>
#include <stdlib.h>
#include "../map/field.hpp"
#include "../graphics/field_view.hpp"
#include "../utils/vector2i.hpp"

#include "../events/playerEvents/eventHeal.hpp"
#include "../events/playerEvents/eventHurt.hpp"
#include "../events/playerEvents/eventGetWeight.hpp"
#include "../events/playerEvents/eventLoseWeight.hpp"
#include "../events/stateEvents/eventVictory.hpp"
#include "../events/stateEvents/eventDefeat.hpp"
#include "../events/mapEvents/eventTrap.hpp"

#include "../log/messages/player_messages.hpp"
#include "../log/messages/game_state_messages.hpp"

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

    notify(GameStateMessages::gameStart());

    Event* eventHPDec = new eventHurt;
    Event* eventHPInc = new eventHeal;
    Event* eventWin = new eventVictory;
    Event* eventLose = new eventDefeat;
    Event* eventBlock = new eventTrap;
    Event* eventFatten = new eventGetWeight;
    Event* eventThin = new eventLoseWeight;

    eventHPDec->copySubscriptions(this);
    eventHPInc->copySubscriptions(this);
    eventWin->copySubscriptions(this);
    eventLose->copySubscriptions(this);
    eventBlock->copySubscriptions(this);
    eventFatten->copySubscriptions(this);
    eventThin->copySubscriptions(this);

    field->changeCellPassability({2, 2}, false);
    field->setCellEvent({0, 2}, eventHPDec, eventType::HURT);
    field->setCellEvent({0, 4}, eventHPInc, eventType::HEAL);
    field->setCellEvent({0, 6}, eventWin, eventType::VICTORY);
    field->setCellEvent({0, 8}, eventLose, eventType::DEFEAT);
    field->setCellEvent({5, 5}, eventBlock, eventType::TRAP);
    field->setCellEvent({9, 9}, eventBlock, eventType::TRAP);
    field->setCellEvent({2, 0}, eventFatten, eventType::GETWEIGHT);
    field->setCellEvent({4, 0}, eventThin, eventType::LOSEWEIGHT);
    FieldView::drawField(*field, field->getPlayerPosition(), player);
}

void Controller::setSize(Vector2i size){
    this->w = size.x;
    this->h = size.y;
}

Player& Controller::getPlayer(){
    return player;
}

Field* Controller::getField(){
    return field;
}

StateMediator* Controller::getStateMediator() {
    return stateMediator;
}

GameState Controller::getState(){
    return gameState;
}

void Controller::setState(GameState state) {
    gameState = state;
}

void Controller::onStateChange(GameState newState) {
    system("cls");

    setState(newState);
    if (getState() == GameState::Win) {
        notify(GameStateMessages::gameVictory());
        std::cout << "\nYou won!";
    }
    else if(getState() == GameState::Loss){
        notify(GameStateMessages::gameDefeat());
        std::cout << "\nYou lost!";
    }
    notify(GameStateMessages::gameEnd());
    mediator->endGame();
}

void Controller::onCommand(UserCommand cmd){
    Vector2i tmpPos = field->getPlayerPosition();
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
        system("cls");
        notify(GameStateMessages::gameEnd());
        mediator->endGame();
        break;
    }
    if (cmd == UserCommand::ESC) {
    }
    else {
        system("cls");
        auto size = field->getSize();
        tmpPos.x = (tmpPos.x + size.x) % size.x;
        tmpPos.y = (tmpPos.y + size.y) % size.y;
        if (field->getCellPassability(tmpPos)){
            field->setPlayerPosition(tmpPos);
            notify(PlayerMessages::changedPosition(tmpPos));
            field->activateCellEvent(tmpPos, *this);
        }
        else { notify(PlayerMessages::triedToPassSolidCell(tmpPos)); }
        if (player.getHP() == 0) { onStateChange(GameState::Loss); }
        if (gameState == GameState::Playing){ FieldView::drawField(*field, field->getPlayerPosition(), player); }
    }
}
