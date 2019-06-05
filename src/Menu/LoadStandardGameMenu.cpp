#include <Menu/LoadStandardGameMenu.hpp>
#include <Model/Board.hpp>
#include <boost/filesystem.hpp>
#include <Graphics/GfxStream.hpp>

LoadStandardGameMenu::LoadStandardGameMenu() {

}


void LoadStandardGameMenu::UseOption(Game &game, const std::string &option) {

}

void LoadStandardGameMenu::OnEntry(Game &game) {
    for (const auto & entry : boost::filesystem::directory_iterator(Board::SAVED_STANDARD_BOARD_PATH))
        gfx::out << entry.path().stem().string() << std::endl;
}
