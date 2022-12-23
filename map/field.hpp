#ifndef FIELD_HPP
#define FIELD_HPP

class Field;

#include <vector>
#include <sstream>
#include "../utils/vector2i.hpp"
#include "cell.hpp"
#include "../utils/eventType.hpp"
#include "../utils/saveable_component.hpp"

class Field : public SaveableComponent{
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

    void setSize(Vector2i size);

    Vector2i getPlayerPosition() const;

    void setPlayerPosition(Vector2i argPos);

    std::vector<std::vector<Cell>> getMap() const;

    Cell& getCell(Vector2i pos);

    void changeCellPassability(Vector2i position, bool passable);

    void setCellEvent(Vector2i position, Event* evnt, eventType tileType);
    void setCell(Vector2i position, Cell cell);

    void activateCellEvent(Vector2i position, Controller& ctrl);

    bool getCellPassability(Vector2i position) const;

    friend std::ostream &operator<<(std::ostream &stream, const Field &map);
    std::string toString() const;

};

#endif