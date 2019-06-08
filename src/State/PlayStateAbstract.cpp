//
// Created by Jakub Kiermasz on 2019-05-25.
//
#include <memory>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <State/PlayStateAbstract.hpp>
#include <Graphics/GfxStream.hpp>


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

}

void PlayStateAbstract::OnExit(Game &game) {

}

