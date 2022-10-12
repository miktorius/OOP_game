#include "field_view.hpp"
#include "../map/field.hpp"
#include "../utils/vector2i.hpp"

#include <iostream>

void FieldView::drawField(const Field &field, Vector2i playerPosition) {
    system("clear");
    for(int i = 0; i < field.get_size().y; i++) {
        for(int j = 0; j < field.get_size().x; j++) {
            if (playerPosition.x == j && playerPosition.y == i) 
                std::cout << "P";
            else 
                std::cout << (field.get_cell_passability({j,i}) ? "_" : "#");
        }
        std::cout << "\n";
    }
}
