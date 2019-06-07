#ifndef HEXADOKU_MOVEBOARDCREATORVIEW_HPP
#define HEXADOKU_MOVEBOARDCREATORVIEW_HPP

#include <View/BoardCreator/AbstractBoardCreatorView.hpp>

class MoveBoardCreatorView : public AbstractBoardCreatorView {
public:
    explicit MoveBoardCreatorView(std::shared_ptr<BoardCreator> boardCreator);

protected:
    void DrawActionsInfo(int x, int y) const override;

    void DrawMovementInfo(int x, int y) const override;

};

#endif //HEXADOKU_MOVEBOARDCREATORVIEW_HPP
