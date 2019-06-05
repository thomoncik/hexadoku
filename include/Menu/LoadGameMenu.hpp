#ifndef HEXADOKU_LOADGAMEMENU_HPP
#define HEXADOKU_LOADGAMEMENU_HPP

#include "AbstractMenuState.hpp"

class LoadGameMenu : public AbstractMenuState {
public:
    static const std::string STANDARD_SIZE_OPTION;
    static const std::string HEXADOKU_OPTION;
    static const std::string BACK_OPTION;

    LoadGameMenu();

protected:
    void UseOption(Game &game, const std::string &option) override;
};

#endif //HEXADOKU_LOADGAMEMENU_HPP
