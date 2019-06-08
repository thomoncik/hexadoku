//
// Created by Jakub Kiermasz on 2019-05-25.
//
#include <memory>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <State/Game/AbstractGameState.hpp>
#include <Graphics/GfxStream.hpp>
#include <State/Game/EndGameState.hpp>


AbstractGameState::AbstractGameState(int boardSize) : game(std::make_shared<Game>(boardSize)) {

}

AbstractGameState::AbstractGameState(std::shared_ptr<Board> board) : game(std::make_shared<Game>(std::move(board))) {

}

AbstractGameState::AbstractGameState(std::shared_ptr<Game> game) : game(std::move(game)) {

}

void AbstractGameState::OnEntry(StateContext &stateContext) {
    game->StartTimer();
}

void AbstractGameState::Update(StateContext &stateContext) {
    if (game->GetBoard()->IsFilled() && !game->GetBoard()->IsViolatingRules()) {
        stateContext.SetState(std::make_shared<EndGameState>(std::move(game)));
    }
}

void AbstractGameState::OnExit(StateContext &stateContext) {

}

