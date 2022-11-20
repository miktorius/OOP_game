#include "commandreader.hpp"
#include <iostream>
#include <string>

CommandReader::CommandReader(Mediator *mediator) : mediator(mediator) {}

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
    std::string input, inputX, inputY;
    bool inputIsCorrect;
    system("cls");
    while ((input != "1") || (input != "2")){
        std::cout << "Custom size - 1\nDefault size (10 x 10) - 2\nQuit - q\n\nInput : ";
        std::cin >> input;
        if (input == "1"){
            system("cls");
            while ((x < 5 || x > 15) || (y < 5 || y > 15)){
                inputIsCorrect = true;
                std::cout << "min = 5, max = 15\nEnter field size (width, height) : ";
                std::cin >> inputX >> inputY;
                for (int i = 0; i < inputX.length(); i++) { // идем по символам
                    if (inputX[i] >= 'A' && inputX[i] <= 'Z' || inputX[i] >= 'a' && inputX[i] <= 'z') {
                        inputIsCorrect = false;
                        break;
                    } 
                }
                for (int i = 0; i < inputY.length(); i++) { // идем по символам
                    if (inputY[i] >= 'A' && inputY[i] <= 'Z' || inputY[i] >= 'a' && inputY[i] <= 'z') {
                        inputIsCorrect = false;
                        break;
                    } 
                }
                if (inputIsCorrect){
                    x = stoi(inputX);
                    y = stoi(inputY);
                }
                if ((x >= 5 && x <= 15) && (y >= 5 && y <= 15)){
                    mediator->notifySize(x, y);
                }
                else {
                    system("cls");
                    std::cout << "Input error, please try again.\n";                  
                }
            }
            break;
        }
        else if (input == "2"){
            mediator->notifySize();
            break;
        }
        else if (input == "q") {
            system("cls");
            mediator->endGame();
            break;
        }
        else {
            system("cls");
            std::cout << "Input error, please try again.\n";
        }
    }
}