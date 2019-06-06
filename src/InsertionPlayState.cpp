//
// Created by Jakub Kiermasz on 2019-05-25.
//

#include "InsertionPlayState.hpp"
#include <MenuState.hpp>
#include "MovePlayState.hpp"
#include <algorithm>
#include <cstddef>
#include "View/InsertionGameView.hpp"

InsertionPlayState::InsertionPlayState(int boardSize) : PlayStateAbstract(boardSize), boardCharacters(boardSize == Board::STANDARD_SIZE ?
                                                                                                                                  std::vector<char>{' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'} :
                                                                                                                                  std::vector<char>{' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e'}) {}

                            InsertionPlayState::InsertionPlayState(std::shared_ptr<PlayStateModel> model) : PlayStateAbstract(model), boardCharacters(model->GetSize() == Board::STANDARD_SIZE ?
                                                                                                                                                      std::vector<char>{' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'} :
                                                                                                                                                      std::vector<char>{' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e'}) {}

void InsertionPlayState::HandleInput(Game &game, char input) {
    model->SetSelected(false, model->GetX(), model->GetY());

    if (input == 'q') {
        game.SetState(MenuState::MAIN_MENU);
    } else if (input == 'm') {
        game.SetState(new MovePlayState(this->model));
    } else if (std::find(boardCharacters.begin(), boardCharacters.end(), input) != boardCharacters.end()) {
        ptrdiff_t value = distance(boardCharacters.begin(), find(boardCharacters.begin(), boardCharacters.end(), input));
        this->model->SetValue(value, model->GetX(), model->GetY());
    }
    this->model->SetSelected(true, model->GetX(), model->GetY());
}

void InsertionPlayState::Draw(Game &game) {
    InsertionGameView gameView(this->model->GetBoard(), this->model->GetGameTimeString());
    gameView.Draw();
}