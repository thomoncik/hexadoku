//
// Created by Jakub Kiermasz on 2019-05-11.
//
#include <iomanip>
#include "../include/GfxStream.hpp"
#include "../include/Attributes.hpp"
#include "../include/PlayState.hpp"
#include "../include/GamemodeMenuState.hpp"
#include "../include/MainMenuState.hpp"
#include "../include/Assets.hpp"

const std::map<GamemodeMenuState::Option, std::string> GamemodeMenuState::GAMEMODE_OPTIONS = {
        {GamemodeMenuState::Option::STANDARD, "Standard mode"},
        {GamemodeMenuState::Option::HEXADOKU, "Hexadoku mode"},
        {GamemodeMenuState::Option::LOAD_YOUR_OWN, "Load your own scheme"},
        {GamemodeMenuState::Option::BACK, "Back"},
};

GamemodeMenuState::GamemodeMenuState() : selectedOption(0) {

}

void GamemodeMenuState::OnEntry(Game &game) {
    gfx::out << gfx::clear;

    gfx::out << Position(0, 3) << Color::Blue << Attribute::BOLD;
    gfx::out << Assets::HEXADOKU_LOGO << gfx::nodecor;
}

void GamemodeMenuState::Update(Game &game) {

}

void GamemodeMenuState::HandleInput(Game &game, char input) {
    if (input == 'j') {
        this->selectedOption = (this->selectedOption + 1) % GAMEMODE_OPTIONS.size();
    } else if (input == 'k') {
        this->selectedOption == 0 ? (this->selectedOption = GAMEMODE_OPTIONS.size() - 1) : (this->selectedOption--);
    } else if (input == ' ') {
        AbstractState* newState;
        switch (static_cast<GamemodeMenuState::Option>(this->selectedOption)) {
            case Option::STANDARD:
                newState = new PlayState();
                break;
            case Option::HEXADOKU:
                newState = new PlayState();
                break;
            case Option::LOAD_YOUR_OWN:
                newState = new PlayState();
                break;
            case Option::BACK:
                newState = new MainMenuState();
                break;
        }
        game.SetState(newState);
    }
}

void GamemodeMenuState::Draw(Game &game) {
    auto optionIterator = GamemodeMenuState::GAMEMODE_OPTIONS.begin();
    for (unsigned i = 0; i < GamemodeMenuState::GAMEMODE_OPTIONS.size(); ++i, ++optionIterator) {
        if (this->selectedOption == i) {
            gfx::out << Attribute::STANDOUT;
        }
        gfx::out << Position(30, 13 + i) << std::setw(20);
        gfx::out << optionIterator->second << gfx::nodecor;
    }
}

void GamemodeMenuState::OnExit(Game &game) {

}
