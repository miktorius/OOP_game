#include "controls_storage.hpp"
#include <fstream>
#include <map>
#include <vector>
#include <iostream>

ControlsStorage::ControlsStorage() {
    std::vector<std::string> config = {
        "up: w", "down: s", "right: d", "left: a", "use: e", "esc: q"
    };
    for (std::string line : config) {
        auto p = process(line);
        binds[p.first] = p.second;
    }
}

ControlsStorage::ControlsStorage(const std::string &controlsFile) {
    std::ifstream file;
    file.open(controlsFile);

    if (file.fail()) {
        throw std::invalid_argument("Specified file does not exist!");
    }

    for( std::string line; getline( file, line ); ){
        auto p = process(line);
        binds[p.first] = p.second;
    }

    file.close();
}

UserCommand ControlsStorage::userCommandFromChar(char key) const {
    if (binds.count(key))
        return binds.at(key);
        
    return UserCommand::UNKNOWN;
} 

std::pair<char, UserCommand> ControlsStorage::process(const std::string &line) {

    std::map<std::string, UserCommand> decoding = {
        {"up", UserCommand::UP},
        {"down", UserCommand::DOWN},
        {"right", UserCommand::RIGHT},
        {"left", UserCommand::LEFT},
        {"esc", UserCommand::ESC}
    }; 

    std::string name = "";
    UserCommand ans;
    int divIndex = -1;

    for (int i = 0; i < line.size(); i ++) {
        if (line[i] == ':')
            if (decoding.count(name)) {
                ans = decoding[name];
                divIndex = i;
                break;
            }
        
        name += std::tolower(line[i]);
    }

    if (divIndex == -1)
        return {0, UserCommand::UNKNOWN};
    
    for (int i = divIndex+1; i < line.size(); i ++) 
        if (line[i] != ' ') {
            return {std::tolower(line[i]), ans};
        }
        
    return {0, UserCommand::UNKNOWN};
}

