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

    void OnEntry(Game &game) override;

    void Update(Game &game) override;

    void OnExit(Game &game) override;

    void HandleInput(Game &game, char input) override;

    void Draw(Game &game) override;

protected:
    std::shared_ptr<BoardCreator> boardCreator;
};

#endif //HEXADOKU_ABSTRACTBOARDCREATORSTATE_HPP
