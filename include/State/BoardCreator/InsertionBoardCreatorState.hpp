#ifndef HEXADOKU_INSERTIONBOARDCREATORSTATE_HPP
#define HEXADOKU_INSERTIONBOARDCREATORSTATE_HPP

#include <State/AbstractState.hpp>
#include <State/BoardCreator/AbstractBoardCreatorState.hpp>

class InsertionBoardCreatorState : public AbstractBoardCreatorState {
public:
    explicit InsertionBoardCreatorState(int size);

    explicit InsertionBoardCreatorState(std::shared_ptr<Board> board);

    explicit InsertionBoardCreatorState(std::shared_ptr<BoardCreator> boardCreator);

    void HandleInput(StateContext &stateContext, char input) override;

    void Draw(StateContext &stateContext) override;

};

#endif //HEXADOKU_INSERTIONBOARDCREATORSTATE_HPP
