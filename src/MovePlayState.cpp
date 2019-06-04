#include <MovePlayState.hpp>
#include <Menu/MainMenuState.hpp>
#include "InsertionPlayState.hpp"

MovePlayState::MovePlayState(int boardSize, std::shared_ptr<Board> board, int x, int y) : PlayStateAbstract(boardSize, board, x, y) {}

void MovePlayState::HandleInput(Game &game, char input) {
    board->SetSelected(false, x, y);

    if (input == 'q') {
        game.SetState(std::make_shared<MainMenuState>());
    } else if (input == 'l') {
        x = (x + 1) % board->GetSize();
    } else if (input == 'h') {
        x = (x == 0) ? board->GetSize() - 1 : x - 1;
    } else if (input == 'j') {
        y = (y + 1) % board->GetSize();
    } else if (input == 'k') {
        y = (y == 0) ? board->GetSize() - 1 : y - 1;
    } else if (input == 'm') {
        game.SetState(std::make_shared<InsertionPlayState>(board->GetSize(), board, x, y));
    }
    board->SetSelected(true, x, y);
}