#ifndef COMMAND_READER_HPP
#define COMMAND_READER_HPP
class CommandReader;
#include "mediator.hpp"

class CommandReader {
private:
    Mediator *mediator;
public:
    CommandReader(Mediator *mediator);
    void readCommands();
    void readSize();
};

#endif