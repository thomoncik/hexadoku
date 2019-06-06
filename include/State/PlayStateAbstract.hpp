//
// Created by Jakub Kiermasz on 2019-05-25.
//

#ifndef HEXADOKU_PLAYSTATEABSTRACT_HPP
#define HEXADOKU_PLAYSTATEABSTRACT_HPP

#include <State/AbstractState.hpp>
#include <Model/PlayStateModel.hpp>
#include <ctime>
#include <memory>

class PlayStateAbstract : public AbstractState {
public:
    explicit PlayStateAbstract(int boardSize);

    explicit PlayStateAbstract(std::shared_ptr<Board> board);

    explicit PlayStateAbstract(std::shared_ptr<PlayStateModel> model);

    void OnEntry(Game &game) override;

    void Update(Game &game) override;

    void OnExit(Game &game) override;

protected:
    std::shared_ptr<PlayStateModel> model;
};


#endif //HEXADOKU_PLAYSTATEABSTRACT_HPP
