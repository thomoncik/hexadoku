#include <utility>

#include <GfxStream.hpp>
#include <View/SectionView.hpp>
#include <View/CellView.hpp>
#include <cmath>

SectionView::SectionView(BoardSection boardSection) : section(std::move(boardSection)) {
    this->size = (int) sqrt(this->section.GetSize());
}

void SectionView::Draw() const {
    this->DrawGrid();

    for (int j = 0; j < this->size; ++j) {
        for (int i = 0; i < this->size; ++i) {
            int cellX = this->x + 4 * i + 1;
            int cellY = this->y + 2 * j;

            CellView cellView(this->section.GetCell(i, j));
            cellView.SetPosition(cellX, cellY);
            cellView.Draw();
        }
    }
}

void SectionView::DrawGrid() const {
    gfx::out << gfx::nodecor << Color::Blue;
    for (int i = 0; i < this->size - 1; ++i) {
        gfx::out << Position(this->x, this->y + 1 + 2 * i) << std::wstring(this->size * 4 - 1, '-');
    }

    for (int i = 0; i < this->size - 1; ++i) {
        for (int j = 0; j < 2 * this->size - 1; ++j) {
            gfx::out << Position(this->x + 3 + 4 * i, this->y + j) << "|";
        }
    }
    gfx::out << gfx::nodecor;
}
