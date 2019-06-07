#include <utility>
#include <View/Game/AbstractGameView.hpp>
#include <View/Board/BoardView.hpp>


AbstractGameView::AbstractGameView(Board board, std::string gameTime) : board(std::move(board)), gameTime(std::move(gameTime)) {}

void AbstractGameView::Draw() const {
    BoardView boardView(this->board);
    boardView.SetPosition(this->x + 4, this->y + 2);
    boardView.Draw();

    this->DrawInfo();
    this->DrawGameTime(70, 1);
}

void AbstractGameView::DrawInfo() const {
    this->DrawMovementInfo(this->x + this->board.GetSize() * 5, this->y + 2);
    this->DrawActionsInfo(this->x + this->board.GetSize() * 5, this->y + 8);
}

void AbstractGameView::DrawGameTime(int x, int y) const {
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y);
    gfx::out << Attribute::BOLD << gameTime;
    gfx::out << gfx::nodecor;
}
