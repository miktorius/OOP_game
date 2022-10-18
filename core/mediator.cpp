#include "mediator.hpp"
#include <iostream>

Mediator::Mediator() : isGameOK(false), commandReader(new CommandReader(this)) {}

void Mediator::start() {
    isGameOK = true;
    commandReader->readSize();
    commandReader->readCommands();
}

bool Mediator::gameIsRunning() const {
    return isGameOK;
}
void Mediator::endGame() {
    isGameOK = false;
}

void Mediator::notify(UserCommand cmd){
    controller->onCommand(cmd);
}

void Mediator::notifySize(int x, int y){
    controller = new Controller(this, x, y);
    controller->run();
}

void Mediator::notifySize(){
    controller = new Controller(this);
    controller->run();
}