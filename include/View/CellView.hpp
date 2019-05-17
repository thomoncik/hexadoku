#ifndef HEXADOKU_CELLVIEW_HPP
#define HEXADOKU_CELLVIEW_HPP

#include "AbstractView.hpp"

class CellView : public AbstractView {
public:
    explicit CellView(int value);

    void Draw(int x, int y);

private:
    int value;
};

#endif //HEXADOKU_CELLVIEW_HPP
