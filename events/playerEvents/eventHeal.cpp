#include "eventHeal.hpp"
#include "../../log/messages/event_messages.hpp"

void eventHeal::execute(Controller& ctrl){
    int heal = 10;
    Player& player = ctrl.getPlayer();
    int maxHP = player.getMaxHP();
    int HP = player.getHP();
    if (HP + heal > maxHP){ player.setHP(maxHP); }
    else { player.setHP(HP + heal); }
    notify(EventMessages::playerHealed());
};