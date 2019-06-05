//
// Created by Jakub Kiermasz on 2019-05-25.
//
#include <memory>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <PlayStateAbstract.hpp>
#include <GfxStream.hpp>
#include <MenuState.hpp>
#include <View/GameViewAbstract.hpp>

PlayStateAbstract::PlayStateAbstract(int boardSize) {
   this->model = std::make_shared<PlayStateModel>(boardSize);
}

PlayStateAbstract::PlayStateAbstract(std::shared_ptr<PlayStateModel> model) {
    this->model = std::move(model);
}

void PlayStateAbstract::OnEntry(Game &game) {
    this->model->StartTimer();
    gfx::out << gfx::clear;
}

void PlayStateAbstract::Update(Game &game) {}

void PlayStateAbstract::OnExit(Game &game) {

}

