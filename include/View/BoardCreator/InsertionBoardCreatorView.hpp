#ifndef HEXADOKU_INSERTIONBOARDCREATORVIEW_HPP
#define HEXADOKU_INSERTIONBOARDCREATORVIEW_HPP

#include <View/BoardCreator/AbstractBoardCreatorView.hpp>

class InsertionBoardCreatorView : public AbstractBoardCreatorView {
public:
    explicit InsertionBoardCreatorView(std::shared_ptr<BoardCreator> boardCreator);

protected:
    void DrawActionsInfo(int x, int y) const override;

    void DrawMovementInfo(int x, int y) const override;

};

#endif //HEXADOKU_INSERTIONBOARDCREATORVIEW_HPP
