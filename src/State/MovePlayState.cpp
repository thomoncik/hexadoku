#include <utility>

#include <State/MovePlayState.hpp>
#include <State/Menu/MainMenuState.hpp>
#include <View/MoveGameView.hpp>
#include "State/InsertionPlayState.hpp"

MovePlayState::MovePlayState(int boardSize) : PlayStateAbstract(boardSize) {

}

MovePlayState::MovePlayState(std::shared_ptr<Board> board) : PlayStateAbstract(std::move(board)) {

}

MovePlayState::MovePlayState(std::shared_ptr<PlayStateModel> model) : PlayStateAbstract(std::move(model)) {}

void MovePlayState::HandleInput(Game &game, char input) {
    model->SetSelected(false, model->GetX(), model->GetY());
    if (input == 'l') {
        model->SetX((model->GetX() + 1) % model->GetSize());
    } else if (input == 'h') {
        model->SetX((model->GetX() == 0) ? model->GetSize() - 1 : model->GetX() - 1);
    } else if (input == 'j') {
        model->SetY((model->GetY() + 1) % model->GetSize());
    } else if (input == 'k') {
        model->SetY((model->GetY() == 0) ? model->GetSize() - 1 : model->GetY() - 1);
    }
    model->SetSelected(true, model->GetX(), model->GetY());

    if (input == 'q') {
        game.SetState(std::make_shared<MainMenuState>());
    } else if (input == 'm') {
        game.SetState(std::make_shared<InsertionPlayState>(std::move(model)));
    }
}

void MovePlayState::Draw(Game &game) {
    MoveGameView gameView(model->GetBoard(), model->GetGameTimeString());
    gameView.Draw();
}
