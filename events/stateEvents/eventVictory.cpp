#include "eventVictory.hpp"

void eventVictory::execute(Controller& ctrl){
    if (ctrl.getPlayer().getWeight() >= 100){
        ctrl.getStateMediator()->changeState(GameState::Win);
    }
}