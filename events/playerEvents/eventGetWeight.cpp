#include "eventGetWeight.hpp"
#include "../../log/messages/event_messages.hpp"


void eventGetWeight::execute(Controller& ctrl){
    this->copySubscriptions(&ctrl);
    int gain = 10;
    Player& player = ctrl.getPlayer();
    int maxWeight = player.getMaxWeight();
    int weight = player.getWeight();
    if (weight != maxWeight) {
        if (weight + gain > maxWeight) { player.setWeight(maxWeight); }
        else { player.setWeight(weight + gain); }
        notify(EventMessages::weightGain());
    }
}