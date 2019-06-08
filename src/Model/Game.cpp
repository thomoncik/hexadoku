//
// Created by Jakub Kiermasz on 2019-05-31.
//

#include "Model/Game.hpp"
#include <chrono>
#include <algorithm>

const std::string Game::SAVED_STANDARD_GAME_PATH = std::string(std::getenv("HOME")) + "/.hexadoku/game/standard/";
const std::string Game::SAVED_HEXADOKU_GAME_PATH = std::string(std::getenv("HOME")) + "/.hexadoku/game/hexadoku/";
const std::string Game::SAVED_GAME_FILE_EXTENSION = ".sudk";

Game::Game(int boardSize) : board(std::make_shared<Board>(boardSize)) {

}

Game::Game(std::shared_ptr<Board> board) : board(std::move(board)) {

}

void Game::StartTimer() {
    if (creationTime == nullptr) {
        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
        creationTime = std::make_shared<std::chrono::steady_clock::time_point>(now);
    }
}

std::shared_ptr<Board> Game::GetBoard() const {
    return board;
}

std::string Game::GetGameTimeString() {
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    gameTime = std::chrono::duration_cast<std::chrono::seconds>(now - *creationTime).count();
    char buf[50];
    std::strftime(buf, sizeof(buf), "%M:%S", localtime(&gameTime));
    return std::string(buf);
}

void Game::SetSelected(bool isSelected, int column, int row) {
    this->board->SetSelected(isSelected, column, row);
}

void Game::SetValue(int value, int column, int row) {
    this->board->SetValue(value, column, row);
}

int Game::GetSize() const {
    return this->board->GetSize();
}

int Game::GetX() const {
    return x;
}

int Game::GetY() const {
    return y;
}

void Game::SetX(int x) {
    this->x = x;
}

void Game::SetY(int y) {
    this->y = y;
}

bool Game::IsCorrect(int column, int row) const {
    int value = board->GetValue(column, row);
    std::vector<int> columnValues = board->GetValuesInColumn(column);
    std::vector<int> rowValues = board->GetValuesInRow(row);
    if (std::count(columnValues.begin(), columnValues.end(), value) > 1) {
        return false;
    }
    return std::count(rowValues.begin(), rowValues.end(), value) <= 1;
}

void Game::SetIsCorrect(bool isCorrect, int column, int row) {
    board->SetIsCorrect(isCorrect, column, row);
}

void Game::MakeHint() {
    if (!board->IsFilled()) {
        auto hint = board->GetHint();
        board->SetValue(hint.GetValue(), hint.GetColumn(), hint.GetRow());
        board->SetSelected(false, x, y);
        x = hint.GetColumn();
        y = hint.GetRow();
        SetSelected(true, x, y);
    }
}

void Game::LoadFromStream(std::istream &stream) {
    int secondsPlayed;
    stream >> secondsPlayed;
    auto now = std::chrono::steady_clock::now();
    creationTime = std::make_shared<std::chrono::steady_clock::time_point>(now - std::chrono::seconds(secondsPlayed));

    board->LoadFromStream(stream);
}

void Game::SaveToStream(std::ostream &stream) const {
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    int secondsPlayed = std::chrono::duration_cast<std::chrono::seconds>(now - *creationTime).count();
    stream << secondsPlayed << " \n";
    board->SaveToStream(stream);
}

void Game::LoadFromFile(const std::string &filename) {
    std::ifstream fileStream;
    fileStream.open(filename);
    LoadFromStream(fileStream);
    fileStream.close();
}

void Game::SaveToFile(const std::string &filename) const {
    std::ofstream fileStream;
    fileStream.open(filename + Game::SAVED_GAME_FILE_EXTENSION);
    SaveToStream(fileStream);
    fileStream.close();
}

