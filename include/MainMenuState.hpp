#ifndef HEXADOKU_MAINMENUSTATE_HPP
#define HEXADOKU_MAINMENUSTATE_HPP

#include "AbstractState.hpp"
#include "Assets.hpp"

#include <string>
#include <map>

class MainMenuState : public AbstractState {
public:
    enum class Option {
        NEW_GAME = 0,
        BOARD_CREATOR,
        EXIT,
    };

    static const std::map<MainMenuState::Option, std::string> MENU_OPTIONS;

    MainMenuState();

    void OnEntry(Game &game) override;

    void Update(Game &game) override;

    void HandleInput(Game &game, char input) override;

    void Draw(Game &game) override;

    void OnExit(Game &game) override;

private:
    unsigned selectedOption;
};

#endif //HEXADOKU_MAINMENUSTATE_HPP
