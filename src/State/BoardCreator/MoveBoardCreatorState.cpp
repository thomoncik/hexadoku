#include <State/BoardCreator/MoveBoardCreatorState.hpp>
#include <State/Menu/MainMenuState.hpp>
#include <State/BoardCreator/InsertionBoardCreatorState.hpp>
#include <View/BoardCreator/MoveBoardCreatorView.hpp>
#include <State/BoardCreator/SaveBoardCreatorState.hpp>

MoveBoardCreatorState::MoveBoardCreatorState(int size) : AbstractBoardCreatorState(size) {

}

MoveBoardCreatorState::MoveBoardCreatorState(std::shared_ptr<Board> board)
        : AbstractBoardCreatorState(std::move(board)) {

}

MoveBoardCreatorState::MoveBoardCreatorState(std::shared_ptr<BoardCreator> boardCreator) :
        AbstractBoardCreatorState(std::move(boardCreator)) {

}

void MoveBoardCreatorState::HandleInput(StateContext &stateContext, char input) {
    boardCreator->GetBoard()->SetSelected(false, boardCreator->GetSelectedColumn(), boardCreator->GetSelectedRow());
    if (input == 'l') {
        int newColumn = (boardCreator->GetSelectedColumn() + 1) % boardCreator->GetBoard()->GetSize();
        boardCreator->SetSelectedColumn(newColumn);
    } else if (input == 'h') {
        int newColumn = boardCreator->GetSelectedColumn() - 1;
        if (newColumn < 0) {
            newColumn = boardCreator->GetBoard()->GetSize() - 1;
        }
        boardCreator->SetSelectedColumn(newColumn);
    } else if (input == 'j') {
        int newRow = (boardCreator->GetSelectedRow() + 1) % boardCreator->GetBoard()->GetSize();
        boardCreator->SetSelectedRow(newRow);
    } else if (input == 'k') {
        int newRow = boardCreator->GetSelectedRow() - 1;
        if (newRow < 0) {
            newRow = boardCreator->GetBoard()->GetSize() - 1;
        }
        boardCreator->SetSelectedRow(newRow);
    }
    boardCreator->GetBoard()->SetSelected(true, boardCreator->GetSelectedColumn(), boardCreator->GetSelectedRow());

    if (input == 'z') {
        boardCreator->GetBoard()->Generate(Board::Difficulty::EASY);
    } else if (input == 'x') {
        boardCreator->GetBoard()->Generate(Board::Difficulty::NORMAL);
    } else if (input == 'c') {
        boardCreator->GetBoard()->Generate(Board::Difficulty::HARD);
    }

    if (input == 'q') {
        stateContext.SetState(std::make_shared<MainMenuState>());
    } else if (input == 'i') {
        stateContext.SetState(std::make_shared<InsertionBoardCreatorState>(std::move(boardCreator)));
    } else if (input == 's') {
        stateContext.SetState(std::make_shared<SaveBoardCreatorState>(std::move(boardCreator)));
    }
}

void MoveBoardCreatorState::Draw(StateContext &stateContext) {
    MoveBoardCreatorView view(boardCreator);
    view.Draw();
}
