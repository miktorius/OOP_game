#ifndef COMMAND_READER_HPP
#define COMMAND_READER_HPP
class CommandReader;
#include "game_mediator.hpp"

class CommandReader {
private:
    GameMediator *mediator;
public:
    CommandReader(GameMediator *mediator);
    void readCommands();
    void readSize();
};

#endif