//
// Created by Jakub Kiermasz on 2019-05-25.
//

#ifndef HEXADOKU_PLAYSTATEABSTRACT_HPP
#define HEXADOKU_PLAYSTATEABSTRACT_HPP

#include "State/AbstractState.hpp"
#include "Model/Board.hpp"
#include <ctime>
#include <memory>
#include <iostream>

class PlayStateAbstract : public AbstractState {
public:
    explicit PlayStateAbstract(int boardSize, std::shared_ptr<Board> board = nullptr, int x = 0, int y = 0);

    void OnEntry(Game &game) override;

    void Update(Game &game) override;

    void Draw(Game &game) override;

    void OnExit(Game &game) override;
protected:
    std::time_t creationTime{};
    std::time_t gameTime{};
    std::shared_ptr<Board> board;
    int x;
    int y;
    std::string GetGameTimeString() const;
};


#endif //HEXADOKU_PLAYSTATEABSTRACT_HPP
