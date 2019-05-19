#ifndef HEXADOKU_CELLVIEW_HPP
#define HEXADOKU_CELLVIEW_HPP

#include "AbstractView.hpp"

class CellView : public AbstractView {
public:
    explicit CellView(char value, int x, int y);

    void Draw() override;

private:
    int x;
    int y;
    char value;
};

#endif //HEXADOKU_CELLVIEW_HPP
