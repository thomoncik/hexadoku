#include <iomanip>
#include "../include/MainMenuState.hpp"
#include "../include/GfxStream.hpp"
#include "../include/Attributes.hpp"
#include "../include/PlayState.hpp"

const std::string MainMenuState::HEXADOKU_LOGO
        = "   888    888                                 888          888               \n"
          "   888    888                                 888          888               \n"
          "   888    888                                 888          888               \n"
          "   8888888888  .d88b.  888  888  8888b.   .d88888  .d88b.  888  888 888  888 \n"
          "   888    888 d8P  Y8b `Y8bd8P'     \"88b d88\" 888 d88\"\"88b 888 .88P 888  888 \n"
          "   888    888 88888888   X88K   .d888888 888  888 888  888 888888K  888  888 \n"
          "   888    888 Y8b.     .d8\"\"8b. 888  888 Y88b 888 Y88..88P 888 \"88b Y88b 888 \n"
          "   888    888  \"Y8888  888  888 \"Y888888  \"Y88888  \"Y88P\"  888  888  \"Y88888 \n";

const std::map<MainMenuState::Option, std::string> MainMenuState::MENU_OPTIONS = {
        {MainMenuState::Option::NEW_GAME,      "New game"},
        {MainMenuState::Option::BOARD_CREATOR, "Board creator"},
        {MainMenuState::Option::EXIT,          "Exit"},
};

MainMenuState::MainMenuState() : selectedOption(0) {
    GfxStream::out << GfxStream::clrscr;

    GfxStream::out << Position(0, 3) << Color::Blue << Attribute::BOLD;
    GfxStream::out << MainMenuState::HEXADOKU_LOGO << GfxStream::nodecor;
}

void MainMenuState::Update(Game &game) {

}

void MainMenuState::HandleInput(Game &game, char input) {
    if (input == 'j') {
        this->selectedOption = (this->selectedOption + 1) % MENU_OPTIONS.size();
    } else if (input == 'k') {
        this->selectedOption == 0 ? (this->selectedOption = MENU_OPTIONS.size() - 1) : (this->selectedOption--);
    } else if (input == ' ') {
        std::unique_ptr<AbstractState> newState;
        switch (static_cast<MainMenuState::Option>(this->selectedOption)) {
            case Option::NEW_GAME:
                newState = std::unique_ptr<AbstractState>(new PlayState());
                break;
            case Option::BOARD_CREATOR:
                newState = std::unique_ptr<AbstractState>(new PlayState());
                break;
            case Option::EXIT:
                newState = nullptr;
                break;
        }
        game.SetState(std::move(newState));
    }
}

void MainMenuState::Draw(Game &game) {
    auto optionIterator = MainMenuState::MENU_OPTIONS.begin();
    for (unsigned i = 0; i < MainMenuState::MENU_OPTIONS.size(); ++i, ++optionIterator) {
        if (this->selectedOption == i) {
            GfxStream::out << Attribute::STANDOUT;
        }
        GfxStream::out << Position(30, 13 + i) << std::setw(14);
        GfxStream::out << optionIterator->second << GfxStream::nodecor;
    }
}
