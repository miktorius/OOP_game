#ifndef MAP_SAVER
#define MAP_SAVER

#include "../field.hpp"


class MapSaver {
public:
        virtual void saveMap(const Field& map, const std::string& saveName, Player player) = 0;
    };


#endif