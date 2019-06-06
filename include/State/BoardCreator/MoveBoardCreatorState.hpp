#ifndef HEXADOKU_MOVEBOARDCREATORSTATE_HPP
#define HEXADOKU_MOVEBOARDCREATORSTATE_HPP

#include <State/AbstractState.hpp>
#include <State/BoardCreator/AbstractBoardCreatorState.hpp>

class MoveBoardCreatorState : public AbstractBoardCreatorState {
public:
    explicit MoveBoardCreatorState(int size);

    explicit MoveBoardCreatorState(std::shared_ptr<Board> board);

    explicit MoveBoardCreatorState(std::shared_ptr<BoardCreator> boardCreator);

    void HandleInput(Game &game, char input) override;

    void Draw(Game &game) override;

};

#endif //HEXADOKU_INSERTIONBOARDCREATORSTATE_HPP
