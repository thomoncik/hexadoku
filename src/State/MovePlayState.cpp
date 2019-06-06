#include <utility>

#include <State/MovePlayState.hpp>
#include <State/Menu/MainMenuState.hpp>
#include "State/InsertionPlayState.hpp"

MovePlayState::MovePlayState(int boardSize, std::shared_ptr<Board> board, int x, int y) : PlayStateAbstract(boardSize, std::move(board), x, y) {}

void MovePlayState::HandleInput(Game &game, char input) {
    board->SetSelected(false, x, y);
    if (input == 'l') {
        x = (x + 1) % board->GetSize();
    } else if (input == 'h') {
        x = (x == 0) ? board->GetSize() - 1 : x - 1;
    } else if (input == 'j') {
        y = (y + 1) % board->GetSize();
    } else if (input == 'k') {
        y = (y == 0) ? board->GetSize() - 1 : y - 1;
    }
    board->SetSelected(true, x, y);

    if (input == 'q') {
        game.SetState(std::make_shared<MainMenuState>());
    } else if (input == 'm') {
        game.SetState(std::make_shared<InsertionPlayState>(board->GetSize(), std::move(board), x, y));
    }
}