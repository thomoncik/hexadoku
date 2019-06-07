#include <State/Menu/BoardCreatorMenu.hpp>
#include <State/Menu/MainMenuState.hpp>
#include <State/Menu/LoadBoardSizeMenuState.hpp>
#include <State/BoardCreator/MoveBoardCreatorState.hpp>

const std::string BoardCreatorMenu::STANDARD_SIZE_OPTION{"Standard"};
const std::string BoardCreatorMenu::HEXADOKU_OPTION{"Hexadoku"};
const std::string BoardCreatorMenu::FROM_FILE_OPTION{"From file"};
const std::string BoardCreatorMenu::BACK_OPTION{"Back"};

BoardCreatorMenu::BoardCreatorMenu() {
    options = {
            STANDARD_SIZE_OPTION,
            HEXADOKU_OPTION,
            FROM_FILE_OPTION,
            BACK_OPTION,
    };
}

void BoardCreatorMenu::UseOption(StateContext &game, const std::string &option) {
    if (option == STANDARD_SIZE_OPTION) {
        game.SetState(std::make_shared<MoveBoardCreatorState>(Board::STANDARD_SIZE));
    } else if (option == HEXADOKU_OPTION) {
        game.SetState(std::make_shared<MoveBoardCreatorState>(Board::HEXADOKU_SIZE));
    } else if (option == FROM_FILE_OPTION) {
        game.SetState(std::make_shared<LoadBoardSizeMenuState>());
    } else if (option == BACK_OPTION) {
        game.SetState(std::make_shared<MainMenuState>());
    }
}