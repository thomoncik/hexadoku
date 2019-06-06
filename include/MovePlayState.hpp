//
// Created by thomoncik on 09.05.19.
//

#ifndef HEXADOKU_MOVEPLAYSTATE_HPP
#define HEXADOKU_MOVEPLAYSTATE_HPP

#include "Model/Board.hpp"
#include "PlayStateAbstract.hpp"

class MovePlayState : public PlayStateAbstract {
public:
    explicit MovePlayState(int boardSize);

    explicit MovePlayState(std::shared_ptr<PlayStateModel> model);

    void HandleInput(Game &game, char input) override;

    void Draw(Game &game) override;

};


#endif //HEXADOKU_MOVEPLAYSTATE_HPP
