#include "field.hpp"
#include "cell.hpp"
#include "../utils/vector2i.hpp"
#include <vector>

Field::Field() : Field(10,10) {}
Field::Field(int width, int height) : width(width), height(height) {
    map = std::vector<std::vector<Cell>>(
        height, 
        std::vector<Cell>(width, Cell())
        );
}

Vector2i Field::getSize() const {return {width, height};}

void Field::changeCellPassability(Vector2i position, bool passable) {
    map[position.y][position.x].setPassable(passable);
}

bool Field::getCellPassability(Vector2i position) const {
    return map[position.y][position.x].isPassable();
}