//
// Created by Jakub Kiermasz on 2019-05-25.
//

#ifndef HEXADOKU_INSERTIONPLAYSTATE_HPP
#define HEXADOKU_INSERTIONPLAYSTATE_HPP

#include "Model/Board.hpp"
#include "PlayStateAbstract.hpp"

class InsertionPlayState : public PlayStateAbstract {
public:

    explicit InsertionPlayState(int boardSize, std::shared_ptr<Board> board = nullptr, int x = 0, int y = 0);

    void HandleInput(Game &game, char input) override;

    void Draw(Game &game) override;
private:
    std::vector<char> boardCharacters;
};


#endif //HEXADOKU_INSERTIONPLAYSTATE_HPP
