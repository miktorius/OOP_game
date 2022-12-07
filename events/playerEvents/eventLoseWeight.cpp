#include "eventLoseWeight.hpp"
#include "../../log/messages/event_messages.hpp"

void eventLoseWeight::execute(Controller& ctrl){
    Player& player = ctrl.getPlayer();
    int loss = 10;
    int weight = player.getWeight();
    if (weight != 0){
        if (weight - loss < 0){ player.setWeight(0); }
        else { player.setWeight(weight - loss); }
        notify(EventMessages::weightLoss()); 
    }        
}