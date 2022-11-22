#ifndef STATE_MEDIATOR
#define STATE_MEDIATOR

class StateMediator;

#include "controller.hpp"
#include "../utils/gameState.hpp"

class StateMediator {
private:
    Controller *c;
public:
    StateMediator( Controller *ctrl );
    void changeState(GameState newState);
};

#endif