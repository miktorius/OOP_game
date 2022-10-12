#ifndef FIELD_HPP
#define FIELD_HPP

#include <vector>
#include "../utils/vector2i.hpp"
#include "cell.hpp"

class Field{
private:
    int width;
    int height;
    std::vector< std::vector<Cell> > map;
public:
    Field();
    Field(int width, int height);
    Vector2i get_size() const;  
    void change_cell_passability(Vector2i position, bool passable);
    bool get_cell_passability(Vector2i position) const;
};

#endif