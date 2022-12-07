#include "game_state_messages.hpp"

Message GameStateMessages::gameStart() {
    return Message(LogType::GameState, "Game Started");
}

Message GameStateMessages::gameVictory() {
    return Message(LogType::GameState, "Victory!");
}
Message GameStateMessages::gameDefeat() {
    return Message(LogType::GameState, "Defeat!");
}

Message GameStateMessages::gameEnd() {
    return Message(LogType::GameState, "Game Finished");
}