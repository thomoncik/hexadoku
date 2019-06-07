#include <State/Menu/LoadBoardSizeMenuState.hpp>
#include <State/Menu/LoadBoardMenuState.hpp>
#include <State/Menu/MainMenuState.hpp>
#include <Model/Board.hpp>

const std::string LoadBoardSizeMenuState::STANDARD_SIZE_OPTION{"Standard"};
const std::string LoadBoardSizeMenuState::HEXADOKU_OPTION{"Hexadoku"};
const std::string LoadBoardSizeMenuState::BACK_OPTION{"Back"};

LoadBoardSizeMenuState::LoadBoardSizeMenuState() {
    options = {
            STANDARD_SIZE_OPTION,
            HEXADOKU_OPTION,
            BACK_OPTION,
    };
}

void LoadBoardSizeMenuState::UseOption(Game &game, const std::string &option) {
    if (option == STANDARD_SIZE_OPTION) {
        game.SetState(std::make_shared<LoadBoardMenuState>(Board::STANDARD_SIZE));
    } else if (option == HEXADOKU_OPTION) {
        game.SetState(std::make_shared<LoadBoardMenuState>(Board::HEXADOKU_SIZE));
    } else if (option == BACK_OPTION) {
        game.SetState(std::make_shared<MainMenuState>());
    }
}

