#include "controller.hpp"
#include <iostream>
#include <stdlib.h>
#include "../map/field.hpp"
#include "../graphics/field_view.hpp"
#include "../utils/vector2i.hpp"
#include "../events/playerEvents/eventHeal.hpp"
#include "../events/playerEvents/eventTrap.hpp"

Controller::Controller(Mediator *mediator, int w, int h) 
    : field(new Field(w, h)), 
    player(Player()), 
    mediator(mediator){}

Controller::Controller(Mediator *mediator) 
    : field(new Field), 
    player(Player()),
    mediator(mediator){}

void Controller::run() {
    Event* eventHPDec = new eventTrap;
    Event* eventHPInc = new eventHeal;
    field->changeCellPassability({1,1}, false);
    field->setCellEvent({2, 2}, eventHPDec);
    field->setCellEvent({3, 3}, eventHPInc);
    FieldView::drawField(*field, field->getPlayerPosition(), player);
}

Player& Controller::getPlayer(){
    return player;
}

/* 

enum class GameState {Win, Loss, Playing};

class StateMediator {
private:
    Controller *c;
    StateEvent *e;
public:
    StateMediator( Controller *ctrl, StateEvent *ev ) : c(ctrl), e(ev);
    void changeState(GameState newState) {
        controller->onStateChange(newState);
    }
};

Controller / private: GameState gameState (GameState::Playing)
Controller / public: StateMediator* getStateMediator();

void Controller::onStateChange(GameState newState) {
    if (newState == GameState::Win) {
        cout << "You won!";
        mediator->endGame();
    }

}

void VictoryEvent::execute(Controller &ctrl) {
    ctrl.getStateMediator()->changeState(GameState::Win);
}

*/ 

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

        FieldView::drawField(*field, field->getPlayerPosition(), player);
    }
}
