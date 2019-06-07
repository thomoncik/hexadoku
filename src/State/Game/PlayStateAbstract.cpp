//
// Created by Jakub Kiermasz on 2019-05-25.
//
#include <memory>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <State/Game/PlayStateAbstract.hpp>
#include <Graphics/GfxStream.hpp>
#include "State/Game/EndGameState.hpp"


PlayStateAbstract::PlayStateAbstract(int boardSize) : model(std::make_shared<PlayStateModel>(boardSize)) {

}

PlayStateAbstract::PlayStateAbstract(std::shared_ptr<Board> board)
        : model(std::make_shared<PlayStateModel>(std::move(board))) {

}

PlayStateAbstract::PlayStateAbstract(std::shared_ptr<PlayStateModel> model) : model(std::move(model)) {

}

void PlayStateAbstract::OnEntry(Game &game) {
    model->StartTimer();
    gfx::out << gfx::clear;
}

void PlayStateAbstract::Update(Game &game) {
    if (model->GetBoard().IsFilled() && !model->GetBoard().IsViolatingRules()) {
        game.SetState(std::make_shared<EndGameState>(std::move(model)));
    }
}

void PlayStateAbstract::OnExit(Game &game) {

}

