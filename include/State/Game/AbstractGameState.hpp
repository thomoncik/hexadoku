//
// Created by Jakub Kiermasz on 2019-05-25.
//

#ifndef HEXADOKU_ABSTRACTGAMESTATE_HPP
#define HEXADOKU_ABSTRACTGAMESTATE_HPP

#include <State/AbstractState.hpp>
#include <Model/Game.hpp>
#include <ctime>
#include <memory>

class AbstractGameState : public AbstractState {
public:
    explicit AbstractGameState(int boardSize);

    explicit AbstractGameState(std::shared_ptr<Board> board);

    explicit AbstractGameState(std::shared_ptr<Game> game);

    void OnEntry(StateContext &stateContext) override;

    void Update(StateContext &stateContext) override;

    void OnExit(StateContext &stateContext) override;

protected:
    std::shared_ptr<Game> game;
};


#endif //HEXADOKU_ABSTRACTGAMESTATE_HPP
