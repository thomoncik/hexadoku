//
// Created by thomoncik on 09.05.19.
//

#ifndef HEXADOKU_PLAYSTATE_HPP
#define HEXADOKU_PLAYSTATE_HPP

#include "AbstractState.hpp"
#include "Model/Board.hpp"
#include "Tools/StringConverter.hpp"


class PlayState : public AbstractState {
public:
    PlayState(int boardSize);

    void OnEntry(Game &game) override;

    void Update(Game &game) override;

    void HandleInput(Game &game, char input) override;

    void Draw(Game &game) override;

    void OnExit(Game &game) override;
private:
    Board board;
    time_t creationTime;
    time_t gameTime;
    StringConverter stringConverter;
    void DisplayBoard(int posX, int posY);
    void DisplaySection(const BoardSection & bs, int posX, int posY, bool shouldPrintRightEdge, bool shouldPrintBottomEdge);
    std::wstring GetGameTimeString() const;
};


#endif //HEXADOKU_PLAYSTATE_HPP
