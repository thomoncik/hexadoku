#include <MovePlayState.hpp>
#include <MenuState.hpp>
#include "InsertionPlayState.hpp"
#include "View/MoveGameView.hpp"

MovePlayState::MovePlayState(int boardSize) : PlayStateAbstract(boardSize) {}
MovePlayState::MovePlayState(std::shared_ptr<PlayStateModel> model) : PlayStateAbstract(model) {}

void MovePlayState::HandleInput(Game &game, char input) {
    model->SetSelected(false, model->GetX(), model->GetY());

    if (input == 'q') {
        game.SetState(MenuState::MAIN_MENU);
    } else if (input == 'l') {
        this->model->SetX((this->model->GetX() + 1) % this->model->GetSize());
    } else if (input == 'h') {
        this->model->SetX((this->model->GetY() == 0) ? this->model->GetSize() - 1 : this->model->GetX() - 1);
    } else if (input == 'j') {
        this->model->SetY((this->model->GetX() + 1) % this->model->GetSize());
    } else if (input == 'k') {
        this->model->SetY((this->model->GetY() == 0) ? this->model->GetSize() - 1 : this->model->GetY() - 1);
    } else if (input == 'm') {
        game.SetState(new InsertionPlayState(this->model));
    }
    this->model->SetSelected(true, model->GetX(), model->GetY());
}

void MovePlayState::Draw(Game &game) {
    MoveGameView gameView(this->model->GetBoard(), this->model->GetGameTimeString());
    gameView.Draw();
}