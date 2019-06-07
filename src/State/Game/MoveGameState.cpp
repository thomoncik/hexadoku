#include <utility>

#include <State/Game/MoveGameState.hpp>
#include <State/Menu/MainMenuState.hpp>
#include <View/Game/MoveGameView.hpp>
#include "State/Game/InsertionGameState.hpp"

MoveGameState::MoveGameState(int boardSize) : AbstractGameState(boardSize) {

}

MoveGameState::MoveGameState(std::shared_ptr<Board> board) : AbstractGameState(std::move(board)) {

}

MoveGameState::MoveGameState(std::shared_ptr<Game> model) : AbstractGameState(std::move(model)) {}

void MoveGameState::HandleInput(StateContext &game, char input) {
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
        game.SetState(std::make_shared<InsertionGameState>(std::move(model)));
    }
}

void MoveGameState::Draw(StateContext &game) {
    MoveGameView gameView(model->GetBoard(), model->GetGameTimeString());
    gameView.Draw();
}
