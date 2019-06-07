#include <utility>
#include <View/Game/GameViewAbstract.hpp>
#include <View/Board/BoardView.hpp>


GameViewAbstract::GameViewAbstract(Board board, std::string gameTime) : board(std::move(board)), gameTime(std::move(gameTime)) {}

void GameViewAbstract::Draw() const {
    BoardView boardView(this->board);
    boardView.SetPosition(this->x + 4, this->y + 2);
    boardView.Draw();

    this->DrawInfo();
    this->DrawGameTime(70, 1);
}

void GameViewAbstract::DrawInfo() const {
    this->DrawMovementInfo(this->x + this->board.GetSize() * 5, this->y + 2);
    this->DrawActionsInfo(this->x + this->board.GetSize() * 5, this->y + 8);
}

void GameViewAbstract::DrawGameTime(int x, int y) const {
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y);
    gfx::out << Attribute::BOLD << gameTime;
    gfx::out << gfx::nodecor;
}
