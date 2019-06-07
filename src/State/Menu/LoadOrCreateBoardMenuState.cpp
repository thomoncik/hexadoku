#include <State/Menu/LoadOrCreateBoardMenuState.hpp>
#include <State/Menu/LoadBoardMenuState.hpp>
#include <State/BoardCreator/MoveBoardCreatorState.hpp>
#include <State/Menu/BoardCreatorMenuState.hpp>

const std::string LoadOrCreateBoardMenuState::CREATE_NEW_OPTION{"Create new"};
const std::string LoadOrCreateBoardMenuState::FROM_FILE_OPTION{"Load from file"};
const std::string LoadOrCreateBoardMenuState::BACK_OPTION{"Back"};

LoadOrCreateBoardMenuState::LoadOrCreateBoardMenuState(int size) : size(size) {
    options = {
            CREATE_NEW_OPTION,
            FROM_FILE_OPTION,
            BACK_OPTION,
    };
}

void LoadOrCreateBoardMenuState::UseOption(StateContext &stateContext, const std::string &option) {
    if (option == CREATE_NEW_OPTION) {
        stateContext.SetState(std::make_shared<MoveBoardCreatorState>(size));
    } else if (option == FROM_FILE_OPTION) {
        stateContext.SetState(std::make_shared<LoadBoardMenuState>(size));
    } else if (option == BACK_OPTION) {
        stateContext.SetState(std::make_shared<BoardCreatorMenuState>());
    }
}

