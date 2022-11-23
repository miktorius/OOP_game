#include <iostream>
#include "cell_view.hpp"

void CellView::viewCurrentCell(Cell &cell) {
    if (cell.getEvent() == nullptr){
        std::cout << (cell.isPassable() ? "_ " : "# ");
    }
    else {
        switch (cell.getType()){
            case eventType::HURT:
                std::cout << "~ ";
                break;
            case eventType::HEAL:
                std::cout << "@ ";
                break;
            case eventType::GETWEIGHT:
                std::cout << "+ ";
                break;
            case eventType::LOSEWEIGHT:
                std::cout << "- ";
                break;
            case eventType::TRAP:
                std::cout << "? ";
                break;
            case eventType::VICTORY:
                std::cout << "$ ";
                break;
            case eventType::DEFEAT:
                std::cout << "! ";
                break;
        }
    }
}