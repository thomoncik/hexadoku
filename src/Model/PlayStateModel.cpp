//
// Created by Jakub Kiermasz on 2019-05-31.
//

#include "Model/PlayStateModel.hpp"
#include <chrono>

PlayStateModel::PlayStateModel(int boardSize) {
    this->board = std::make_shared<Board>(boardSize);
}

void PlayStateModel::StartTimer() {
    if (!creationTime) {
        creationTime = std::make_shared<std::time_t>(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
        gameTime = *creationTime;
    }
}

Board& PlayStateModel::GetBoard() {
    return *board.get();
}

std::string PlayStateModel::GetGameTimeString() {
    this->gameTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) - *creationTime;
    char buf[50];
    std::strftime(buf, sizeof(buf), "%M:%S", localtime(&gameTime));
    return std::string(buf);
}

void PlayStateModel::SetSelected(bool isSelected, int column, int row) {
    this->board->SetSelected(isSelected, column, row);
}

void PlayStateModel::SetValue(int value, int column, int row) {
    this->board->SetValue(value, column, row);
}

int PlayStateModel::GetSize() const {
    return this->board->GetSize();
}

int PlayStateModel::GetX() const {
    return x;
}

int PlayStateModel::GetY() const {
    return y;
}

void PlayStateModel::SetX(int x) {
    this->x = x;
}

void PlayStateModel::SetY(int y) {
    this->y = y;
}