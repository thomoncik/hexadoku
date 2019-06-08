#include <State/Menu/NewGameMenuState.hpp>
#include <State/Menu/MainMenuState.hpp>
#include <State/Menu/NewGameDifficultyMenuState.hpp>
#include <Model/Board.hpp>

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

void NewGameMenuState::UseOption(StateContext &stateContext, const std::string &option) {
    if (option == STANDARD_SIZE_OPTION) {
        stateContext.SetState(std::make_shared<NewGameDifficultyMenuState>(Board::STANDARD_SIZE));
    } else if (option == HEXADOKU_OPTION) {
        stateContext.SetState(std::make_shared<NewGameDifficultyMenuState>(Board::HEXADOKU_SIZE));
    } else if (option == BACK_OPTION) {
        stateContext.SetState(std::make_shared<MainMenuState>());
    }
}
