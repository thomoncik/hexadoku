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
    this->board.SetValue(5, x, y);
}

void PlayState::Update(Game &game) {

}

void PlayState::HandleInput(Game &game, char input) {
    if (input == 'q') {
        game.SetState(MenuState::MAIN_MENU);
    } else if (input == 'l') {
        this->board.SetValue(0, x, y);
        x = (x + 1) % this->board.GetSize();
        this->board.SetValue(5, x, y);
    } else if (input == 'h') {
        this->board.SetValue(0, x, y);
        x--;
        if (x < 0) {
            x = this->board.GetSize() - 1;
        }
        this->board.SetValue(5, x, y);
    } else if (input == 'j') {
        this->board.SetValue(0, x, y);
        y = (y + 1) % this->board.GetSize();
        this->board.SetValue(5, x, y);
    } else if (input == 'k') {
        this->board.SetValue(0, x, y);
        y--;
        if (y < 0) {
            y = this->board.GetSize() - 1;
        }
        this->board.SetValue(5, x, y);
    }
}

void PlayState::Draw(Game &game) {
    const int BOARD_X = 2;
    const int BOARD_Y = 2;

    BoardView((int) sqrt(this->board.GetSize()), this->board.GetValues(), BOARD_X, BOARD_Y).Draw();
}

void PlayState::OnExit(Game &game) {

}