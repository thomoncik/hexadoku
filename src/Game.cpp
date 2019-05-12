#include <utility>
#include <chrono>
#include <thread>
#include <ncurses.h>
#include "../include/Game.hpp"
#include "../include/MainMenuState.hpp"

Game::Game() {
    this->state = new MainMenuState();
}

void Game::Run() {
    while (this->state != nullptr) {
        if (this->state != nullptr) {
            this->state->Draw(*this);
        }
        if (this->state != nullptr) {
            this->state->HandleInput(*this, getch());
        }
        if (this->state != nullptr) {
            this->state->Update(*this);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

void Game::SetState(AbstractState *newState) {
    if (this->state != nullptr) {
        this->state->OnExit(*this);
    }

    this->state = newState;

    if (this->state != nullptr) {
        this->state->OnEntry(*this);
    }
}

AbstractState *Game::GetState() {
    return this->state;
}
