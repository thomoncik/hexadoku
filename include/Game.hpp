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

    void SetState(AbstractState *newState);

    AbstractState *GetState();

private:
    AbstractState *state;
};

#endif //HEXADOKU_GAME_HPP
