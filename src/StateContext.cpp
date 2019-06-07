#include <utility>
#include <chrono>
#include <thread>
#include <ncurses.h>
#include <State/Menu/MainMenuState.hpp>

#include "StateContext.hpp"

StateContext::StateContext() : state(nullptr) {
    SetState(std::make_shared<MainMenuState>());
}

void StateContext::Run() {
    while (state != nullptr) {
        if (state != nullptr) {
            state->Draw(*this);
        }
        if (state != nullptr) {
            state->HandleInput(*this, getch());
        }
        if (state != nullptr) {
            state->Update(*this);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

void StateContext::SetState(std::shared_ptr<AbstractState> newState) {
    if (state != nullptr) {
        state->OnExit(*this);
    }

    state = std::move(newState);

    if (state != nullptr) {
        state->OnEntry(*this);
    }
}

AbstractState *StateContext::GetState() const {
    return state.get();
}
