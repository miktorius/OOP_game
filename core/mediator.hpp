#ifndef GAME_MEDIATOR_HPP
#define GAME_MEDIATOR_HPP

class Mediator;

#include "controls/usercommand.hpp"
#include "controls/event_reader.hpp"
#include "controls/controls_storage.hpp"

#include "controller.hpp"


class Mediator{
public:
    Mediator();
    void start();
    void notify(UserCommand);
    void notifySize(int x, int y);
    void notifySize();
    bool gameIsRunning() const;
    void endGame();
private:
    EventReader *commandReader;
    Controller *controller;
    bool isGameOK;
    void configureLogging();
};

#endif
