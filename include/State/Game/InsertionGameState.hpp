//
// Created by Jakub Kiermasz on 2019-05-25.
//

#ifndef HEXADOKU_INSERTIONGAMESTATE_HPP
#define HEXADOKU_INSERTIONGAMESTATE_HPP

#include <Model/Board.hpp>
#include <State/Game/AbstractGameState.hpp>
#include <Model/Game.hpp>

class InsertionGameState : public AbstractGameState {
public:
    explicit InsertionGameState(int boardSize);

    explicit InsertionGameState(std::shared_ptr<Game> model);

    void HandleInput(StateContext &stateContext, char input) override;
    
    void Draw(StateContext &stateContext) override;

private:
    std::vector<char> boardCharacters;
};


#endif //HEXADOKU_INSERTIONGAMESTATE_HPP
