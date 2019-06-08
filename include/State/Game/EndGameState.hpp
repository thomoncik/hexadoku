#ifndef HEXADOKU_ENDGAMESTATE_HPP
#define HEXADOKU_ENDGAMESTATE_HPP


#include <State/AbstractState.hpp>
#include <Model/PlayStateModel.hpp>

class EndGameState : public AbstractState {
public:
    explicit EndGameState(std::shared_ptr<PlayStateModel> playStateModel);

    void OnEntry(Game &game) override;

    void Update(Game &game) override;

    void HandleInput(Game &game, char input) override;

    void Draw(Game &game) override;

    void OnExit(Game &game) override;

private:
    std::shared_ptr<PlayStateModel> playStateModel;
    std::string timeUsed;
};


#endif //HEXADOKU_ENDGAMESTATE_HPP
