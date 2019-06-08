//
// Created by Jakub Kiermasz on 2019-06-05.
//

#include <View/Game/MoveGameView.hpp>
#include <View/Game/GameViewAbstract.hpp>
#include <utility>


MoveGameView::MoveGameView(Board board, std::string gameTime) : GameViewAbstract(std::move(board), std::move(gameTime)) {}

void MoveGameView::DrawMovementInfo(int x, int y) const {
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y);
    gfx::out << Attribute::BOLD << "Movement";
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y + 1);
    gfx::out << " h - Move left" << Position(x, y + 2);
    gfx::out << " j - Move down" << Position(x, y + 3);
    gfx::out << " k - Move up" << Position(x, y + 4);
    gfx::out << " l - Move right" << Position(x, y + 5);
    gfx::out << gfx::nodecor;
}

void MoveGameView::DrawActionsInfo(int x, int y) const {
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y);
    gfx::out << Attribute::BOLD << "Actions";
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y + 1);
    gfx::out << " q - Quit to main menu" << Position(x, y + 2);
    gfx::out << " m - Enter insertion mode" << Position(x, y + 3);
    gfx::out << " ? - Get hint" << Position(x, y + 4);
    gfx::out << gfx::nodecor;
}