//
// Created by Jakub Kiermasz on 2019-06-10.
//

#include "State/BoardCreator/ConfirmExitBoardCreatorState.hpp"
#include <State/Menu/MainMenuState.hpp>
#include <State/BoardCreator/InsertionBoardCreatorState.hpp>
#include <State/BoardCreator/MoveBoardCreatorState.hpp>
#include <View/BoardCreator/ConfirmExitBoardCreatorView.hpp>

ConfirmExitBoardCreatorState::ConfirmExitBoardCreatorState(bool wasInsertionEnabled, std::shared_ptr<BoardCreator> boardCreator) : wasInsertionEnabled(wasInsertionEnabled), AbstractBoardCreatorState(std::move(boardCreator)) {}

void ConfirmExitBoardCreatorState::HandleInput(StateContext &stateContext, char input) {
    if (input == 'y') {
        stateContext.SetState(std::make_shared<MainMenuState>());
    } else if (input == 'n') {
        if (wasInsertionEnabled) {
            stateContext.SetState(std::make_shared<InsertionBoardCreatorState>(std::move(boardCreator)));
        } else {
            stateContext.SetState(std::make_shared<MoveBoardCreatorState>(std::move(boardCreator)));
        }
    }
}

void ConfirmExitBoardCreatorState::Draw(StateContext &stateContext) {
    ConfirmExitBoardCreatorView view(boardCreator);
    view.Draw();
}