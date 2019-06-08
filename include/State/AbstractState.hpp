#ifndef HEXADOKU_ABSTRACTSTATE_HPP
#define HEXADOKU_ABSTRACTSTATE_HPP

#include "StateContext.hpp"
class StateContext;

class AbstractState {
public:
    virtual ~AbstractState() = 0;

    virtual void OnEntry(StateContext &stateContext) = 0;

    virtual void Update(StateContext &stateContext) = 0;

    virtual void HandleInput(StateContext &stateContext, char input) = 0;

    virtual void Draw(StateContext &stateContext) = 0;

    virtual void OnExit(StateContext &stateContext) = 0;
};

#endif //HEXADOKU_ABSTRACTSTATE_HPP
