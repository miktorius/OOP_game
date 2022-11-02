#include "field.hpp"
#include "cell.hpp"
#include "../utils/vector2i.hpp"
#include <vector>

Field::Field() : Field(10,10) {}
Field::Field(int width, int height) : width(width), height(height) {
    playerPosition = {0,0};
    map = std::vector<std::vector<Cell>>(
        height, 
        std::vector<Cell>(width, Cell())
        );
}

Field::Field(const Field &copy): width(copy.width), height(copy.height) {
    playerPosition = copy.playerPosition;
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


Field::Field(Field &&move): width(move.width), height(move.height) {
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

Vector2i Field::getPlayerPosition() const { return playerPosition; }

void Field::setPlayerPosition(Vector2i argPos) { playerPosition = argPos; }

std::vector<std::vector<Cell>> Field::getMap() const { return map; }

void Field::changeCellPassability(Vector2i position, bool passable) {
    map[position.y][position.x].setPassable(passable);
}

bool Field::getCellPassability(Vector2i position) const {
    return map[position.y][position.x].isPassable();
}