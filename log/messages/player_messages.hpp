#ifndef PLAYER_MESSAGES
#define PLAYER_MESSAGES

#include "message_storage.hpp"
#include "../../utils/vector2i.hpp"

class PlayerMessages : public MessageStorage {
public:
    static Message changedPosition(const Vector2i &pos);
    static Message triedToPassSolidCell(const Vector2i &pos);
};

#endif