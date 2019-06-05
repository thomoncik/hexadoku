#include <Menu/LoadGameMenu.hpp>
#include <Menu/MainMenuState.hpp>
#include <Menu/LoadStandardGameMenu.hpp>

const std::string LoadGameMenu::STANDARD_SIZE_OPTION{"Standard"};
const std::string LoadGameMenu::HEXADOKU_OPTION{"Hexadoku"};
const std::string LoadGameMenu::BACK_OPTION{"Back"};

LoadGameMenu::LoadGameMenu() {
    options = {
            STANDARD_SIZE_OPTION,
            HEXADOKU_OPTION,
            BACK_OPTION,
    };
}

void LoadGameMenu::UseOption(Game &game, const std::string &option) {
    if (option == STANDARD_SIZE_OPTION) {
        game.SetState(std::make_shared<LoadStandardGameMenu>());
    } else if (option == HEXADOKU_OPTION) {
        game.SetState(nullptr);
    } else if (option == BACK_OPTION) {
        game.SetState(std::make_shared<MainMenuState>());
    }
}