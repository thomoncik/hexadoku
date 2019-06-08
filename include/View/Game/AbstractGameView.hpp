#ifndef HEXADOKU_ABSTRACTGAMEVIEW_HPP
#define HEXADOKU_ABSTRACTGAMEVIEW_HPP

#include <string>
#include <Model/Board.hpp>
#include "View/AbstractView.hpp"
#include <Graphics/Color.hpp>
#include <Graphics/GfxStream.hpp>
#include <Graphics/Attributes.hpp>

class AbstractGameView : public AbstractView {
public:
    explicit AbstractGameView(Board board, std::string gameTime);

    void Draw() const override;

protected:
    virtual void DrawMovementInfo(int x, int y) const = 0;

    virtual void DrawActionsInfo(int x, int y) const = 0;

private:
    Board board;
    std::string gameTime;

    void DrawInfo() const;

    void DrawGameTime(int x, int y) const;
};

#endif //HEXADOKU_ABSTRACTGAMEVIEW_HPP
