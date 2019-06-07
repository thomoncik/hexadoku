//
// Created by thomoncik on 09.05.19.
//

#ifndef HEXADOKU_MOVEGAMESTATE_HPP
#define HEXADOKU_MOVEGAMESTATE_HPP

#include <Model/Board.hpp>
#include <Model/Game.hpp>
#include <State/Game/AbstractGameState.hpp>

class MoveGameState : public AbstractGameState {
public:
    explicit MoveGameState(int boardSize);

    explicit MoveGameState(std::shared_ptr<Board> board);

    explicit MoveGameState(std::shared_ptr<Game> model);

    void HandleInput(StateContext &game, char input) override;

    void Draw(StateContext &game) override;

};


#endif //HEXADOKU_MOVEGAMESTATE_HPP
