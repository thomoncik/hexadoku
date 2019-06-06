#ifndef HEXADOKU_BOARDCRETORVIEWABSTRACT_HPP
#define HEXADOKU_BOARDCRETORVIEWABSTRACT_HPP

#include <memory>
#include <Model/Board.hpp>
#include <Model/BoardCreator.hpp>
#include <View/AbstractView.hpp>

class BoardCreatorViewAbstract : public AbstractView {
public:
    explicit BoardCreatorViewAbstract(std::shared_ptr<BoardCreator> boardCreator);

    void Draw() const override;

protected:
    virtual void DrawActionsInfo(int x, int y) const = 0;

    virtual void DrawMovementInfo(int x, int y) const = 0;

private:
    std::shared_ptr<BoardCreator> boardCreator;
};

#endif //HEXADOKU_BOARDCRETORVIEWABSTRACT_HPP
