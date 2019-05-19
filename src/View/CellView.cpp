
#include <GfxStream.hpp>
#include "View/CellView.hpp"

CellView::CellView(char value, int x, int y) : value(value), x(x), y(y) {

}


void CellView::Draw() {
    gfx::out << Color::White;
    gfx::out << Position(this->x, this->y) << this->value;
}
