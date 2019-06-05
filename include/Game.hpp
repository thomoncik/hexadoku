#ifndef HEXADOKU_GAME_HPP
#define HEXADOKU_GAME_HPP

#include "AbstractState.hpp"
#include <memory>

class AbstractState;

class Game {
public:
    Game();

    void Run();

    void SetState(std::shared_ptr<AbstractState> newState);

    AbstractState *GetState() const;

private:
    std::shared_ptr<AbstractState> state;
};

#endif //HEXADOKU_GAME_HPP
