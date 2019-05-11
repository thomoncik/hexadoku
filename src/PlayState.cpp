#include "../include/PlayState.hpp"
#include "../include/MainMenuState.hpp"
#include "../include/GfxStream.hpp"

#include <memory>

PlayState::PlayState() {
    gfx::out << gfx::clear;
}

void PlayState::OnEntry(Game &game) {

}

void PlayState::Update(Game &game) {

}

void PlayState::HandleInput(Game &game, char input) {
    if (input == 'q') {
        std::unique_ptr<AbstractState> mainMenuState(new MainMenuState());
        game.SetState(std::move(mainMenuState));
    }
}

void PlayState::Draw(Game &game) {
    gfx::out << Color::Red;
    for (int i = 0; i < 10; ++i) {
        gfx::out << Position(10, 10 + i) << "----------";
    }
    gfx::out << gfx::nodecor;
}

void PlayState::OnExit(Game &game) {

}
