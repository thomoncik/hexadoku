#include <iomanip>
#include "../include/MainMenuState.hpp"
#include "../include/GfxStream.hpp"
#include "../include/Attributes.hpp"
#include "../include/GamemodeMenuState.hpp"



const std::map<MainMenuState::Option, std::string> MainMenuState::MENU_OPTIONS = {
        {MainMenuState::Option::NEW_GAME,      "New game"},
        {MainMenuState::Option::BOARD_CREATOR, "Board creator"},
        {MainMenuState::Option::EXIT,          "Exit"},
};

MainMenuState::MainMenuState() : selectedOption(0) {
    gfx::out << gfx::clear;

    gfx::out << Position(0, 3) << Color::Blue << Attribute::BOLD;
    gfx::out << Assets::HEXADOKU_LOGO << gfx::nodecor;
}

void MainMenuState::OnEntry(Game &game) {

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
                newState = std::unique_ptr<AbstractState>(new GamemodeMenuState());
                break;
            case Option::BOARD_CREATOR:
                newState = std::unique_ptr<AbstractState>(new GamemodeMenuState());
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
            gfx::out << Attribute::STANDOUT;
        }
        gfx::out << Position(30, 13 + i) << std::setw(14);
        gfx::out << optionIterator->second << gfx::nodecor;
    }
}

void MainMenuState::OnExit(Game &game) {

}
