#ifndef HEXADOKU_STATECONTEXT_HPP
#define HEXADOKU_STATECONTEXT_HPP

#include "State/AbstractState.hpp"
#include <memory>

class AbstractState;

class StateContext {
public:
    StateContext();

    void Run();

    void SetState(std::shared_ptr<AbstractState> newState);

    AbstractState *GetState() const;

private:
    std::shared_ptr<AbstractState> state;
};

#endif //HEXADOKU_STATECONTEXT_HPP
