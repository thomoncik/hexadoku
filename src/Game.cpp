#include <utility>
#include <chrono>
#include <thread>
#include <ncurses.h>
#include <Menu/MainMenuState.hpp>

#include "Game.hpp"

Game::Game() : state(nullptr) {
    SetState(std::make_shared<MainMenuState>());
}

void Game::Run() {
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

void Game::SetState(std::shared_ptr<AbstractState> newState) {
    if (state != nullptr) {
        state->OnExit(*this);
    }

    state = std::move(newState);

    if (state != nullptr) {
        state->OnEntry(*this);
    }
}

AbstractState *Game::GetState() const {
    return state.get();
}
