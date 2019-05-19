#include <GfxStream.hpp>
#include <View/SectionView.hpp>
#include <View/CellView.hpp>

SectionView::SectionView(int size, int x, int y) : size(size), x(x), y(y) {

}

void SectionView::Draw() {
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
            CellView(' ', this->x + 2 * i, this->y + 2 * j).Draw();
        }
    }
}
