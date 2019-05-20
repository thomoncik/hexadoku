
#include <GfxStream.hpp>
#include "View/CellView.hpp"

const char CellView::SYMBOLS[17] = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', '0'};


CellView::CellView(int value, int x, int y) : value(value), x(x), y(y) {

}


void CellView::Draw() {
    gfx::out << Color::White;
    gfx::out << Position(this->x, this->y) << CellView::SYMBOLS[this->value];
}
