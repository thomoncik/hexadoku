//
// Created by Jakub Kiermasz on 2019-06-09.
//

#ifndef HEXADOKU_CONFIRMEXITGAMESTATE_HPP
#define HEXADOKU_CONFIRMEXITGAMESTATE_HPP

#include <Model/Board.hpp>
#include <State/Game/AbstractGameState.hpp>
#include <Model/Game.hpp>

class ConfirmExitGameState : public AbstractGameState {
public:
    explicit ConfirmExitGameState(bool wasInsertionEnabled, std::shared_ptr<Game> model);

    void HandleInput(StateContext &stateContext, char input) override;

    void Draw(StateContext &stateContext) override;
private:
    bool wasInsertionEnabled;
};


#endif //HEXADOKU_CONFIRMEXITGAMESTATE_HPP
