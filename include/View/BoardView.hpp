#ifndef HEXADOKU_BOARDVIEW_HPP
#define HEXADOKU_BOARDVIEW_HPP

#include "AbstractView.hpp"

class BoardView : public AbstractView {
public:
    void Draw(int x, int y) override;
};

#endif //HEXADOKU_BOARDVIEW_HPP
