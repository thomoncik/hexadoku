#ifndef HEXADOKU_BOARDVIEW_HPP
#define HEXADOKU_BOARDVIEW_HPP

#include "AbstractView.hpp"
#include <vector>

class BoardView : public AbstractView {
public:
    explicit BoardView(int size, std::vector<std::vector<int>> values, int xSelected, int ySelected, int x = 0,
                       int y = 0);

    void Draw() const override;

private:
    std::vector<std::vector<int>> values;
    int xSelected;
    int ySelected;
    int size;
    int x;
    int y;

    void DrawBorder() const;

    void DrawVerticalLinesBorder() const;

    void DrawHorizontalLinesBorder() const;

    void DrawTopHorizontalLineBorder() const;

    void DrawMiddleHorizontalLineBorder() const;

    void DrawBottomHorizontalLineBorder() const;
};

#endif //HEXADOKU_BOARDVIEW_HPP
