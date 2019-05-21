#ifndef HEXADOKU_GAMEVIEW_HPP
#define HEXADOKU_GAMEVIEW_HPP

#include <Model/Board.hpp>
#include "AbstractView.hpp"

class GameView : public AbstractView {
public:
    explicit GameView(Board board);

    void Draw() const override;

private:
    Board board;

    void DrawInfo() const;

    void DrawMovementInfo(int x, int y) const;

    void DrawActionsInfo(int x, int y) const;
};

#endif //HEXADOKU_GAMEVIEW_HPP
