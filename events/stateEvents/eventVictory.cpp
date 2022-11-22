#include "eventVictory.hpp"

void eventVictory::execute(Controller& ctrl){
    ctrl.getStateMediator()->changeState(GameState::Win);
}

char eventVictory::getSymbol(){
    return sym;
}