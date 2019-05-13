//
// Created by Jakub Kiermasz on 2019-05-11.
//
#include <iomanip>
#include "../include/GfxStream.hpp"
#include "../include/Attributes.hpp"
#include "../include/PlayState.hpp"
#include "../include/GameModeMenuState.hpp"
#include "../include/MainMenuState.hpp"
#include "../include/Assets.hpp"

const std::map<GameModeMenuState::Option, std::wstring> GameModeMenuState::GAMEMODE_OPTIONS = {
        {GameModeMenuState::Option::STANDARD, L"Standard mode"},
        {GameModeMenuState::Option::HEXADOKU, L"Hexadoku mode"},
        {GameModeMenuState::Option::LOAD_YOUR_OWN, L"Load your own scheme"},
        {GameModeMenuState::Option::BACK, L"Back"},
};

GameModeMenuState::GameModeMenuState() : selectedOption(0) {

}

void GameModeMenuState::OnEntry(Game &game) {
    gfx::out << gfx::clear;

    gfx::out << Position(0, 3) << Color::Blue << Attribute::BOLD;
    gfx::out << Assets::HEXADOKU_LOGO << gfx::nodecor;
}

void GameModeMenuState::Update(Game &game) {

}

void GameModeMenuState::HandleInput(Game &game, char input) {
    if (input == 'j') {
        this->selectedOption = (this->selectedOption + 1) % GAMEMODE_OPTIONS.size();
    } else if (input == 'k') {
        this->selectedOption == 0 ? (this->selectedOption = GAMEMODE_OPTIONS.size() - 1) : (this->selectedOption--);
    } else if (input == ' ') {
        AbstractState *newState = nullptr;
        switch (static_cast<GameModeMenuState::Option>(this->selectedOption)) {
            case Option::STANDARD:
                newState = new PlayState(Board::STANDARD_SIZE);
                break;
            case Option::HEXADOKU:
                newState = new PlayState(Board::HEXADOKU_SIZE);
                break;
            case Option::LOAD_YOUR_OWN:
                newState = new PlayState(Board::STANDARD_SIZE);
                break;
            case Option::BACK:
                newState = new MainMenuState();
                break;
        }
        game.SetState(newState);
    }
}

void GameModeMenuState::Draw(Game &game) {
    auto optionIterator = GameModeMenuState::GAMEMODE_OPTIONS.begin();
    for (unsigned i = 0; i < GameModeMenuState::GAMEMODE_OPTIONS.size(); ++i, ++optionIterator) {
        if (this->selectedOption == i) {
            gfx::out << Attribute::STANDOUT;
        }
        gfx::out << Position(30, 13 + i) << std::setw(20);
        gfx::out << optionIterator->second << gfx::nodecor;
    }
}

void GameModeMenuState::OnExit(Game &game) {

}
