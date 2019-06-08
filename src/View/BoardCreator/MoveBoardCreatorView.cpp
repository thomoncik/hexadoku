#include <View/BoardCreator/MoveBoardCreatorView.hpp>
#include <Graphics/Attributes.hpp>
#include <Graphics/GfxStream.hpp>
#include <Model/BoardCreator.hpp>

MoveBoardCreatorView::MoveBoardCreatorView(std::shared_ptr<BoardCreator> boardCreator) :
        AbstractBoardCreatorView(std::move(boardCreator)) {

}

void MoveBoardCreatorView::DrawActionsInfo(int x, int y) const {
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y);
    gfx::out << Attribute::BOLD << "Actions";
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y + 1);
    gfx::out << " q - Quit to main menu" << Position(x, y + 2);
    gfx::out << " i - Enter insertion mode" << Position(x, y + 3);
    gfx::out << " s - Save board to file" << Position(x, y + 4);
    gfx::out << " z - Generate easy board" << Position(x, y + 5);
    gfx::out << " x - Generate normal board" << Position(x, y + 6);
    gfx::out << " c - Generate hard board" << Position(x, y + 7);
    gfx::out << gfx::nodecor;
}

void MoveBoardCreatorView::DrawMovementInfo(int x, int y) const {
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y);
    gfx::out << Attribute::BOLD << "Movement";
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y + 1);
    gfx::out << " h - Move left" << Position(x, y + 2);
    gfx::out << " j - Move down" << Position(x, y + 3);
    gfx::out << " k - Move up" << Position(x, y + 4);
    gfx::out << " l - Move right" << Position(x, y + 5);
    gfx::out << gfx::nodecor;
}
