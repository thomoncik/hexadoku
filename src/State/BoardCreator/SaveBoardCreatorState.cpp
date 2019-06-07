#include <State/BoardCreator/SaveBoardCreatorState.hpp>
#include <Graphics/GfxStream.hpp>
#include <State/BoardCreator/MoveBoardCreatorState.hpp>
#include <iomanip>

const int SaveBoardCreatorState::MAX_FILENAME_LENGTH = 20;

SaveBoardCreatorState::SaveBoardCreatorState(int size) : AbstractBoardCreatorState(size) {

}

SaveBoardCreatorState::SaveBoardCreatorState(std::shared_ptr<Board> board) :
        AbstractBoardCreatorState(std::move(board)) {

}

SaveBoardCreatorState::SaveBoardCreatorState(std::shared_ptr<BoardCreator> boardCreator) :
        AbstractBoardCreatorState(std::move(boardCreator)) {

}

void SaveBoardCreatorState::HandleInput(StateContext &game, char input) {
    if (isalnum(input) && filename.length() < MAX_FILENAME_LENGTH) {
        filename += input;
    } else if (filename.length() > 0 && (input == 127 || input == 8)) { // backspace
        filename.pop_back();
    } else if (input == '\n') {
        if (boardCreator->GetBoard()->GetSize() == Board::STANDARD_SIZE) {
            filename = Board::SAVED_STANDARD_BOARD_PATH + filename;
        } else if (boardCreator->GetBoard()->GetSize() == Board::HEXADOKU_SIZE) {
            filename = Board::SAVED_HEXADOKU_BOARD_PATH + filename;
        }
        boardCreator->GetBoard()->SaveToFile(filename);
        game.SetState(std::make_shared<MoveBoardCreatorState>(std::move(boardCreator)));
    } else if (input == 27) { // ESC
        game.SetState(std::make_shared<MoveBoardCreatorState>(std::move(boardCreator)));
    }
}

void SaveBoardCreatorState::Draw(StateContext &game) {
    const int x = boardCreator->GetBoard()->GetSize() * 4 + 7;
    const int y = boardCreator->GetBoard()->GetSize() * 2;

    gfx::out << gfx::nodecor;
    gfx::out << Position(x, y) << "Save as: " << std::string(MAX_FILENAME_LENGTH, ' ');
    gfx::out << Position(x, y) << "Save as: " << filename;
    gfx::out << Position(x, y + 1) << Color::Yellow << "  or press ESC to go back";
    gfx::out << Position(x, y + 2) << "  to creator without saving";
    gfx::out << gfx::nodecor;
}
