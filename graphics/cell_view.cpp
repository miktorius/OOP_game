#include <iostream>
#include "cell_view.hpp"

void CellView::viewCurrentCell(const Cell &cell) {
    std::cout << (cell.isPassable() ? "▪ " : "■ "); //todo : extract to CellView
}