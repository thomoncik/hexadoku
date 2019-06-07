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

void AbstractBoardCreatorState::OnEntry(StateContext &stateContext) {

}

void AbstractBoardCreatorState::Update(StateContext &stateContext) {

}

void AbstractBoardCreatorState::OnExit(StateContext &stateContext) {

}

void AbstractBoardCreatorState::HandleInput(StateContext &stateContext, char input) {
    if (input == 'q') {
        stateContext.SetState(std::make_shared<MainMenuState>());
    }
}

void AbstractBoardCreatorState::Draw(StateContext &stateContext) {

}
