#include "mediator.hpp"
#include <iostream>

#include "../log/console_logger.hpp"
#include "../log/file_logger.hpp"
#include "../log/logger_pool.hpp"
#include "../log/messages/game_state_messages.hpp"
#include "controls/commandreader.hpp"

Mediator::Mediator() : isGameOK(false) {
    ControlsStorage storage;
    try {
        storage = ControlsStorage("controls.txt");
    } catch (std::invalid_argument &e) {
        // storage is already created with default configuration
    }
    commandReader = new CommandReader(this, storage);
    controller = new Controller(this);
    configureLogging(); 
}

void Mediator::start() {
    isGameOK = true;
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

void Mediator::launchController(){
    controller->run();
}

void Mediator::configureLogging() {
    system("cls");
    auto &loggerPool = LoggerPool::getInstance();
    std::cout << "Logging configuration.\n";
    std::cout << "Enter 0 to skip, 1 to add ConsoleLogger, 2 to add FileLogger : ";
    int choice;
    std::cin >> choice;

    while (choice) {
        
        std::string filename;
        Logger *logger;
        bool err = false;
        switch (choice)
        {
        case 1:
            logger = new ConsoleLogger;
            break;
        case 2:
            system("cls");
            std::cout << "Enter file name to log into: ";
            std::cin >> filename;
            logger = new FileLogger(filename);
            break;
        default:
            err = true;
            std::cout << "Invalid choice\n";
            break;
        }
        if (!err) {
            system("cls");
            std::cout << "To make logger log levels, input sum of numbers next to log level that"
                  << " should be logged : GameState - 1; ObjectState - 2; CriticalState - 4: ";
            int sum;
            std::cin >> sum;
            if (sum & 1)
                logger->addLogType(LogType::GameState);
            if (sum/2 & 1)
                logger->addLogType(LogType::ObjectState);
            if (sum/4 & 1)
                logger->addLogType(LogType::CriticalState);
                
            controller->subscribe(logger);
            loggerPool.addLogger(logger);
        }

        std::cout << "Enter 0 to skip, 1 to add ConsoleLogger, 2 to add FileLogger\n";
        std::cin >> choice;
    }
}