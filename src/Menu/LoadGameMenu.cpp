#include <utility>

#include <Menu/LoadGameMenu.hpp>
#include <boost/filesystem.hpp>
#include <Graphics/GfxStream.hpp>
#include <iomanip>
#include <Graphics/Attributes.hpp>
#include <Model/Board.hpp>
#include <State/MovePlayState.hpp>
#include <Graphics/Assets.hpp>

LoadGameMenu::LoadGameMenu(int size) : size(size) {
    if (size == Board::STANDARD_SIZE) {
        loadingPath = Board::SAVED_STANDARD_BOARD_PATH;
    } else if (size == Board::HEXADOKU_SIZE) {
        loadingPath = Board::SAVED_HEXADOKU_BOARD_PATH;
    }
}

void LoadGameMenu::OnEntry(Game &game) {
    filePathToName.clear();
    for (const auto &entry : boost::filesystem::directory_iterator(loadingPath)) {
        filePathToName[entry.path().filename().string()] = entry.path().stem().string();
    }
    option = filePathToName.begin();
}

void LoadGameMenu::Update(Game &game) {

}

void LoadGameMenu::HandleInput(Game &game, char input) {
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
        auto board = std::make_shared<Board>(size);
        board->LoadFromFile(option->first);

        game.SetState(std::make_shared<MovePlayState>(size, board));
    }
}

void LoadGameMenu::Draw(Game &game) {
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

void LoadGameMenu::OnExit(Game &game) {

}
