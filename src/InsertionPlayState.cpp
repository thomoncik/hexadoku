//
// Created by Jakub Kiermasz on 2019-05-25.
//

#include "InsertionPlayState.hpp"
#include "MovePlayState.hpp"
#include <algorithm>
#include <cstddef>
#include <Menu/MainMenuState.hpp>

InsertionPlayState::InsertionPlayState(int boardSize, std::shared_ptr<Board> board, int x, int y) : PlayStateAbstract(boardSize, board, x, y), boardCharacters(boardSize == Board::STANDARD_SIZE ?
                            std::vector<char>{' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'} :
                            std::vector<char>{' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e'}) {}

void InsertionPlayState::HandleInput(Game &game, char input) {
    board->SetSelected(false, x, y);

    if (input == 'q') {
        game.SetState(std::make_shared<MainMenuState>());
    } else if (input == 'm') {
        game.SetState(std::make_shared<MovePlayState>(this->board->GetSize(), this->board, this->x, this->y));
    } else if (std::find(boardCharacters.begin(), boardCharacters.end(), input) != boardCharacters.end()) {
        ptrdiff_t value = distance(boardCharacters.begin(), find(boardCharacters.begin(), boardCharacters.end(), input));
        this->board->SetValue(value, x, y);
    }
    this->board->SetSelected(true, x, y);
}