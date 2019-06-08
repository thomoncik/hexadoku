#include <utility>

#include <State/Menu/LoadGameMenuState.hpp>
#include <boost/filesystem.hpp>
#include <Graphics/GfxStream.hpp>
#include <iomanip>
#include <Graphics/Attributes.hpp>
#include <Model/Board.hpp>
#include <State/Game/MoveGameState.hpp>
#include <Graphics/Assets.hpp>

LoadGameMenuState::LoadGameMenuState(int size) : size(size) {
    if (size == Board::STANDARD_SIZE) {
        loadingPath = Game::SAVED_STANDARD_GAME_PATH;
    } else if (size == Board::HEXADOKU_SIZE) {
        loadingPath = Game::SAVED_HEXADOKU_GAME_PATH;
    }
}

void LoadGameMenuState::OnEntry(StateContext &stateContext) {
    filePathToName.clear();
    for (const auto &entry : boost::filesystem::directory_iterator(loadingPath)) {
        if (entry.path().extension().string() == Game::SAVED_GAME_FILE_EXTENSION) {
            filePathToName[entry.path().string()] = entry.path().stem().string();
        }
    }
    option = filePathToName.begin();
}

void LoadGameMenuState::Update(StateContext &stateContext) {

}

void LoadGameMenuState::HandleInput(StateContext &stateContext, char input) {
    if (input == 'j') {
        option++;
        if (option == filePathToName.end()) {
            option = filePathToName.begin();
        }
    } else if (input == 'k') {
        if (option == filePathToName.begin()) {
            option = filePathToName.end();
        }
        option--;
    } else if (input == ' ') {
        auto game = std::make_shared<Game>(size);
        game->LoadFromFile(option->first);

        stateContext.SetState(std::make_shared<MoveGameState>(game));
    }
}

void LoadGameMenuState::Draw(StateContext &stateContext) {
    gfx::out << gfx::clear;
    gfx::out << Position(0, 3) << Color::Blue << Attribute::BOLD;
    gfx::out << Assets::HEXADOKU_LOGO << gfx::nodecor;

    auto filesIterator = option;
    for (int i = 0; i < 5; ++i) {
        if (filesIterator == filePathToName.begin()) {
            break;
        }
        filesIterator--;
    }

    for (int i = 0; i < 11 && filesIterator != filePathToName.end(); ++filesIterator, ++i) {
        gfx::out << Position(25, 13 + i) << std::setw(20);
        if (option == filesIterator) {
            gfx::out << Attribute::STANDOUT;
        }
        gfx::out << filesIterator->second.substr(0, 20) << gfx::nodecor;
    }
}

void LoadGameMenuState::OnExit(StateContext &stateContext) {

}
