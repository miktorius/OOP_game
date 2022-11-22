#include "field_view.hpp"
#include "../map/field.hpp"
#include "../utils/vector2i.hpp"
#include "cell_view.hpp"

#include <iostream>

void FieldView::drawField(const Field &field, Vector2i playerPosition, const Player& player) {
    CellView viewCell;
    system("cls");
    for(int i = 0; i < field.getSize().y; i++) {
        for(int j = 0; j < field.getSize().x; j++) {
            if (playerPosition.x == j && playerPosition.y == i) {
                std::cout << "P ";
                //field.getMap()[j][i].detectPlayer();
            }
            else 
                viewCell.viewCurrentCell(field.getMap()[i][j]);
        }
        std::cout << "\n";
    }
    std::cout << "\nHP : " << player.getHP() 
              << "\nWeight : " << player.getWeight()  
              << "\nInput : ";

    // for(int i = 0; i < field.getSize().y; i++) {
    //     for(int j = 0; j < field.getSize().x; j++) {
    //         std::cout << (field.getMap()[j][i].isPlayerDetected() ? "1 " : "0 ");
    //     }
    //     std::cout << "\n";
    // }
}
