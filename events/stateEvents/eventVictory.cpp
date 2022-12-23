#include "eventVictory.hpp"
#include "../../log/messages/event_messages.hpp"

void eventVictory::execute(Controller& ctrl){
    this->copySubscriptions(&ctrl);
    if (ctrl.getPlayer().getWeight() >= 100){
        notify(EventMessages::win());
        ctrl.onStateChange(GameState::Win);
    }
}

std::string eventVictory::toString() const {
    return "<Event name={win}>";
}