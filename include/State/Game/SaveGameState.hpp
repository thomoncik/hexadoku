#ifndef HEXADOKU_SAVEGAMESTATE_HPP
#define HEXADOKU_SAVEGAMESTATE_HPP

#include <State/Game/AbstractGameState.hpp>

class SaveGameState : public AbstractGameState {
public:
    static const int MAX_FILENAME_LENGTH;

    explicit SaveGameState(std::shared_ptr<Game> model);

    void HandleInput(StateContext &stateContext, char input) override;

    void Draw(StateContext &stateContext) override;

private:
    std::string filename{};
};


#endif //HEXADOKU_SAVEGAMESTATE_HPP
