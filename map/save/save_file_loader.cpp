#include "save_file_loader.hpp"

#include "../../utils/string_utilities.hpp"
#include "../../utils/vector2i.hpp"
#include "../../events/test_event_creator.hpp"



SaveFileLoader::SaveFileLoader(const std::string &filename) {
    file.open(filename);
    if (file.fail()) {
        throw Exceptions::LoadingMapException(
            Exceptions::LoadingMapException::Step::Undefined, 
            Exceptions::LoadingMapException::Reason::NoFile);
    }
}

SaveFileLoader::~SaveFileLoader() {
    file.close();
}

Field *SaveFileLoader::loadMap(Entity &player) {
    std::string line;
    bool fieldCreated = false, cellsPlaced = false, playerCreated = false;

    Field *result = new Field;
    TestEventCreator* eventCreator = new TestEventCreator(*result);

    std::getline(file, line);
    std::string fileHash = line;
    std::string fileContent;

    while (std::getline(file, line)) {
        fileContent += line+'\n';
        if (!fieldCreated && line.substr(0, 7) == "{Field ") {
            try {
                auto fSize = StringUtilities::findTwoInts(line);
                result->setSize( {fSize.first, fSize.second} );
            } catch (...) {
                throw Exceptions::LoadingMapException(
                    Exceptions::LoadingMapException::Step::FieldCreation, 
                    Exceptions::LoadingMapException::Reason::FileDataIncorrect);
            }
            fieldCreated = true;
        }
        else if (fieldCreated && !cellsPlaced) {
            if (line.substr(0, 8) == "{Player ") {
                // player
                cellsPlaced = true;
                try {
                    auto playerPos = StringUtilities::findTwoInts(line);
                    result->setPlayerPosition ({playerPos.first, playerPos.second});
                } catch (...) {
                    throw Exceptions::LoadingMapException(
                        Exceptions::LoadingMapException::Step::PlayerCreation, 
                        Exceptions::LoadingMapException::Reason::FileDataIncorrect);
                }
                continue;
            }
            try {
                auto cellPos = StringUtilities::findTwoInts(line);
                Cell cell = Cell::fromString(line.substr(line.find('<')), eventCreator);
                result->setCell({cellPos.first, cellPos.second}, cell);
            } catch (...) {
                throw Exceptions::LoadingMapException(
                    Exceptions::LoadingMapException::Step::CellCreation, 
                    Exceptions::LoadingMapException::Reason::FileDataIncorrect);
            }
        }

        else if (cellsPlaced) {
            try {
                player = Player::fromString(line);
                playerCreated = true;
            } catch (...) {
                throw Exceptions::LoadingMapException(
                    Exceptions::LoadingMapException::Step::PlayerCreation, 
                    Exceptions::LoadingMapException::Reason::FileDataIncorrect);
            }
        }
    }

    if (std::to_string(StringUtilities::hash(fileContent)) != fileHash)
        throw Exceptions::LoadingMapException(
            Exceptions::LoadingMapException::Step::Undefined, 
            Exceptions::LoadingMapException::Reason::FileChanged);

    if (!fieldCreated) 
        throw Exceptions::LoadingMapException(
            Exceptions::LoadingMapException::Step::FieldCreation, 
            Exceptions::LoadingMapException::Reason::FileDataIncorrect);
    
    if (!playerCreated) 
        throw Exceptions::LoadingMapException(
            Exceptions::LoadingMapException::Step::PlayerCreation, 
            Exceptions::LoadingMapException::Reason::FileDataIncorrect);
        
    return result;
}
