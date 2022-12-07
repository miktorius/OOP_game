#ifndef COMMAND_READER_HPP
#define COMMAND_READER_HPP


#include "../mediator.hpp"
#include "event_reader.hpp"
#include "controls_storage.hpp"

class CommandReader : public EventReader{
public:
    CommandReader() = delete;
    CommandReader(Mediator *notifier, ControlsStorage controls);
    void readCommands() const;
private:
    Mediator *mediator;
    ControlsStorage storage;
};

#endif