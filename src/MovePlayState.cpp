#include <MovePlayState.hpp>
#include <MenuState.hpp>
#include "InsertionPlayState.hpp"
#include "View/MoveGameView.hpp"

MovePlayState::MovePlayState(int boardSize, std::shared_ptr<Board> board, int x, int y) : PlayStateAbstract(boardSize, board, x, y) {}

void MovePlayState::HandleInput(Game &game, char input) {
    board->SetSelected(false, x, y);

    if (input == 'q') {
        game.SetState(MenuState::MAIN_MENU);
    } else if (input == 'l') {
        this->x = (this->x + 1) % this->board->GetSize();
    } else if (input == 'h') {
        this->x = (this->x == 0) ? this->board->GetSize() - 1 : this->x - 1;
    } else if (input == 'j') {
        this->y = (this->y + 1) % this->board->GetSize();
    } else if (input == 'k') {
        this->y = (this->y == 0) ? this->board->GetSize() - 1 : this->y - 1;
    } else if (input == 'm') {
        game.SetState(new InsertionPlayState(this->board->GetSize(), this->board, this->x, this->y));
    }
    this->board->SetSelected(true, x, y);
}

void MovePlayState::Draw(Game &game) {
    MoveGameView gameView(*this->board, GetGameTimeString());
    gameView.Draw();
}