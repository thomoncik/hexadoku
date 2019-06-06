//
// Created by Jakub Kiermasz on 2019-06-05.
//

#ifndef HEXADOKU_MOVEGAMEVIEW_HPP
#define HEXADOKU_MOVEGAMEVIEW_HPP

#include "GameViewAbstract.hpp"

class MoveGameView : public GameViewAbstract {
public:
    explicit MoveGameView(Board board, std::string gameTime);

private:
    void DrawMovementInfo(int x, int y) const;

    void DrawActionsInfo(int x, int y) const;

};

#endif //HEXADOKU_MOVEGAMEVIEW_HPP
