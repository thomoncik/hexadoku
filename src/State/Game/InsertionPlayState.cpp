//
// Created by Jakub Kiermasz on 2019-05-25.
//

#include <utility>
#include <cstddef>
#include <algorithm>
#include <State/Game/MovePlayState.hpp>
#include <State/Game/InsertionPlayState.hpp>
#include <State/Menu/MainMenuState.hpp>
#include <View/Game/InsertionGameView.hpp>

InsertionPlayState::InsertionPlayState(int boardSize) : PlayStateAbstract(boardSize) {
    boardCharacters = (boardSize == Board::STANDARD_SIZE) ?
                      std::vector<char>{' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'} :
                      std::vector<char>{' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', '0'};
}

InsertionPlayState::InsertionPlayState(std::shared_ptr<PlayStateModel> model) : PlayStateAbstract(std::move(model)) {
    boardCharacters = (this->model->GetSize() == Board::STANDARD_SIZE) ?
                      std::vector<char>{' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'} :
                      std::vector<char>{' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', '0'};
}

void InsertionPlayState::HandleInput(Game &game, char input) {
    model->SetSelected(false, model->GetX(), model->GetY());
    if (std::find(boardCharacters.begin(), boardCharacters.end(), input) != boardCharacters.end()) {
        auto value = distance(boardCharacters.begin(), find(boardCharacters.begin(), boardCharacters.end(), input));
        model->SetValue(value, model->GetX(), model->GetY());
        model->SetIsCorrect(model->IsCorrect(model->GetX(), model->GetY()), model->GetX(), model->GetY());
    }
    model->SetSelected(true, model->GetX(), model->GetY());
    if (input == '?') {
        model->MakeHint();
    } else if (input == 'q') {
        game.SetState(std::make_shared<MainMenuState>());
    } else if (input == 'm') {
        game.SetState(std::make_shared<MovePlayState>(std::move(model)));
    }
}

void InsertionPlayState::Draw(Game &game) {
    InsertionGameView gameView(model->GetBoard(), model->GetGameTimeString());
    gameView.Draw();
}
