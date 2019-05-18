#include "../include/PlayState.hpp"
#include "../include/GfxStream.hpp"
#include "../include/MenuState.hpp"

#include <memory>
#include <chrono>

PlayState::PlayState(int boardSize) : board(Board(boardSize)), stringConverter(StringConverter()) {
    creationTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    gameTime = creationTime;
}

void PlayState::OnEntry(Game &game) {
    gfx::out << gfx::clear;
}

void PlayState::Update(Game &game) {
    gameTime = creationTime - std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

void PlayState::HandleInput(Game &game, char input) {
    if (input == 'q') {
        game.SetState(MenuState::MAIN_MENU);
    }
}

void PlayState::Draw(Game &game) {
    gfx::out << Color::Red;
    gfx::out << Position(70, 1) << GetGameTimeString();
    DisplayBoard(2, 2);
    gfx::out << gfx::nodecor;
}

void PlayState::OnExit(Game &game) {

}

void PlayState::DisplayBoard(int posX, int posY) {
    int sectionViewWidth = (board.GetSize() == Board::STANDARD_SIZE) ? 12 : 777;
    int sectionViewHeight = (board.GetSize() == Board::STANDARD_SIZE) ? 6 : 777;
    int numberOfSectionsPerDimension = board.GetSectionSize();
    int sectionIndex = 0;
    for (int i = 0; i < numberOfSectionsPerDimension; ++i) {
        for (int j = 0; j < numberOfSectionsPerDimension; ++j) {
            DisplaySection(board.GetSection(sectionIndex), posX + j * sectionViewWidth, posY + i * sectionViewHeight, j == (numberOfSectionsPerDimension - 1), i == (numberOfSectionsPerDimension - 1));
            sectionIndex++;
        }
    }
}

void PlayState::DisplaySection(const BoardSection &bs, int posX, int posY, bool shouldPrintRightEdge, bool shouldPrintBottomEdge) {
    gfx::out << Position(posX, posY);
    gfx::out << "+";
    int y = posY;
    for (int i = 0; i < board.GetSectionSize(); ++i) {
        gfx::out << Position(((i == 0) ? posX + 1 : posX), y);
        for (int j = 0; j < board.GetSectionSize(); ++j) {
            gfx::out << ((i == 0 && j == 0) ? "===" : "====");
        }
        gfx::out << "=";
        y++;
        gfx::out << Position(posX, y);
        gfx::out << "|";
        for (int j = 0; j < board.GetSectionSize(); ++j) {
            gfx::out << ((j == board.GetSectionSize() - 1 && !shouldPrintRightEdge) ? "   " : "   |");
        }
        y++;
    }
    if (shouldPrintBottomEdge) {
        gfx::out << Position(posX, y) << "+";
        gfx::out << Position(posX + 1, y);
        for (int j = 0; j < board.GetSectionSize(); ++j) {
            gfx::out << (( j == 0) ? "===" : "====");
        }
        if (shouldPrintRightEdge) {
            gfx::out << "+";
        }
    }
}

std::wstring PlayState::GetGameTimeString() const {
    char buf[50];
    std::strftime(buf, sizeof(buf), "%M:%S", localtime(&gameTime));
    std::string str(buf);
    return stringConverter.StringToWstring(str);
}
