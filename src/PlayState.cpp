#include <cmath>

#include <PlayState.hpp>
#include <GfxStream.hpp>
#include <MenuState.hpp>
#include <View/BoardView.hpp>
#include "View/SectionView.hpp"

PlayState::PlayState(int boardSize) : board(Board(boardSize)), x(0), y(0) {

}

void PlayState::OnEntry(Game &game) {
    gfx::out << gfx::clear;
}

void PlayState::Update(Game &game) {

}

void PlayState::HandleInput(Game &game, char input) {
    this->board.SetSelected(false, x, y);

    if (input == 'q') {
        game.SetState(MenuState::MAIN_MENU);
    } else if (input == 'l') {
        this->x = (this->x + 1) % this->board.GetSize();
    } else if (input == 'h') {
        this->x = (this->x == 0) ? this->board.GetSize() - 1 : this->x - 1;
    } else if (input == 'j') {
        this->y = (this->y + 1) % this->board.GetSize();
    } else if (input == 'k') {
        this->y = (this->y == 0) ? this->board.GetSize() - 1 : this->y - 1;
    }

    this->board.SetSelected(true, x, y);
}

void PlayState::Draw(Game &game) {
    const int BOARD_X = 2;
    const int BOARD_Y = 2;

    BoardView((int) sqrt(this->board.GetSize()), this->board.GetValues(), this->x, this->y, BOARD_X, BOARD_Y).Draw();
}

void PlayState::OnExit(Game &game) {

}