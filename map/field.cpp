#include "field.hpp"
#include <vector>
#include <sstream>


Field::Field() : Field(10,10) {}
Field::Field(int width, int height) : width(width), height(height), playerPosition(0,0) {
    map = std::vector<std::vector<Cell>>(
        height, 
        std::vector<Cell>(width, Cell())
        );
}

Field::Field(const Field &copy): width(copy.width), height(copy.height), playerPosition (copy.playerPosition) {
    map = std::vector<std::vector<Cell>>(
        height, 
        std::vector<Cell>(width, Cell())
        );
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            this->map[i][j] = copy.map[i][j];
}

Field &Field::operator=(const Field &copy) {
    playerPosition = copy.playerPosition;
    map = std::vector<std::vector<Cell>>(
    height, 
    std::vector<Cell>(width, Cell())
    );
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            this->map[i][j] = copy.map[i][j];
    return *this;
}


Field::Field(Field &&move): width(move.width), height(move.height), playerPosition(move.playerPosition) {
    map = std::vector<std::vector<Cell>>(
        height, 
        std::vector<Cell>(width, Cell())
        );
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            this->map[i][j] = move.map[i][j];
    move.map.clear();
    playerPosition = {0,0};
    move.width = 0;
    move.height = 0;
}

Field &Field::operator=(Field &&move){
    playerPosition = move.playerPosition;
    map = std::vector<std::vector<Cell>>(
        height, 
        std::vector<Cell>(width, Cell())
        );
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            this->map[i][j] = move.map[i][j];
    move.map.clear();
    playerPosition = {0,0};
    move.width = 0;
    move.height = 0;
    return *this;
}

Field::~Field() {
    map.clear();
};

Vector2i Field::getSize() const { return {width, height}; }

void Field::setSize(Vector2i size){
    width = size.x;
    height = size.y;
    map = std::vector<std::vector<Cell>>(
        height, 
        std::vector<Cell>(width, Cell())
        );
}

Vector2i Field::getPlayerPosition() const { return playerPosition; }

void Field::setPlayerPosition(Vector2i argPos) {
    playerPosition = argPos;
}

std::vector<std::vector<Cell>> Field::getMap() const { return map; }

Cell& Field::getCell(Vector2i pos){ return map[pos.y][pos.x]; }

void Field::changeCellPassability(Vector2i position, bool passable) {
    map[position.y][position.x].setPassable(passable);
}

void Field::setCellEvent(Vector2i position, Event* evnt, eventType tileType){
    map[position.y][position.x].setEvent(evnt);
    map[position.y][position.x].setType(tileType);   
}

void Field::activateCellEvent(Vector2i position, Controller& ctrl){
    map[position.y][position.x].activateEvent(ctrl);
}

bool Field::getCellPassability(Vector2i position) const {
    return map[position.y][position.x].isPassable();
}
void Field::setCell(Vector2i position, Cell cell) {
    map[position.x][position.y] = cell;
}

std::ostream &operator<<(std::ostream &stream, const Field &map) {
    stream << "<Field " << map.height << " x " << map.width << ">";
    return stream;
}

std::string Field::toString() const {
    std::stringstream sstr;
    sstr << "{Field " << width << " " << height << "}\n";
    for(int i = 0; i < height; i ++) {
        for(int j = 0; j < width; j ++){
            sstr << i << " " << j << " " << map[i][j].toString() << '\n';
        }
    }
    sstr << "{Player " << playerPosition.x << " " << playerPosition.y << "}\n";
    
    return sstr.str();
}