//
// Created by Jakub Kiermasz on 2019-06-05.
//

#ifndef HEXADOKU_INSERTIONGAMEVIEW_HPP
#define HEXADOKU_INSERTIONGAMEVIEW_HPP

#include "AbstractGameView.hpp"

class InsertionGameView : public AbstractGameView {
public:
    explicit InsertionGameView(Board board, std::string gameTime);

private:
    void DrawMovementInfo(int x, int y) const override;

    void DrawActionsInfo(int x, int y) const override;

};

#endif //HEXADOKU_INSERTIONGAMEVIEW_HPP
