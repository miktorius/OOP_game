#ifndef CONSOLE_LOGGER_HPP
#define CONSOLE_LOGGER_HPP

#include "logger.hpp"


class ConsoleLogger : public Logger {
public:
    void update(const Message &message);
};


#endif