#include "player_messages.hpp"

Message PlayerMessages::changedPosition(const Vector2i &pos) {
    std::string x = std::to_string(pos.x),
				y = std::to_string(pos.y);
	std::string p = "["+x+", "+y+"]";
    return Message(LogType::ObjectState, "Player position : "+p);
}

Message PlayerMessages::triedToPassSolidCell(const Vector2i &pos) {
    std::string x = std::to_string(pos.x),
				y = std::to_string(pos.y);
	std::string p = "["+x+", "+y+"]";
    return Message(LogType::CriticalState, "Player tried to pass through solid cell " + p);
}  