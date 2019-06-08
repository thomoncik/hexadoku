#ifndef HEXADOKU_SAVEBOARDCREATORSTATE_HPP
#define HEXADOKU_SAVEBOARDCREATORSTATE_HPP

#include <State/BoardCreator/AbstractBoardCreatorState.hpp>

class SaveBoardCreatorState : public AbstractBoardCreatorState {
public:
    static const int MAX_FILENAME_LENGTH;

    explicit SaveBoardCreatorState(int size);

    explicit SaveBoardCreatorState(std::shared_ptr<Board> board);

    explicit SaveBoardCreatorState(std::shared_ptr<BoardCreator> boardCreator);

    void HandleInput(StateContext &stateContext, char input) override;

    void Draw(StateContext &stateContext) override;

private:
    std::string filename{};
};


#endif //HEXADOKU_SAVEBOARDCREATORSTATE_HPP
