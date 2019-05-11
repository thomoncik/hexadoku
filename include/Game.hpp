#ifndef HEXADOKU_GAME_HPP
#define HEXADOKU_GAME_HPP

#include <stack>
#include <memory>

#include "AbstractState.hpp"

class AbstractState;

class Game {
public:
    Game();

    void Run();

    void SetState(std::unique_ptr<AbstractState> newState);

    AbstractState *GetState();

private:
    std::unique_ptr<AbstractState> state;
};

#endif //HEXADOKU_GAME_HPP
