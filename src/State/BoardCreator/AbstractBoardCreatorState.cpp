#include <State/BoardCreator/AbstractBoardCreatorState.hpp>
#include <State/Menu/MainMenuState.hpp>
#include <Graphics/GfxStream.hpp>
#include <View/Board/BoardView.hpp>
#include <View/BoardCreator/AbstractBoardCreatorView.hpp>

AbstractBoardCreatorState::AbstractBoardCreatorState(int size) : boardCreator(std::make_shared<BoardCreator>(size)) {

}

AbstractBoardCreatorState::AbstractBoardCreatorState(std::shared_ptr<Board> board) :
        boardCreator(std::make_shared<BoardCreator>(std::move(board))) {

}

AbstractBoardCreatorState::AbstractBoardCreatorState(std::shared_ptr<BoardCreator> boardCreator) :
        boardCreator(std::move(boardCreator)) {

}

void AbstractBoardCreatorState::OnEntry(StateContext &game) {

}

void AbstractBoardCreatorState::Update(StateContext &game) {

}

void AbstractBoardCreatorState::OnExit(StateContext &game) {

}

void AbstractBoardCreatorState::HandleInput(StateContext &game, char input) {
    if (input == 'q') {
        game.SetState(std::make_shared<MainMenuState>());
    }
}

void AbstractBoardCreatorState::Draw(StateContext &game) {

}
