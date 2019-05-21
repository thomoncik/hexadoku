#include <utility>

#include <utility>
#include <View/GameView.hpp>
#include <View/BoardView.hpp>
#include <Color.hpp>
#include <GfxStream.hpp>
#include <Attributes.hpp>

GameView::GameView(Board board, std::string gameTime) : board(std::move(board)), gameTime(std::move(gameTime)) {

}

void GameView::Draw() const {
    BoardView boardView(this->board);
    boardView.SetPosition(this->x + 4, this->y + 2);
    boardView.Draw();

    this->DrawInfo();
    this->DrawGameTime(70, 1);
}

void GameView::DrawInfo() const {
    this->DrawMovementInfo(this->x + this->board.GetSize() * 5, this->y + 2);
    this->DrawActionsInfo(this->x + this->board.GetSize() * 5, this->y + 8);
}

void GameView::DrawMovementInfo(int x, int y) const {
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y);
    gfx::out << Attribute::BOLD << "Movement";
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y + 1);
    gfx::out << " h - Move left" << Position(x, y + 2);
    gfx::out << " j - Move down" << Position(x, y + 3);
    gfx::out << " k - Move up" << Position(x, y + 4);
    gfx::out << " l - Move right" << Position(x, y + 5);
    gfx::out << gfx::nodecor;
}

void GameView::DrawActionsInfo(int x, int y) const {
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y);
    gfx::out << Attribute::BOLD << "Actions";
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y + 1);
    gfx::out << " q - Quit to main menu" << Position(x, y + 2);
    gfx::out << " m - Enter value" << Position(x, y + 3);
    gfx::out << gfx::nodecor;
}

void GameView::DrawGameTime(int x, int y) const {
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y);
    gfx::out << Attribute::BOLD << gameTime;
    gfx::out << gfx::nodecor;
}
