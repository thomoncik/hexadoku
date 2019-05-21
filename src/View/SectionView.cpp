#include <GfxStream.hpp>
#include <View/SectionView.hpp>
#include <View/CellView.hpp>

SectionView::SectionView(int size, std::vector<int> values, int x, int y) : size(size), values(std::move(values)), x(x),
                                                                            y(y) {

}

void SectionView::Draw() const {
    gfx::out << gfx::nodecor;
    gfx::out << Color::Blue;
    for (int i = 0; i < this->size - 1; ++i) {
        gfx::out << Position(this->x, this->y + 1 + 2 * i) << std::wstring(this->size * 2 - 1, '-');
    }

    for (int i = 0; i < this->size - 1; ++i) {
        for (int j = 0; j < 2 * this->size - 1; ++j) {
            gfx::out << Position(this->x + 1 + 2 * i, this->y + j) << "|";
        }
    }

    for (int j = 0; j < this->size; ++j) {
        for (int i = 0; i < this->size; ++i) {
            int cellValue = this->values.at(i + j * this->size);
            int cellX = this->x + 2 * i;
            int cellY = this->y + 2 * j;

            CellView cellView(cellValue, cellX, cellY);
            if (this->selectedX == i && this->selectedY == j) {
                cellView.SetSelected();
            }
            cellView.Draw();
        }
    }

    gfx::out << gfx::nodecor;
}

void SectionView::SetSelected(int x, int y) {
    this->selectedX = x;
    this->selectedY = y;
}
