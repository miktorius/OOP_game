#include "console_logger.hpp"
#include "logger.hpp"
#include <iostream>


void ConsoleLogger::update(const Message &message) {
    if (logTypeAvailable(message.type()))
        std::cout << message << '\n';
}

