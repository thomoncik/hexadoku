#include <View/SectionView.hpp>
#include <View/BoardView.hpp>
#include <Attributes.hpp>
#include <GfxStream.hpp>
#include <cmath>

BoardView::BoardView(Board board) : board(std::move(board)) {
    this->size = (int) sqrt(this->board.GetSize());
}

void BoardView::Draw() const {
    gfx::out << Attribute::BOLD << Color::Blue;
    this->DrawBorder();

    for (int j = 0; j < this->size; ++j) {
        for (int i = 0; i < this->size; ++i) {
            int sectionX = this->x + 2 * this->size * i + 1;
            int sectionY = this->y + 2 * this->size * j + 1;

            SectionView sectionView(this->board.GetSection(i + this->size * j));
            sectionView.SetPosition(sectionX, sectionY);
            sectionView.Draw();
        }
    }

    gfx::out << gfx::nodecor;
}

void BoardView::DrawBorder() const {
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
