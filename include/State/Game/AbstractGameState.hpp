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

    explicit AbstractGameState(std::shared_ptr<Game> model);

    void OnEntry(StateContext &game) override;

    void Update(StateContext &game) override;

    void OnExit(StateContext &game) override;

protected:
    std::shared_ptr<Game> model;
};


#endif //HEXADOKU_ABSTRACTGAMESTATE_HPP
