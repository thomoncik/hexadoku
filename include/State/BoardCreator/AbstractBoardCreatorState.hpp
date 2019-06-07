#ifndef HEXADOKU_ABSTRACTBOARDCREATORSTATE_HPP
#define HEXADOKU_ABSTRACTBOARDCREATORSTATE_HPP

#include <State/AbstractState.hpp>
#include <Model/BoardCreator.hpp>
#include <Model/Board.hpp>

class AbstractBoardCreatorState : public AbstractState {
public:
    explicit AbstractBoardCreatorState(int size);

    explicit AbstractBoardCreatorState(std::shared_ptr<Board> board);

    explicit AbstractBoardCreatorState(std::shared_ptr<BoardCreator> boardCreator);

    void OnEntry(StateContext &stateContext) override;

    void Update(StateContext &stateContext) override;

    void OnExit(StateContext &stateContext) override;

    void HandleInput(StateContext &stateContext, char input) override;

    void Draw(StateContext &stateContext) override;

protected:
    std::shared_ptr<BoardCreator> boardCreator;
};

#endif //HEXADOKU_ABSTRACTBOARDCREATORSTATE_HPP
