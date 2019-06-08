#ifndef HEXADOKU_BOARDVIEW_HPP
#define HEXADOKU_BOARDVIEW_HPP

#include "View/AbstractView.hpp"
#include <vector>
#include <Model/Board.hpp>

class BoardView : public AbstractView {
public:
    explicit BoardView(Board board);

    void Draw() const override;

private:
    Board board;
    int size;

    void DrawBorder() const;

    void DrawVerticalLinesBorder() const;

    void DrawHorizontalLinesBorder() const;

    void DrawTopHorizontalLineBorder() const;

    void DrawMiddleHorizontalLineBorder() const;

    void DrawBottomHorizontalLineBorder() const;
};

#endif //HEXADOKU_BOARDVIEW_HPP
