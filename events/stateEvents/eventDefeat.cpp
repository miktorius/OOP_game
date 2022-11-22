#include "eventDefeat.hpp"

void eventDefeat::execute(Controller& ctrl){
    ctrl.getStateMediator()->changeState(GameState::Loss);
}

char eventDefeat::getSymbol(){
    return sym;
}