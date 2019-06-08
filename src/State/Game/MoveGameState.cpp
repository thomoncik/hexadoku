#include <utility>

#include <State/Game/MoveGameState.hpp>
#include <State/Menu/MainMenuState.hpp>
#include <View/Game/MoveGameView.hpp>
#include <State/Game/SaveGameState.hpp>
#include "State/Game/InsertionGameState.hpp"

MoveGameState::MoveGameState(int boardSize) : AbstractGameState(boardSize) {

}

MoveGameState::MoveGameState(std::shared_ptr<Board> board) : AbstractGameState(std::move(board)) {

}

MoveGameState::MoveGameState(std::shared_ptr<Game> game) : AbstractGameState(std::move(game)) {}

void MoveGameState::HandleInput(StateContext &stateContext, char input) {
    game->SetSelected(false, game->GetX(), game->GetY());
    if (input == 'l') {
        game->SetX((game->GetX() + 1) % game->GetSize());
    } else if (input == 'h') {
        game->SetX((game->GetX() == 0) ? game->GetSize() - 1 : game->GetX() - 1);
    } else if (input == 'j') {
        game->SetY((game->GetY() + 1) % game->GetSize());
    } else if (input == 'k') {
        game->SetY((game->GetY() == 0) ? game->GetSize() - 1 : game->GetY() - 1);
    }
    game->SetSelected(true, game->GetX(), game->GetY());

    if (input == '?') {
        game->MakeHint();
    } else if (input == 'q') {
        stateContext.SetState(std::make_shared<MainMenuState>());
    } else if (input == 'i') {
        stateContext.SetState(std::make_shared<InsertionGameState>(std::move(game)));
    } else if (input == 's') {
        stateContext.SetState(std::make_shared<SaveGameState>(std::move(game)));
    }
}

void MoveGameState::Draw(StateContext &stateContext) {
    MoveGameView gameView(*game->GetBoard().get(), game->GetGameTimeString());
    gameView.Draw();
}
