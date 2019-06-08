#ifndef HEXADOKU_CELLVIEW_HPP
#define HEXADOKU_CELLVIEW_HPP

#include <Model/BoardCell.hpp>
#include "View/AbstractView.hpp"

class CellView : public AbstractView {
public:
    static const char SYMBOLS[17];

    explicit CellView(BoardCell boardCell);

    void Draw() const override;

private:
    BoardCell cell;
};

#endif //HEXADOKU_CELLVIEW_HPP
