#include <utility>

#include <utility>

#include <GfxStream.hpp>
#include <View/SectionView.hpp>
#include <Attributes.hpp>
#include "View/BoardView.hpp"

BoardView::BoardView(int size, std::vector<std::vector<int>> values, int xSelected, int ySelected, int x, int y)
        : size(size), values(std::move(values)), xSelected(xSelected), ySelected(ySelected), x(x), y(y) {

}

void BoardView::Draw() const {
    gfx::out << Attribute::BOLD << Color::Blue;
    this->DrawBorder();

    for (int j = 0; j < this->size; ++j) {
        for (int i = 0; i < this->size; ++i) {
            int sectionX = this->x + 2 * this->size * i + 1;
            int sectionY = this->y + 2 * this->size * j + 1;
            std::vector<int> sectionValues = this->values[i + this->size * j];

            SectionView sectionView(this->size, sectionValues, sectionX, sectionY);
            if (this->ySelected / this->size * this->size + this->xSelected / this->size == i + this->size * j) {
                int selectedXInSection = this->xSelected % this->size;
                int selectedYInSection = this->ySelected % this->size;
                sectionView.SetSelected(selectedXInSection, selectedYInSection);
            }
            sectionView.Draw();
        }
    }

    gfx::out << gfx::nodecor;
}

void BoardView::DrawBorder() const{
    this->DrawVerticalLinesBorder();
    this->DrawHorizontalLinesBorder();
}

void BoardView::DrawHorizontalLinesBorder() const {
    this->DrawTopHorizontalLineBorder();
    this->DrawMiddleHorizontalLineBorder();
    this->DrawBottomHorizontalLineBorder();
}

void BoardView::DrawVerticalLinesBorder() const {
    for (int i = 0; i <= this->size; ++i) {
        for (int j = 0; j <= 2 * this->size * this->size; ++j) {
            gfx::out << Position(this->x + 2 * this->size * i, this->y + j) << gfx::box::vln;
        }
    }
}

void BoardView::DrawTopHorizontalLineBorder() const {
    gfx::out << Attribute::BOLD << Color::Blue << Position(x, y);
    gfx::out << gfx::box::ulcorner;
    for (int i = 1; i < 2 * this->size * this->size; ++i) {
        gfx::out << gfx::box::hln;
    }
    gfx::out << gfx::box::urcorner;

    for (int i = 1; i < this->size; ++i) {
        gfx::out << Position(x + 2 * this->size * i, y) << gfx::box::ttee;
    }
}

void BoardView::DrawMiddleHorizontalLineBorder() const {
    for (int j = 1; j < this->size; ++j) {
        gfx::out << Position(x, y + 2 * this->size * j);
        gfx::out << gfx::box::ltee;
        for (int i = 1; i < 2 * this->size * this->size; ++i) {
            gfx::out << gfx::box::hln;
        }
        gfx::out << gfx::box::rtee;
        for (int i = 1; i < this->size; ++i) {
            gfx::out << Position(x + 2 * this->size * i, y + 2 * this->size * j) << gfx::box::plus;
        }
    }
}

void BoardView::DrawBottomHorizontalLineBorder() const {
    gfx::out << Position(x, y + 2 * this->size * this->size);
    gfx::out << gfx::box::llcorner;
    for (int i = 1; i < 2 * this->size * this->size; ++i) {
        gfx::out << gfx::box::hln;
    }
    gfx::out << gfx::box::lrcorner;

    for (int i = 1; i < this->size; ++i) {
        gfx::out << Position(x + 2 * this->size * i, y + 2 * this->size * this->size) << gfx::box::btee;
    }
}
