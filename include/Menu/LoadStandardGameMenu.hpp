#ifndef HEXADOKU_LOADSTANDARDGAMEMENU_HPP
#define HEXADOKU_LOADSTANDARDGAMEMENU_HPP

#include "AbstractMenuState.hpp"

class LoadStandardGameMenu : public AbstractMenuState {
public:
    LoadStandardGameMenu();

    void OnEntry(Game &game) override;

protected:
    void UseOption(Game &game, const std::string &option) override;
};

#endif //HEXADOKU_LOADSTANDARDGAMEMENU_HPP
