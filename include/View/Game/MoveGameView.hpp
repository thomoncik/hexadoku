//
// Created by Jakub Kiermasz on 2019-06-05.
//

#ifndef HEXADOKU_MOVEGAMEVIEW_HPP
#define HEXADOKU_MOVEGAMEVIEW_HPP

#include "AbstractGameView.hpp"

class MoveGameView : public AbstractGameView {
public:
    explicit MoveGameView(Board board, std::string gameTime);

private:
    void DrawMovementInfo(int x, int y) const override;

    void DrawActionsInfo(int x, int y) const override;

};

#endif //HEXADOKU_MOVEGAMEVIEW_HPP
