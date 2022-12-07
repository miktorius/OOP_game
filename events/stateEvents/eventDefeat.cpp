#include "eventDefeat.hpp"
#include "../../log/messages/event_messages.hpp"

void eventDefeat::execute(Controller& ctrl){
    notify(EventMessages::lose());
    ctrl.onStateChange(GameState::Loss);
}