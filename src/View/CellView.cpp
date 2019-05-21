
#include <GfxStream.hpp>
#include <Attributes.hpp>
#include "View/CellView.hpp"

const char CellView::SYMBOLS[] = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', '0'};


CellView::CellView(int value, int x, int y) : value(value), x(x), y(y), selected(false) {

}


void CellView::Draw() const {
    gfx::out << gfx::nodecor << Color::White << Position(this->x, this->y);
    if (this->selected) {
        gfx::out << Attribute::BLINKING << Attribute::STANDOUT;
    }
    gfx::out << CellView::SYMBOLS[this->value] << gfx::nodecor;
}

void CellView::SetSelected() {
    this->selected = true;
}
