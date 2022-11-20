#ifndef FIELD_VIEW_HPP
#define FIELD_VIEW_HPP

#include "../map/field.hpp"
#include "../utils/vector2i.hpp"
#include "../entities/player.hpp"

class FieldView{
public:
    static void drawField(const Field &field, Vector2i playerPosition, const Player& player);
};

#endif