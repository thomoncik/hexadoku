//
// Created by Jakub Kiermasz on 2019-06-09.
//

#ifndef HEXADOKU_CONFIRMEXITGAMEVIEW_HPP
#define HEXADOKU_CONFIRMEXITGAMEVIEW_HPP

#include "AbstractGameView.hpp"

class ConfirmExitGameView : public AbstractGameView {
public:
    explicit ConfirmExitGameView(Board board, std::string gameTime);

private:
    void DrawMovementInfo(int x, int y) const override;

    void DrawActionsInfo(int x, int y) const override;

};


#endif //HEXADOKU_CONFIRMEXITGAMEVIEW_HPP
