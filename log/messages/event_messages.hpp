#ifndef EVENT_MESSAGES_HPP
#define EVENT_MESSAGES_HPP

#include "message_storage.hpp"

class EventMessages : public MessageStorage {
public:
    static Message playerHealed();
    static Message playerDamaged(int newHP);
    static Message weightGain();
    static Message weightLoss();
    static Message lose();
    static Message win();
    static Message playerTrapped();

    static Message trapTriggered();

    static Message gameLost();
    static Message gameWon();
};

#endif