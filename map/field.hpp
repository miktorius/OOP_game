#ifndef FIELD_HPP
#define FIELD_HPP

class Field;

#include <vector>
#include "../utils/vector2i.hpp"
#include "cell.hpp"
#include "../utils/eventType.hpp"

class Field {
private:
    int width;
    int height;
    Vector2i playerPosition;
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

    Vector2i getPlayerPosition() const;

    void setPlayerPosition(Vector2i argPos);

    std::vector<std::vector<Cell>> getMap() const;

    Cell& getCell(Vector2i pos);

    void changeCellPassability(Vector2i position, bool passable);

    void setCellEvent(Vector2i position, Event* evnt, eventType tileType);

    void activateCellEvent(Vector2i position, Controller& ctrl);

    bool getCellPassability(Vector2i position) const;
};

#endif