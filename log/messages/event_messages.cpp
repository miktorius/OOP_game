#include "event_messages.hpp"

Message EventMessages::playerHealed() {
    return Message(LogType::ObjectState, "eventHeal triggered");
}

Message EventMessages::playerDamaged(int newHP) {
    return Message(
        LogType::ObjectState, 
        "eventHurt triggered. New hp: " + std::to_string(newHP));
}

Message EventMessages::weightGain(){
    return Message(LogType::ObjectState, "eventGetWeight triggered");
}

Message EventMessages::weightLoss(){
    return Message(LogType::ObjectState, "eventLoseWeight triggered");
}

Message EventMessages::lose() {
    return Message(LogType::ObjectState, "eventDefeat triggered");
}

Message EventMessages::win() {
    return Message(LogType::ObjectState, "eventVictory triggered");
}

Message EventMessages::playerTrapped() {
    return Message(LogType::ObjectState, "eventTrap triggered");
}