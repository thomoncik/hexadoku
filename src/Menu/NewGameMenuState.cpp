#include <Menu/NewGameMenuState.hpp>
#include <Menu/MainMenuState.hpp>
#include <MovePlayState.hpp>

const std::string NewGameMenuState::STANDARD_SIZE_OPTION{"Standard"};
const std::string NewGameMenuState::HEXADOKU_OPTION{"Hexadoku"};
const std::string NewGameMenuState::BACK_OPTION{"Back"};

NewGameMenuState::NewGameMenuState() {
    options = {
            STANDARD_SIZE_OPTION,
            HEXADOKU_OPTION,
            BACK_OPTION,
    };
}

void NewGameMenuState::UseOption(Game &game, const std::string &option) {
    if (option == STANDARD_SIZE_OPTION) {
        game.SetState(new MovePlayState(Board::STANDARD_SIZE));
    } else if (option == HEXADOKU_OPTION) {
        game.SetState(new MovePlayState(Board::HEXADOKU_SIZE));
    } else if (option == BACK_OPTION) {
        game.SetState(new MainMenuState());
    }
}
