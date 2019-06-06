#ifndef HEXADOKU_ABSTRACTSTATE_HPP
#define HEXADOKU_ABSTRACTSTATE_HPP

#include "Game.hpp"
class Game;

class AbstractState {
public:
    virtual ~AbstractState() = 0;

    virtual void OnEntry(Game &game) = 0;

    virtual void Update(Game &game) = 0;

    virtual void HandleInput(Game &game, char input) = 0;

    virtual void Draw(Game &game) = 0;

    virtual void OnExit(Game &game) = 0;
};

#endif //HEXADOKU_ABSTRACTSTATE_HPP
