#include <View/BoardCreator/InsertionBoardCreatorView.hpp>
#include <Graphics/Attributes.hpp>
#include <Graphics/GfxStream.hpp>
#include <Model/BoardCreator.hpp>

InsertionBoardCreatorView::InsertionBoardCreatorView(std::shared_ptr<BoardCreator> boardCreator) :
        AbstractBoardCreatorView(std::move(boardCreator)) {

}

void InsertionBoardCreatorView::DrawActionsInfo(int x, int y) const {
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y);
    gfx::out << Attribute::BOLD << "Actions";
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y + 1);
    gfx::out << " q - Quit to main menu" << Position(x, y + 2);
    gfx::out << " i -Exit insertion mode" << Position(x, y + 3);
    gfx::out << " s - Save board to file" << Position(x, y + 4);
    gfx::out << " z - Generate easy board" << Position(x, y + 5);
    gfx::out << " x - Generate normal board" << Position(x, y + 6);
    gfx::out << " c - Generate hard board";
    gfx::out << gfx::nodecor;
}

void InsertionBoardCreatorView::DrawMovementInfo(int x, int y) const {
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y);
    gfx::out << Attribute::BOLD << "Insertion";
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y + 1);
    gfx::out << " Insert value by pressing a key" << Position(x, y + 2);
    gfx::out << " Use space bar to erase cell value";
    gfx::out << gfx::nodecor;
}
