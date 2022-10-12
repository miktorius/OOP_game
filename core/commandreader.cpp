#include "commandreader.hpp"
#include <iostream>

CommandReader::CommandReader(GameMediator *mediator) : mediator(mediator) {}

void CommandReader::readCommands() {
    while(mediator->gameIsRunning()) {
        char c;
        std::cin >> c;
        UserCommand cmd;
        switch(c) {
        case 'w': 
            cmd = UserCommand::UP;
            break;
        case 'a': 
            cmd = UserCommand::LEFT;
            break;
        case 's': 
            cmd = UserCommand::DOWN;
            break;
        case 'd': 
            cmd = UserCommand::RIGHT;
            break;
        case 'q': 
            cmd = UserCommand::ESC;
            break;
        default:
            cmd = UserCommand::UNKNOWN;
        }
        mediator->notify(cmd);
    }
}

void CommandReader::readSize() {
    int x, y;
    system("clear");
    std::cout << "Enter field size (x, y) : ";
    std::cin >> x >> y;
    mediator->notifySize(x, y);
}