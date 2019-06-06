//
// Created by Jakub Kiermasz on 2019-05-25.
//

#ifndef HEXADOKU_INSERTIONPLAYSTATE_HPP
#define HEXADOKU_INSERTIONPLAYSTATE_HPP

#include "Model/Board.hpp"
#include "PlayStateAbstract.hpp"

class InsertionPlayState : public PlayStateAbstract {
public:
    explicit InsertionPlayState(int boardSize);

    explicit InsertionPlayState(std::shared_ptr<PlayStateModel> model);

    void HandleInput(Game &game, char input) override;
    
    void Draw(Game &game) override;

private:
    std::vector<char> boardCharacters;
};


#endif //HEXADOKU_INSERTIONPLAYSTATE_HPP
