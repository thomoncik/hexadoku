#include <cmath>

#include <PlayState.hpp>
#include <GfxStream.hpp>
#include <MenuState.hpp>
#include <View/BoardView.hpp>
#include "View/SectionView.hpp"

PlayState::PlayState(int boardSize) : board(Board(boardSize)) {

}

void PlayState::OnEntry(Game &game) {
    gfx::out << gfx::clear;
}

void PlayState::Update(Game &game) {

}

void PlayState::HandleInput(Game &game, char input) {
    if (input == 'q') {
        game.SetState(MenuState::MAIN_MENU);
    }
}

void PlayState::Draw(Game &game) {
    const int BOARD_X = 2;
    const int BOARD_Y = 2;

    BoardView((int) sqrt(this->board.GetSize()), BOARD_X, BOARD_Y).Draw();
}

void PlayState::OnExit(Game &game) {

}