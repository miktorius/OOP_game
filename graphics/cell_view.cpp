#include <iostream>
#include "cell_view.hpp"

void CellView::viewCurrentCell(Cell &cell) {
    if (cell.getEvent() == nullptr){
        std::cout << (cell.isPassable() ? "_ " : "# ");
    }
    else {
        std::cout << (cell.getEvent()->getSymbol()) << " ";
    }
    
}