#include <View/BoardCreator/BoardCreatorViewAbstract.hpp>
#include <View/Board/BoardView.hpp>
#include <Graphics/GfxStream.hpp>

BoardCreatorViewAbstract::BoardCreatorViewAbstract(std::shared_ptr<BoardCreator> boardCreator) :
        boardCreator(std::move(boardCreator)) {

}


void BoardCreatorViewAbstract::Draw() const {
    gfx::out << gfx::clear;

    BoardView boardView(*boardCreator->GetBoard());
    boardView.SetPosition(2, 2);
    boardView.Draw();

    DrawMovementInfo(boardCreator->GetBoard()->GetSize() * 4 + 7, 2);
    DrawActionsInfo(boardCreator->GetBoard()->GetSize() * 4 + 7, 10);
}
