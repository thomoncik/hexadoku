#ifndef HEXADOKU_BOARDVIEW_HPP
#define HEXADOKU_BOARDVIEW_HPP

#include "AbstractView.hpp"
#include <vector>

class BoardView : public AbstractView {
public:
    explicit BoardView(int size, std::vector<std::vector<int>> values, int x = 0, int y = 0);

    void Draw() override;

private:
    std::vector<std::vector<int>> values;
    int size;
    int x;
    int y;

    void DrawBorder();

    void DrawVerticalLinesBorder();

    void DrawHorizontalLinesBorder();

    void DrawTopHorizontalLineBorder();

    void DrawMiddleHorizontalLineBorder();

    void DrawBottomHorizontalLineBorder();
};

#endif //HEXADOKU_BOARDVIEW_HPP
