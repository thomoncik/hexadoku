#include <memory>
#include <chrono>
#include <cmath>
#include <PlayState.hpp>
#include <GfxStream.hpp>
#include <MenuState.hpp>
#include <View/GameView.hpp>

PlayState::PlayState(int boardSize) : board(Board(boardSize)), x(0), y(0) {
    creationTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    gameTime = creationTime;
}

void PlayState::OnEntry(Game &game) {
    gfx::out << gfx::clear;
}

void PlayState::Update(Game &game) {
    gameTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) - creationTime;
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
    GameView gameView(this->board, GetGameTimeString());
    gameView.Draw();
}

void PlayState::OnExit(Game &game) {

}

std::string PlayState::GetGameTimeString() const {
    char buf[50];
    std::strftime(buf, sizeof(buf), "%M:%S", localtime(&gameTime));
    return std::string(buf);
}
