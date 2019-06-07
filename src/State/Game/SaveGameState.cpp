#include <State/Game/SaveGameState.hpp>
#include <State/Game/MoveGameState.hpp>
#include <Graphics/GfxStream.hpp>

const int SaveGameState::MAX_FILENAME_LENGTH = 20;

SaveGameState::SaveGameState(std::shared_ptr<Game> game) : AbstractGameState(std::move(game)) {

}

void SaveGameState::HandleInput(StateContext &stateContext, char input) {
    if (isalnum(input) && filename.length() < MAX_FILENAME_LENGTH) {
        filename += input;
    } else if (filename.length() > 0 && (input == 127 || input == 8)) { // backspace
        filename.pop_back();
    } else if (input == '\n') {
        if (game->GetBoard()->GetSize() == Board::STANDARD_SIZE) {
            filename = Game::SAVED_STANDARD_GAME_PATH + filename;
        } else if (game->GetBoard()->GetSize() == Board::HEXADOKU_SIZE) {
            filename = Game::SAVED_HEXADOKU_GAME_PATH + filename;
        }
        game->SaveToFile(filename);
        stateContext.SetState(std::make_shared<MoveGameState>(std::move(game)));
    } else if (input == 27) { // ESC
        stateContext.SetState(std::make_shared<MoveGameState>(std::move(game)));
    }
}

void SaveGameState::Draw(StateContext &stateContext) {
    const int x = game->GetBoard()->GetSize() * 4 + 7;
    const int y = game->GetBoard()->GetSize() * 2;

    gfx::out << gfx::nodecor;
    gfx::out << Position(x, y) << "Save as: " << std::string(MAX_FILENAME_LENGTH, ' ');
    gfx::out << Position(x, y) << "Save as: " << filename;
    gfx::out << Position(x, y + 1) << Color::Yellow << "  or press ESC to go back";
    gfx::out << Position(x, y + 2) << "  without saving";
    gfx::out << gfx::nodecor;
}