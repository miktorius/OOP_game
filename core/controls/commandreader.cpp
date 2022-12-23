#include "commandreader.hpp"
#include <iostream>
#include <string>

CommandReader::CommandReader(Mediator *notifier, ControlsStorage controls) : mediator(notifier), storage(controls) {}

void CommandReader::readCommands() const{
    //system("cls");
    
    mediator->launchController();
    while(mediator->gameIsRunning()) {
        std::string tmp;
        std::cin >> tmp;
        char c = tmp[0];
        UserCommand cmd;
        cmd = storage.userCommandFromChar(c);
        mediator->notify(cmd);
    }
}