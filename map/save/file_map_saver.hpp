#ifndef FILE_MAP_SAVER
#define FILE_MAP_SAVER

#include "map_saver.hpp"


class FileMapSaver : MapSaver {
public:
    void saveMap(const Field &map, const std::string& saveName, Player player) final;
};


#endif