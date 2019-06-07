//
// Created by Jakub Kiermasz on 2019-05-31.
//

#ifndef HEXADOKU_GAME_HPP
#define HEXADOKU_GAME_HPP

#include <iostream>
#include <fstream>
#include <memory>
#include <ctime>
#include <chrono>
#include "Model/Board.hpp"

class Game {
public:
    static const std::string SAVED_STANDARD_GAME_PATH;
    static const std::string SAVED_HEXADOKU_GAME_PATH;
    static const std::string SAVED_GAME_FILE_EXTENSION;

    explicit Game(int boardSize);

    explicit Game(std::shared_ptr<Board> board);

    std::shared_ptr<Board> GetBoard() const;

    std::string GetGameTimeString();

    void StartTimer();

    void SetSelected(bool isSelected, int column, int row);

    void SetValue(int value, int column, int row);

    int GetSize() const;

    int GetX() const;

    int GetY() const;

    void SetX(int x);

    void SetY(int y);

    void LoadFromStream(std::istream &stream);

    void SaveToStream(std::ostream &stream) const;

    void LoadFromFile(const std::string &filename);

    void SaveToFile(const std::string &filename) const;

private:
    std::shared_ptr<std::chrono::steady_clock::time_point> creationTime;
    std::time_t gameTime{};
    std::shared_ptr<Board> board;
    int x{};
    int y{};
};

#endif //HEXADOKU_GAME_HPP
