#include "eventHurt.hpp"
#include "../../log/messages/event_messages.hpp"

void eventHurt::execute(Controller& ctrl){
    this->copySubscriptions(&ctrl);
    Player& player = ctrl.getPlayer();
    int dmg = 20;
    int weight = player.getWeight();
    int HP = player.getHP();
    if (weight >= 50){
        if (HP - dmg < 0){ player.setHP(0); }
        else { player.setHP(HP - dmg); }
        notify(EventMessages::playerDamaged(player.getHP()));
    }
}

std::string eventHurt::toString() const {
    std::stringstream stream;
    stream << "<Event name={damage}>";
    return stream.str();
}