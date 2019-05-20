#ifndef HEXADOKU_CELLVIEW_HPP
#define HEXADOKU_CELLVIEW_HPP

#include "AbstractView.hpp"

class CellView : public AbstractView {
public:
    static const char SYMBOLS[17];

    explicit CellView(int value, int x, int y);

    void Draw() override;

private:
    int x;
    int y;
    int value;
};

#endif //HEXADOKU_CELLVIEW_HPP
