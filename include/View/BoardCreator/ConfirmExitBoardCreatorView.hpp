//
// Created by Jakub Kiermasz on 2019-06-10.
//

#ifndef HEXADOKU_CONFIRMEXITBOARDCREATORVIEW_HPP
#define HEXADOKU_CONFIRMEXITBOARDCREATORVIEW_HPP

#include <View/BoardCreator/AbstractBoardCreatorView.hpp>

class ConfirmExitBoardCreatorView : public AbstractBoardCreatorView {
public:
    explicit ConfirmExitBoardCreatorView(std::shared_ptr<BoardCreator> boardCreator);

protected:
    void DrawActionsInfo(int x, int y) const override;

    void DrawMovementInfo(int x, int y) const override;
};


#endif //HEXADOKU_CONFIRMEXITBOARDCREATORVIEW_HPP
