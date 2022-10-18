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
    Vector2i getSize() const;  
    void changeCellPassability(Vector2i position, bool passable);
    bool getCellPassability(Vector2i position) const;
};

#endif