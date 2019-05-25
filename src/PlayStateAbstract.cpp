//
// Created by Jakub Kiermasz on 2019-05-25.
//

#include <memory>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <PlayStateAbstract.hpp>
#include <GfxStream.hpp>
#include <MenuState.hpp>
#include <View/GameView.hpp>

PlayStateAbstract::PlayStateAbstract(int boardSize, std::shared_ptr<Board>board, int x, int y) : x(x), y(y) {
    this->board = (board == nullptr) ? std::shared_ptr<Board>(new Board(boardSize)) : std::move(board);
}

void PlayStateAbstract::OnEntry(Game &game) {
    creationTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    gameTime = creationTime;
    gfx::out << gfx::clear;
}

void PlayStateAbstract::Update(Game &game) {
    gameTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) - creationTime;
}

void PlayStateAbstract::Draw(Game &game) {
    GameView gameView(*this->board, GetGameTimeString());
    gameView.Draw();
}

void PlayStateAbstract::OnExit(Game &game) {

}

std::string PlayStateAbstract::GetGameTimeString() const {
    char buf[50];
    std::strftime(buf, sizeof(buf), "%M:%S", localtime(&gameTime));
    return std::string(buf);
}

