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

    Field(const Field &copy);
    Field &operator=(const Field &copy);

    Field(Field &&move);
    Field &operator=(Field &&move);  

    ~Field();

    Vector2i getSize() const;
    std::vector<std::vector<Cell>> getMap() const;
    void changeCellPassability(Vector2i position, bool passable);
    bool getCellPassability(Vector2i position) const;
};

#endif