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

InsertionGameState::InsertionGameState(int boardSize) : AbstractGameState(boardSize) {
    boardCharacters = (boardSize == Board::STANDARD_SIZE) ?
                      std::vector<char>{' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'} :
                      std::vector<char>{' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', '0'};
}

InsertionGameState::InsertionGameState(std::shared_ptr<Game> model) : AbstractGameState(std::move(model)) {
    boardCharacters = (this->model->GetSize() == Board::STANDARD_SIZE) ?
                      std::vector<char>{' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'} :
                      std::vector<char>{' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', '0'};
}

void InsertionGameState::HandleInput(StateContext &game, char input) {
    model->SetSelected(false, model->GetX(), model->GetY());
    if (std::find(boardCharacters.begin(), boardCharacters.end(), input) != boardCharacters.end()) {
        auto value = distance(boardCharacters.begin(), find(boardCharacters.begin(), boardCharacters.end(), input));
        model->SetValue(value, model->GetX(), model->GetY());
    }
    model->SetSelected(true, model->GetX(), model->GetY());

    if (input == 'q') {
        game.SetState(std::make_shared<MainMenuState>());
    } else if (input == 'm') {
        game.SetState(std::make_shared<MoveGameState>(std::move(model)));
    }
}

void InsertionGameState::Draw(StateContext &game) {
    InsertionGameView gameView(model->GetBoard(), model->GetGameTimeString());
    gameView.Draw();
}
