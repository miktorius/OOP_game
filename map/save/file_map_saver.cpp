#include "file_map_saver.hpp"
#include <fstream>
#include "../../utils/string_utilities.hpp"
#include "../../entities/player.hpp"
#include <iostream>


void FileMapSaver::saveMap(const Field &map, const std::string& saveName, Player player) {
    std::ofstream file(saveName + ".txt");
    std::string str = map.toString() + player.toString() + '\n';
    file << StringUtilities::hash(str) << "\n";
    file << str;
    
    file.close();
}
