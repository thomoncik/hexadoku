#include <GfxStream.hpp>
#include <View/SectionView.hpp>
#include <Attributes.hpp>
#include "View/BoardView.hpp"

BoardView::BoardView(int size, int x, int y) : size(size), x(x), y(y) {

}

void BoardView::Draw() {
    gfx::out << Attribute::BOLD << Color::Blue;
    this->DrawBorder();

    for (int j = 0; j < this->size; ++j) {
        for (int i = 0; i < this->size; ++i) {
            SectionView(this->size, 1 + this->x + 2 * this->size * i, 1 + this->y + 2 * this->size * j).Draw();
        }
    }
}

void BoardView::DrawBorder() {
    this->DrawVerticalLinesBorder();
    this->DrawHorizontalLinesBorder();
}

void BoardView::DrawHorizontalLinesBorder() {
    this->DrawTopHorizontalLineBorder();
    this->DrawMiddleHorizontalLineBorder();
    this->DrawBottomHorizontalLineBorder();
}

void BoardView::DrawVerticalLinesBorder() {
    for (int i = 0; i <= this->size; ++i) {
        for (int j = 0; j <= 2 * this->size * this->size; ++j) {
            gfx::out << Position(this->x + 2 * this->size * i, this->y + j) << gfx::box::vln;
        }
    }
}

void BoardView::DrawTopHorizontalLineBorder() {
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

void BoardView::DrawMiddleHorizontalLineBorder() {
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

void BoardView::DrawBottomHorizontalLineBorder() {
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
