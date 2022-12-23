#ifndef SAVE_LOADER_HPP 
#define SAVE_LOADER_HPP

#include <fstream>
#include "../field.hpp"


class SaveLoader {
public:
    virtual Field *loadMap(Entity &player) = 0;
};


#endif