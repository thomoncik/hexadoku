#include <State/Menu/NewGameDifficultyMenuState.hpp>
#include <State/Game/MoveGameState.hpp>
#include <State/Menu/NewGameMenuState.hpp>
#include <State/Menu/NewGameFromFileMenuState.hpp>

const std::string NewGameDifficultyMenuState::EASY_OPTION{"Easy"};
const std::string NewGameDifficultyMenuState::NORMAL_OPTION{"Normal"};
const std::string NewGameDifficultyMenuState::HARD_OPTION{"Hard"};
const std::string NewGameDifficultyMenuState::FROM_FILE_OPTION{"From file"};
const std::string NewGameDifficultyMenuState::BACK_OPTION{"Back"};

NewGameDifficultyMenuState::NewGameDifficultyMenuState(int size) : size(size) {
    options = {
            EASY_OPTION,
            NORMAL_OPTION,
            HARD_OPTION,
            FROM_FILE_OPTION,
            BACK_OPTION,
    };
}

void NewGameDifficultyMenuState::UseOption(StateContext &stateContext, const std::string &option) {
    if (option == BACK_OPTION) {
        stateContext.SetState(std::make_shared<NewGameMenuState>());
    } else if (option == FROM_FILE_OPTION) {
        stateContext.SetState(std::make_shared<NewGameFromFileMenuState>(size));
    }

    Board board(size);
    if (option == EASY_OPTION) {
        board.Generate(Board::Difficulty::EASY);
        stateContext.SetState(std::make_shared<MoveGameState>(std::make_shared<Board>(board)));
    } else if (option == NORMAL_OPTION) {
        board.Generate(Board::Difficulty::NORMAL);
        stateContext.SetState(std::make_shared<MoveGameState>(std::make_shared<Board>(board)));
    } else if (option == HARD_OPTION) {
        board.Generate(Board::Difficulty::HARD);
        stateContext.SetState(std::make_shared<MoveGameState>(std::make_shared<Board>(board)));
    }
}

