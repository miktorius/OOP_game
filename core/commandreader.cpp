#include "commandreader.hpp"
#include <iostream>
#include <string>

CommandReader::CommandReader(GameMediator *mediator) : mediator(mediator) {}

void CommandReader::readCommands() {
    while(mediator->gameIsRunning()) {
        std::string tmp;
        std::cin >> tmp;
        char c = tmp[0];
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
    std::string input;
    system("clear");
    while ((input != "1") || (input != "2")){
        std::cout << "Enter :\nCustom size - 1\nDefault size - 2\n";
        std::cin >> input;
        if (input == "1"){
            system("clear");
            std::cout << "Enter field size (x, y) : ";
            std::cin >> x >> y;
            mediator->notifySize(x, y);
            break;
        }
        else if (input == "2"){
            mediator->notifySize();
            break;
        }
        else {
            system("clear");
            std::cout << "Input error, please try again.\n";
        }
    }
}