//
// Created by Jakub Kiermasz on 2019-05-31.
//

#ifndef HEXADOKU_PLAYSTATEMODEL_HPP
#define HEXADOKU_PLAYSTATEMODEL_HPP

#include <iostream>
#include <memory>
#include <ctime>
#include "Model/Board.hpp"

class PlayStateModel {
public:
    explicit PlayStateModel(int boardSize);
    Board& GetBoard();
    std::string GetGameTimeString();
    void StartTimer();
    void SetSelected(bool isSelected, int column, int row);
    void SetValue(int value, int column, int row);
    int GetSize() const;
    int GetX() const;
    int GetY() const;
    void SetX(int x);
    void SetY(int y);
private:
    std::shared_ptr<std::time_t> creationTime;
    std::time_t gameTime;
    std::shared_ptr<Board> board;
    int x;
    int y;
};

#endif //HEXADOKU_PLAYSTATEMODEL_HPP
