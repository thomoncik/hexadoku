//
// Created by Jakub Kiermasz on 2019-06-10.
//

#include "View/BoardCreator/ConfirmExitBoardCreatorView.hpp"
#include <Graphics/Attributes.hpp>
#include <Graphics/GfxStream.hpp>
#include <Model/BoardCreator.hpp>

ConfirmExitBoardCreatorView::ConfirmExitBoardCreatorView(std::shared_ptr<BoardCreator> boardCreator) :
        AbstractBoardCreatorView(std::move(boardCreator)) {

}

void ConfirmExitBoardCreatorView::DrawActionsInfo(int x, int y) const {
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y);
    gfx::out << Attribute::BOLD << "Are you sure you" << Position(x, y + 1);
    gfx::out << "want to exit?" << Position(x, y + 2);
    gfx::out << gfx::nodecor;
}

void ConfirmExitBoardCreatorView::DrawMovementInfo(int x, int y) const {
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y);
    gfx::out << " y - To confirm" << Position(x, y + 2);
    gfx::out << " n - To cancel" << Position(x, y + 3);
    gfx::out << gfx::nodecor;
}
