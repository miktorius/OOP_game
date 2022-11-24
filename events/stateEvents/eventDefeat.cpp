#include "eventDefeat.hpp"

void eventDefeat::execute(Controller& ctrl){
    ctrl.getStateMediator()->changeState(GameState::Loss);
}