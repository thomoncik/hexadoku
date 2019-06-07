//
// Created by Jakub Kiermasz on 2019-06-05.
//

#ifndef HEXADOKU_INSERTIONGAMEVIEW_HPP
#define HEXADOKU_INSERTIONGAMEVIEW_HPP

#include "GameViewAbstract.hpp"

class InsertionGameView : public GameViewAbstract {
public:
    explicit InsertionGameView(Board board, std::string gameTime);

private:
    void DrawMovementInfo(int x, int y) const;

    void DrawActionsInfo(int x, int y) const;

};

#endif //HEXADOKU_INSERTIONGAMEVIEW_HPP
