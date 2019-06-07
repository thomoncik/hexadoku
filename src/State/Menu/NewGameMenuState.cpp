#include <State/Menu/NewGameMenuState.hpp>
#include <State/Menu/MainMenuState.hpp>
#include <State/Game/MoveGameState.hpp>

const std::string NewGameMenuState::STANDARD_SIZE_OPTION{"Standard"};
const std::string NewGameMenuState::HEXADOKU_OPTION{"Hexadoku"};
const std::string NewGameMenuState::FROM_FILE_OPTION{"From file"};
const std::string NewGameMenuState::BACK_OPTION{"Back"};

NewGameMenuState::NewGameMenuState() {
    options = {
            STANDARD_SIZE_OPTION,
            HEXADOKU_OPTION,
            FROM_FILE_OPTION,
            BACK_OPTION,
    };
}

void NewGameMenuState::UseOption(StateContext &stateContext, const std::string &option) {
    if (option == STANDARD_SIZE_OPTION) {
        stateContext.SetState(std::make_shared<MoveGameState>(Board::STANDARD_SIZE));
    } else if (option == HEXADOKU_OPTION) {
        stateContext.SetState(std::make_shared<MoveGameState>(Board::HEXADOKU_SIZE));
    } else if (option == FROM_FILE_OPTION) {
        stateContext.SetState(nullptr);
    } else if (option == BACK_OPTION) {
        stateContext.SetState(std::make_shared<MainMenuState>());
    }
}
