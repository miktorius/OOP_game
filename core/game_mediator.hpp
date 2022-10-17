#ifndef GAME_MEDIATOR_HPP
#define GAME_MEDIATOR_HPP
class GameMediator;
enum class UserCommand {
    UP, DOWN, LEFT, RIGHT, ESC, UNKNOWN
};
#include "commandreader.hpp"
#include "controller.hpp"

class GameMediator {
public:
    GameMediator();
    void start();
    void notify(UserCommand);
    void notifySize(int x, int y);
    void notifySize();
    bool gameIsRunning() const;
    void endGame();
private:
    CommandReader *commandReader;
    Controller *controller;
    bool isGameOK;
};

#endif
