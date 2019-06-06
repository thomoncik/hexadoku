#ifndef HEXADOKU_BOARDCREATORSTATE_HPP
#define HEXADOKU_BOARDCREATORSTATE_HPP

#include <State/AbstractState.hpp>

class BoardCreatorState : public AbstractState {
public:
    explicit BoardCreatorState(int size);

    void OnEntry(Game &game) override;

    void Update(Game &game) override;

    void HandleInput(Game &game, char input) override;

    void Draw(Game &game) override;

    void OnExit(Game &game) override;

private:
    int size;
};

#endif //HEXADOKU_BOARDCREATORSTATE_HPP
