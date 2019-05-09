#include "../include/PlayState.hpp"
#include "../include/MainMenuState.hpp"
#include "../include/GfxStream.hpp"

#include <memory>

PlayState::PlayState() {
    GfxStream::out << GfxStream::clrscr;
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
    GfxStream::out << Color::Red;
    for (int i = 0; i < 10; ++i) {
        GfxStream::out << Position(10, 10 + i) << "----------";
    }
    GfxStream::out << GfxStream::nodecor;
}
