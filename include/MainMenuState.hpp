#ifndef HEXADOKU_MAINMENUSTATE_HPP
#define HEXADOKU_MAINMENUSTATE_HPP

#include "AbstractMenuState.hpp"
#include <string>

class MainMenuState : public AbstractMenuState {
public:
    static const std::string NEW_GAME_OPTION;
    static const std::string BOARD_CREATOR_OPTION;
    static const std::string EXIT_OPTION;

    MainMenuState();

protected:
    void UseOption(Game &game, const std::string &option) override;
};

#endif //HEXADOKU_MAINMENUSTATE_HPP
