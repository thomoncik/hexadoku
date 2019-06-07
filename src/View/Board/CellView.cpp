
#include <Graphics/GfxStream.hpp>
#include <Graphics/Attributes.hpp>
#include "View/Board/CellView.hpp"

const char CellView::SYMBOLS[] = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', '0'};


CellView::CellView(BoardCell boardCell) : cell(boardCell) {

}


void CellView::Draw() const {
    gfx::out << gfx::nodecor << Color::White << Position(this->x, this->y);
    if (this->cell.IsSelected()) {
        gfx::out << Attribute::BLINKING << Attribute::STANDOUT;
    }
    gfx::out << CellView::SYMBOLS[this->cell.GetValue()] << gfx::nodecor;
}
