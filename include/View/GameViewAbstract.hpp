#ifndef HEXADOKU_GAMEVIEWABSTRACT_HPP
#define HEXADOKU_GAMEVIEWABSTRACT_HPP

#include <string>
#include <Model/Board.hpp>
#include "AbstractView.hpp"
#include <Graphics/Color.hpp>
#include <Graphics/GfxStream.hpp>
#include <Graphics/Attributes.hpp>

class GameViewAbstract : public AbstractView {
public:
    explicit GameViewAbstract(Board board, std::string gameTime);

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

#endif //HEXADOKU_GAMEVIEWABSTRACT_HPP
