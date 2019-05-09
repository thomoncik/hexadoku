#ifndef HEXADOKU_ABSTRACTSTATE_HPP
#define HEXADOKU_ABSTRACTSTATE_HPP

#include "Game.hpp"

class AbstractState {
public:
    virtual void Update(Game &game) = 0;

    virtual void HandleInput(Game &game, char input) = 0;

    virtual void Draw(Game &game) = 0;
};

#endif //HEXADOKU_ABSTRACTSTATE_HPP
