#include "game_state_messages.hpp"

Message GameStateMessages::gameStart() {
    return Message(LogType::GameState, "Game Started");
}

Message GameStateMessages::gameVictory() {
    return Message(LogType::GameState, "Win!");
}
Message GameStateMessages::gameDefeat() {
    return Message(LogType::GameState, "Loss!");
}

Message GameStateMessages::gameEnd() {
    return Message(LogType::GameState, "Game Finished");
}