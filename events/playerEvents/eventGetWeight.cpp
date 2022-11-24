#include "eventGetWeight.hpp"

void eventGetWeight::execute(Controller& ctrl){
    int gain = 10;
    Player& player = ctrl.getPlayer();
    int maxWeight = player.getMaxWeight();
    int weight = player.getWeight();
    if (weight + gain > maxWeight){ player.setWeight(maxWeight); }
    else { player.setWeight(weight + gain); }
}