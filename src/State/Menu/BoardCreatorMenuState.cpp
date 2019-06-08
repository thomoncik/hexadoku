#include <State/Menu/BoardCreatorMenuState.hpp>
#include <State/Menu/MainMenuState.hpp>
#include <State/Menu/LoadOrCreateBoardMenuState.hpp>
#include <State/BoardCreator/MoveBoardCreatorState.hpp>

const std::string BoardCreatorMenuState::STANDARD_SIZE_OPTION{"Standard"};
const std::string BoardCreatorMenuState::HEXADOKU_OPTION{"Hexadoku"};
const std::string BoardCreatorMenuState::BACK_OPTION{"Back"};

BoardCreatorMenuState::BoardCreatorMenuState() {
    options = {
            STANDARD_SIZE_OPTION,
            HEXADOKU_OPTION,
            BACK_OPTION,
    };
}

void BoardCreatorMenuState::UseOption(StateContext &stateContext, const std::string &option) {
    if (option == STANDARD_SIZE_OPTION) {
        stateContext.SetState(std::make_shared<LoadOrCreateBoardMenuState>(Board::STANDARD_SIZE));
    } else if (option == HEXADOKU_OPTION) {
        stateContext.SetState(std::make_shared<LoadOrCreateBoardMenuState>(Board::HEXADOKU_SIZE));
    } else if (option == BACK_OPTION) {
        stateContext.SetState(std::make_shared<MainMenuState>());
    }
}