#ifndef HEXADOKU_ABSTRACTSTATE_HPP
#define HEXADOKU_ABSTRACTSTATE_HPP

#include "StateContext.hpp"
class StateContext;

class AbstractState {
public:
    virtual ~AbstractState() = 0;

    virtual void OnEntry(StateContext &game) = 0;

    virtual void Update(StateContext &game) = 0;

    virtual void HandleInput(StateContext &game, char input) = 0;

    virtual void Draw(StateContext &game) = 0;

    virtual void OnExit(StateContext &game) = 0;
};

#endif //HEXADOKU_ABSTRACTSTATE_HPP
