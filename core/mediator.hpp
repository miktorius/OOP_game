#ifndef GAME_MEDIATOR_HPP
#define GAME_MEDIATOR_HPP
class Mediator;
enum class UserCommand {
    UP, DOWN, LEFT, RIGHT, ESC, UNKNOWN
};
#include "commandreader.hpp"
#include "controller.hpp"
#include "../log/observable.hpp"

class Mediator : public Observable{
public:
    Mediator();
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
    void configureLogging();
};

#endif
