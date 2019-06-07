#include <View/BoardCreator/InsertionBoardCreatorView.hpp>
#include <State/Menu/MainMenuState.hpp>
#include <State/BoardCreator/MoveBoardCreatorState.hpp>
#include <State/BoardCreator/InsertionBoardCreatorState.hpp>
#include <algorithm>

InsertionBoardCreatorState::InsertionBoardCreatorState(int size) : AbstractBoardCreatorState(size) {

}

InsertionBoardCreatorState::InsertionBoardCreatorState(std::shared_ptr<Board> board)
        : AbstractBoardCreatorState(std::move(board)) {

}

InsertionBoardCreatorState::InsertionBoardCreatorState(std::shared_ptr<BoardCreator> boardCreator)
        : AbstractBoardCreatorState(std::move(boardCreator)) {

}

void InsertionBoardCreatorState::HandleInput(Game &game, char input) {
    std::vector<char> boardCharacters;
    boardCharacters = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    if (boardCreator->GetBoard()->GetSize() == Board::STANDARD_SIZE) {
        boardCharacters = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    } else if (boardCreator->GetBoard()->GetSize() == Board::HEXADOKU_SIZE) {
        boardCharacters = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', '0'};
    }

    if (std::find(boardCharacters.begin(), boardCharacters.end(), input) != boardCharacters.end()) {
        auto value = distance(boardCharacters.begin(), find(boardCharacters.begin(), boardCharacters.end(), input));
        boardCreator->SetValue(value, boardCreator->GetSelectedColumn(), boardCreator->GetSelectedRow());
    }

    if (input == 'z') {
        boardCreator->GetBoard()->Generate(Board::Difficulty::EASY);
    } else if (input == 'x') {
        boardCreator->GetBoard()->Generate(Board::Difficulty::NORMAL);
    } else if (input == 'c') {
        boardCreator->GetBoard()->Generate(Board::Difficulty::HARD);
    }

    if (input == 'q') {
        game.SetState(std::make_shared<MainMenuState>());
    } else if (input == 'm') {
        game.SetState(std::make_shared<MoveBoardCreatorState>(std::move(boardCreator)));
    }
}

void InsertionBoardCreatorState::Draw(Game &game) {
    InsertionBoardCreatorView view(boardCreator);
    view.Draw();
}