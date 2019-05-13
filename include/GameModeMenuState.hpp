//
// Created by Jakub Kiermasz on 2019-05-11.
//

#ifndef HEXADOKU_GAMEMODEMENUSTATE_HPP
#define HEXADOKU_GAMEMODEMENUSTATE_HPP


#include "AbstractState.hpp"
#include "Assets.hpp"

#include <string>
#include <map>

class GameModeMenuState : public AbstractState {
public:
    enum class Option {
        STANDARD = 0,
        HEXADOKU,
        LOAD_YOUR_OWN,
        BACK,
    };

    static const std::map<GameModeMenuState::Option, std::wstring> GAMEMODE_OPTIONS;

    GameModeMenuState();

    void OnEntry(Game &game) override;

    void Update(Game &game) override;

    void HandleInput(Game &game, char input) override;

    void Draw(Game &game) override;

    void OnExit(Game &game) override;

private:
    unsigned selectedOption;
};


#endif //HEXADOKU_GAMEMODEMENUSTATE_HPP
