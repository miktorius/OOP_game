#ifndef FIELD_VIEW_HPP
#define FIELD_VIEW_HPP

#include "../map/field.hpp"
#include "../utils/vector2i.hpp"

class FieldView{
public:
    void drawField(const Field &field, Vector2i playerPosition);
};

#endif