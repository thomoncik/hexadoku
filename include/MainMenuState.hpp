#ifndef HEXADOKU_MAINMENUSTATE_HPP
#define HEXADOKU_MAINMENUSTATE_HPP

#include "AbstractState.hpp"

#include <string>
#include <map>

class MainMenuState : public AbstractState {
public:
    enum class Option {
        NEW_GAME = 0,
        BOARD_CREATOR,
        EXIT,
    };

    static const std::string HEXADOKU_LOGO;
    static const std::map<MainMenuState::Option, std::string> MENU_OPTIONS;

    MainMenuState();

    void Update() override;

    void HandleInput(char input) override;

    void Draw() override;

private:
    unsigned selectedOption;
};

#endif //HEXADOKU_MAINMENUSTATE_HPP
