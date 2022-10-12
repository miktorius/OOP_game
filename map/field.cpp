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

Vector2i Field::get_size() const {return {width, height};}

void Field::change_cell_passability(Vector2i position, bool passable) {
    map[position.y][position.x].set_passable(passable);
}

bool Field::get_cell_passability(Vector2i position) const {
    return map[position.y][position.x].is_passable();
}