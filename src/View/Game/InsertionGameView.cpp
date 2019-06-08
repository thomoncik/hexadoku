//
// Created by Jakub Kiermasz on 2019-06-05.
//

#include "View/Game/InsertionGameView.hpp"
#include "View/Game/GameViewAbstract.hpp"
#include <utility>

InsertionGameView::InsertionGameView(Board board, std::string gameTime) : GameViewAbstract(std::move(board), std::move(gameTime)) {}

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
    gfx::out << " m - Exit insertion mode" << Position(x, y + 3);
    gfx::out << " ? - Get hint" << Position(x, y + 4);
    gfx::out << gfx::nodecor;
}