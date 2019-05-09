#include <utility>

#include <ncurses.h>
#include "../include/Game.hpp"
#include "../include/MainMenuState.hpp"

Game::Game() : state(std::make_shared<MainMenuState>()) {

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
    }
}

void Game::SetState(std::shared_ptr<AbstractState> newState) {
    this->state = std::move(newState);
}
