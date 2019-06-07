#include <State/Menu/LoadGameSizeMenu.hpp>
#include <State/Menu/LoadGameMenu.hpp>
#include <State/Menu/MainMenuState.hpp>
#include <Model/Board.hpp>

const std::string LoadGameSizeMenu::STANDARD_SIZE_OPTION{"Standard"};
const std::string LoadGameSizeMenu::HEXADOKU_OPTION{"Hexadoku"};
const std::string LoadGameSizeMenu::BACK_OPTION{"Back"};

LoadGameSizeMenu::LoadGameSizeMenu() {
    options = {
            STANDARD_SIZE_OPTION,
            HEXADOKU_OPTION,
            BACK_OPTION,
    };
}

void LoadGameSizeMenu::UseOption(Game &game, const std::string &option) {
    if (option == STANDARD_SIZE_OPTION) {
        game.SetState(std::make_shared<LoadGameMenu>(Board::STANDARD_SIZE));
    } else if (option == HEXADOKU_OPTION) {
        game.SetState(std::make_shared<LoadGameMenu>(Board::HEXADOKU_SIZE));
    } else if (option == BACK_OPTION) {
        game.SetState(std::make_shared<MainMenuState>());
    }
}