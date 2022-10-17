#include "game_mediator.hpp"
#include <iostream>

GameMediator::GameMediator() : isGameOK(false), commandReader(new CommandReader(this)) {}

void GameMediator::start() {
    isGameOK = true;
    commandReader->readSize();
    commandReader->readCommands();
}

bool GameMediator::gameIsRunning() const {
    return isGameOK;
}
void GameMediator::endGame() {
    isGameOK = false;
}

void GameMediator::notify(UserCommand cmd){
    controller->onCommand(cmd);
}

void GameMediator::notifySize(int x, int y){
    controller = new Controller(this, x, y);
    controller->run();
}

void GameMediator::notifySize(){
    controller = new Controller(this);
    controller->run();
}