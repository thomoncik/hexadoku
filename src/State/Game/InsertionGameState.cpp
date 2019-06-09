//
// Created by Jakub Kiermasz on 2019-05-25.
//

#include <utility>
#include <cstddef>
#include <algorithm>
#include <State/Game/MoveGameState.hpp>
#include <State/Game/InsertionGameState.hpp>
#include <State/Menu/MainMenuState.hpp>
#include <View/Game/InsertionGameView.hpp>
#include <State/Game/SaveGameState.hpp>

InsertionGameState::InsertionGameState(int boardSize) : AbstractGameState(boardSize) {
    boardCharacters = (boardSize == Board::STANDARD_SIZE) ?
                      std::vector<char>{' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'} :
                      std::vector<char>{' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', '0'};
}

InsertionGameState::InsertionGameState(std::shared_ptr<Game> model) : AbstractGameState(std::move(model)) {
    boardCharacters = (this->game->GetSize() == Board::STANDARD_SIZE) ?
                      std::vector<char>{' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'} :
                      std::vector<char>{' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', '0'};
}

void InsertionGameState::HandleInput(StateContext &stateContext, char input) {
    game->SetSelected(false, game->GetX(), game->GetY());
    if (std::find(boardCharacters.begin(), boardCharacters.end(), input) != boardCharacters.end()) {
        auto value = distance(boardCharacters.begin(), find(boardCharacters.begin(), boardCharacters.end(), input));
        game->SetValue(value, game->GetX(), game->GetY());
        game->Validate(game->GetX(), game->GetY());
    }
    game->SetSelected(true, game->GetX(), game->GetY());

    if (input == '?') {
        game->MakeHint();
    } else if (input == 'q') {
        stateContext.SetState(std::make_shared<MainMenuState>());
    } else if (input == 'i') {
        stateContext.SetState(std::make_shared<MoveGameState>(std::move(game)));
    } else if (input == 's') {
        stateContext.SetState(std::make_shared<SaveGameState>(std::move(game)));
    }
}

void InsertionGameState::Draw(StateContext &stateContext) {
    InsertionGameView gameView(*game->GetBoard().get(), game->GetGameTimeString());
    gameView.Draw();
}
