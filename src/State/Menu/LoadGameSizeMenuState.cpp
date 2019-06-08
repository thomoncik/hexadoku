#include <State/Menu/LoadGameSizeMenuState.hpp>
#include <State/Menu/LoadGameMenuState.hpp>
#include <State/Menu/MainMenuState.hpp>
#include <Model/Board.hpp>

const std::string LoadGameSizeMenuState::STANDARD_SIZE_OPTION{"Standard"};
const std::string LoadGameSizeMenuState::HEXADOKU_OPTION{"Hexadoku"};
const std::string LoadGameSizeMenuState::BACK_OPTION{"Back"};

LoadGameSizeMenuState::LoadGameSizeMenuState() {
    options = {
            STANDARD_SIZE_OPTION,
            HEXADOKU_OPTION,
            BACK_OPTION,
    };
}

void LoadGameSizeMenuState::UseOption(StateContext &stateContext, const std::string &option) {
    if (option == STANDARD_SIZE_OPTION) {
        stateContext.SetState(std::make_shared<LoadGameMenuState>(Board::STANDARD_SIZE));
    } else if (option == HEXADOKU_OPTION) {
        stateContext.SetState(std::make_shared<LoadGameMenuState>(Board::HEXADOKU_SIZE));
    } else if (option == BACK_OPTION) {
        stateContext.SetState(std::make_shared<MainMenuState>());
    }
}
