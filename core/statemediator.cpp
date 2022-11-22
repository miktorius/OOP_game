#include "statemediator.hpp"

StateMediator::StateMediator(Controller *ctrl) : c(ctrl) {}

 void StateMediator::changeState(GameState newState) {
        c->onStateChange(newState);
}