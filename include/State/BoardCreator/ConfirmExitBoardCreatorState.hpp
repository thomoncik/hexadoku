//
// Created by Jakub Kiermasz on 2019-06-10.
//

#ifndef HEXADOKU_CONFIRMEXITBOARDCREATORSTATE_HPP
#define HEXADOKU_CONFIRMEXITBOARDCREATORSTATE_HPP

#include "AbstractBoardCreatorState.hpp"

class ConfirmExitBoardCreatorState : public AbstractBoardCreatorState {
public:
    explicit ConfirmExitBoardCreatorState(bool wasInsertionEnabled, std::shared_ptr<BoardCreator> boardCreator);

    void HandleInput(StateContext &stateContext, char input) override;

    void Draw(StateContext &stateContext) override;
private:
    bool wasInsertionEnabled;
};


#endif //HEXADOKU_CONFIRMEXITBOARDCREATORSTATE_HPP
