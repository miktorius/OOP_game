#include "field_view.hpp"
#include "../map/field.hpp"
#include "../utils/vector2i.hpp"

#include <iostream>

void FieldView::drawField(const Field &field, Vector2i playerPosition) {
    system("clear");
    for(int i = 0; i < field.getSize().y; i++) {
        for(int j = 0; j < field.getSize().x; j++) {
            if (playerPosition.x == j && playerPosition.y == i) 
                std::cout << "P";
            else 
                std::cout << (field.getCellPassability({j,i}) ? "_" : "#"); //todo : extract to CellView
        }
        std::cout << "\n";
    }
}
