//
// Created by thomoncik on 09.05.19.
//

#ifndef HEXADOKU_PLAYSTATE_HPP
#define HEXADOKU_PLAYSTATE_HPP

#include "AbstractState.hpp"
#include "Model/Board.hpp"


class PlayState : public AbstractState {
public:
    explicit PlayState(int boardSize);

    void OnEntry(Game &game) override;

    void Update(Game &game) override;

    void HandleInput(Game &game, char input) override;

    void Draw(Game &game) override;

    void OnExit(Game &game) override;

private:
    Board board;
    int x;
    int y;
};


#endif //HEXADOKU_PLAYSTATE_HPP
