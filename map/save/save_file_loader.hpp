#ifndef SAVE_FILE_LOADER_HPP 
#define SAVE_FILE_LOADER_HPP

#include <fstream>
#include "save_loader.hpp"
#include "../../exceptions/loading_map_exception.hpp"
#include "../../entities/player.hpp"

class SaveFileLoader : public SaveLoader {
public:
    SaveFileLoader(const std::string &filename);
    ~SaveFileLoader();
    Field *loadMap(Entity &player);
private:
    std::ifstream file; 
};


#endif