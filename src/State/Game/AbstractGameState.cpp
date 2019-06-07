//
// Created by Jakub Kiermasz on 2019-05-25.
//
#include <memory>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <State/Game/AbstractGameState.hpp>
#include <Graphics/GfxStream.hpp>


AbstractGameState::AbstractGameState(int boardSize) : model(std::make_shared<Game>(boardSize)) {

}

AbstractGameState::AbstractGameState(std::shared_ptr<Board> board)
        : model(std::make_shared<Game>(std::move(board))) {

}

AbstractGameState::AbstractGameState(std::shared_ptr<Game> model) : model(std::move(model)) {

}

void AbstractGameState::OnEntry(StateContext &game) {
    model->StartTimer();
    gfx::out << gfx::clear;
}

void AbstractGameState::Update(StateContext &game) {

}

void AbstractGameState::OnExit(StateContext &game) {

}

