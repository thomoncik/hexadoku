#include <Menu/NewGameMenuState.hpp>
#include <Menu/BoardCreatorMenu.hpp>
#include <Menu/LoadGameMenu.hpp>
#include <Menu/AbstractLoadingMenu.hpp>
#include "Menu/MainMenuState.hpp"

const std::string MainMenuState::NEW_GAME_OPTION{"New game"};
const std::string MainMenuState::LOAD_GAME_OPTION{"Load game"};
const std::string MainMenuState::BOARD_CREATOR_OPTION{"Board creator"};
const std::string MainMenuState::EXIT_OPTION{"Exit"};

MainMenuState::MainMenuState() {
    options = {
            NEW_GAME_OPTION,
            LOAD_GAME_OPTION,
            BOARD_CREATOR_OPTION,
            EXIT_OPTION,
    };
}

void MainMenuState::UseOption(Game &game, const std::string &option) {
    if (option == NEW_GAME_OPTION) {
        game.SetState(std::make_shared<NewGameMenuState>());
    } else if (option == LOAD_GAME_OPTION) {
        game.SetState(std::make_shared<AbstractLoadingMenu>());
    } else if (option == BOARD_CREATOR_OPTION) {
        game.SetState(std::make_shared<BoardCreatorMenu>());
    } else if (option == EXIT_OPTION) {
        game.SetState(nullptr);
    }
}
