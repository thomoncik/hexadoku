#ifndef HEXADOKU_ENDGAMESTATE_HPP
#define HEXADOKU_ENDGAMESTATE_HPP


#include <State/AbstractState.hpp>
#include <Model/Game.hpp>

class EndGameState : public AbstractState {
public:
    explicit EndGameState(std::shared_ptr<Game> game);

    void OnEntry(StateContext &stateContext) override;

    void Update(StateContext &stateContext) override;

    void HandleInput(StateContext &stateContext, char input) override;

    void Draw(StateContext &stateContext) override;

    void OnExit(StateContext &stateContext) override;

private:
    std::shared_ptr<Game> game;
    std::string timeUsed;
};


#endif //HEXADOKU_ENDGAMESTATE_HPP
