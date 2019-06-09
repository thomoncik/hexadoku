//
// Created by Jakub Kiermasz on 2019-06-09.
//

#include "State/Game/ConfirmExitGameState.hpp"
#include <State/Menu/MainMenuState.hpp>
#include <State/Game/InsertionGameState.hpp>
#include <State/Game/MoveGameState.hpp>
#include <View/Game/ConfirmExitGameView.hpp>

ConfirmExitGameState::ConfirmExitGameState(bool wasInsertionEnabled, std::shared_ptr<Game> model) : wasInsertionEnabled(wasInsertionEnabled), AbstractGameState(std::move(model)) {}

void ConfirmExitGameState::HandleInput(StateContext &stateContext, char input) {
    if (input == 'y') {
        stateContext.SetState(std::make_shared<MainMenuState>());
    } else if (input == 'n') {
        if (wasInsertionEnabled) {
            stateContext.SetState(std::make_shared<InsertionGameState>(std::move(game)));
        } else {
            stateContext.SetState(std::make_shared<MoveGameState>(std::move(game)));
        }
    }
}

void ConfirmExitGameState::Draw(StateContext &stateContext) {
    ConfirmExitGameView gameView(*game->GetBoard().get(), game->GetGameTimeString());
    gameView.Draw();
}