//
// Created by Jakub Kiermasz on 2019-06-05.
//

#include <utility>
#include "View/Game/InsertionGameView.hpp"
#include "View/Game/AbstractGameView.hpp"

InsertionGameView::InsertionGameView(Board board, std::string gameTime) : AbstractGameView(std::move(board), std::move(gameTime)) {}

void InsertionGameView::DrawMovementInfo(int x, int y) const {
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y);
    gfx::out << Attribute::BOLD << "Insertion";
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y + 1);
    gfx::out << " Insert value by pressing a key" << Position(x, y + 2);
    gfx::out << gfx::nodecor;
}

void InsertionGameView::DrawActionsInfo(int x, int y) const {
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y);
    gfx::out << Attribute::BOLD << "Actions";
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y + 1);
    gfx::out << " q - Quit to main menu" << Position(x, y + 2);
    gfx::out << " i - Exit insertion mode" << Position(x, y + 3);
    gfx::out << " s - Save game" << Position(x, y + 4);
    gfx::out << " ? - Get hint" << Position(x, y + 4);
    gfx::out << gfx::nodecor;
}
