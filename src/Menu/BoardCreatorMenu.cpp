#include <Menu/BoardCreatorMenu.hpp>
#include <Menu/MainMenuState.hpp>
#include <State/MovePlayState.hpp>

const std::string BoardCreatorMenu::STANDARD_SIZE_OPTION{"Standard"};
const std::string BoardCreatorMenu::HEXADOKU_OPTION{"Hexadoku"};
const std::string BoardCreatorMenu::BACK_OPTION{"Back"};

BoardCreatorMenu::BoardCreatorMenu() {
    options = {
            STANDARD_SIZE_OPTION,
            HEXADOKU_OPTION,
            BACK_OPTION,
    };
}

void BoardCreatorMenu::UseOption(Game &game, const std::string &option) {
    if (option == STANDARD_SIZE_OPTION) {
        game.SetState(nullptr);
    } else if (option == HEXADOKU_OPTION) {
        game.SetState(nullptr);
    } else if (option == BACK_OPTION) {
        game.SetState(std::make_shared<MainMenuState>());
    }
}