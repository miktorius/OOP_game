#ifndef CONTROLS_STORAGE_HPP
#define CONTROLS_STORAGE_HPP

#include "usercommand.hpp"
#include <map>
#include <string>


class ControlsStorage {
private:
    std::map<char, UserCommand> binds;
    std::pair<char, UserCommand> process(const std::string &line);
public:
    ControlsStorage();
    ControlsStorage(const std::string &controlsFile);

    UserCommand userCommandFromChar(char key) const;
};

#endif