#include <iomanip>
#include <string>

#include "../include/MenuState.hpp"
#include "../include/GfxStream.hpp"
#include "../include/Attributes.hpp"
#include "../include/Assets.hpp"
#include "../include/PlayState.hpp"

MenuState *const MenuState::MAIN_MENU = new MenuState();
MenuState *const MenuState::GAME_MODE_MENU = new MenuState();
bool MenuState::arePredefinedMenusInitialized = MenuState::initPredefinedMenus();

MenuState::MenuState() : selectedOption(0), labelSize(0) {

}

void MenuState::OnEntry(Game &game) {
    gfx::out << gfx::clear;
    gfx::out << Position(0, 3) << Color::Blue << Attribute::BOLD;
    gfx::out << Assets::HEXADOKU_LOGO << gfx::nodecor;

    this->selectedOption = 0;
}

void MenuState::Update(Game &game) {

}

void MenuState::HandleInput(Game &game, char input) {
    if (input == 'j') {
        this->selectedOption = (this->selectedOption + 1) % this->options.size();
    } else if (input == 'k') {
        this->selectedOption == 0 ? (this->selectedOption = this->options.size() - 1) : (this->selectedOption--);
    } else if (input == ' ') {
        game.SetState(this->options[this->selectedOption].second);
    }
}

void MenuState::Draw(Game &game) {
    auto optionIterator = this->options.begin();
    for (unsigned i = 0; i < this->options.size(); ++i, ++optionIterator) {
        if (this->selectedOption == i) {
            gfx::out << Attribute::STANDOUT;
        }
        gfx::out << Position(30, 13 + i) << std::setw(this->labelSize);
        gfx::out << optionIterator->first << gfx::nodecor;
    }
}

void MenuState::OnExit(Game &game) {

}

void MenuState::AddOption(std::pair<std::wstring, AbstractState *> option) {
    this->options.emplace_back(option);
    this->labelSize = std::max(this->labelSize, option.first.size());
}

bool MenuState::initPredefinedMenus() {
    MAIN_MENU->AddOption({L"New game", GAME_MODE_MENU});
    MAIN_MENU->AddOption({L"Board creator", GAME_MODE_MENU});
    MAIN_MENU->AddOption({L"Exit", nullptr});

    GAME_MODE_MENU->AddOption({L"Standard", new PlayState(Board::STANDARD_SIZE)});
    GAME_MODE_MENU->AddOption({L"Hexadoku", new PlayState(Board::HEXADOKU_SIZE)});
    GAME_MODE_MENU->AddOption({L"Load your own scheme", nullptr});
    GAME_MODE_MENU->AddOption({L"Back", MAIN_MENU});

    return true;
}
