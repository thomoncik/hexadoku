//
// Created by Jakub Kiermasz on 2019-05-31.
//

#include "Model/PlayStateModel.hpp"
#include <chrono>
#include <algorithm>

PlayStateModel::PlayStateModel(int boardSize) : board(std::make_shared<Board>(boardSize)) {

}

PlayStateModel::PlayStateModel(std::shared_ptr<Board> board) : board(std::move(board)) {

}

void PlayStateModel::StartTimer() {
    if (creationTime == nullptr) {
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

bool PlayStateModel::IsCorrect(int column, int row) const {
    int value = this->board->GetValue(column, row);
    std::vector<int> columnValues = this->board->GetValuesInColumn(column);
    std::vector<int> rowValues = this->board->GetValuesInRow(row);
    if (std::count(columnValues.begin(), columnValues.end(), value) > 1) {
        return false;
    }
    return std::count(rowValues.begin(), rowValues.end(), value) <= 1;
}

void PlayStateModel::SetIsCorrect(bool isCorrect, int column, int row) {
    this->board->SetIsCorrect(isCorrect, column, row);
}

void PlayStateModel::MakeHint() {
    if (!board->IsFilled()) {
        auto hint = board->GetHint();
        board->SetValue(hint.GetValue(), hint.GetColumn(), hint.GetRow());
        board->SetSelected(false, x, y);
        x = hint.GetColumn();
        y = hint.GetRow();
        SetSelected(true, x, y);
    }
}
