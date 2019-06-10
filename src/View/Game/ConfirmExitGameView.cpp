//
// Created by Jakub Kiermasz on 2019-06-09.
//

#include "View/Game/ConfirmExitGameView.hpp"

ConfirmExitGameView::ConfirmExitGameView(Board board, std::string gameTime) : AbstractGameView(std::move(board), std::move(gameTime)) {}

void ConfirmExitGameView::DrawMovementInfo(int x, int y) const {
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y);
    gfx::out << Attribute::BOLD << "Are you sure you" << Position(x, y + 1);
    gfx::out << "want to exit?" << Position(x, y + 2);
    gfx::out << gfx::nodecor;
}

void ConfirmExitGameView::DrawActionsInfo(int x, int y) const {
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y);
    gfx::out << " y - To confirm" << Position(x, y + 2);
    gfx::out << " n - To cancel" << Position(x, y + 3);
    gfx::out << gfx::nodecor;
}