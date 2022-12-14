#include "eventDefeat.hpp"
#include "../../log/messages/event_messages.hpp"

void eventDefeat::execute(Controller& ctrl){
    this->copySubscriptions(&ctrl);
    notify(EventMessages::lose());
    ctrl.onStateChange(GameState::Loss);
}