#ifndef GAME_STATE_MESSAGES
#define GAME_STATE_MESSAGES

#include "message_storage.hpp"

class GameStateMessages : public MessageStorage {
public:
    static Message gameStart();
    static Message gameVictory();
    static Message gameDefeat();
    static Message gameEnd();
};

#endif