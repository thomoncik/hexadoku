#ifndef HEXADOKU_LOADGAMESIZEMENU_HPP
#define HEXADOKU_LOADGAMESIZEMENU_HPP

#include "AbstractMenuState.hpp"

class LoadGameSizeMenu : public AbstractMenuState {
public:
    static const std::string STANDARD_SIZE_OPTION;
    static const std::string HEXADOKU_OPTION;
    static const std::string BACK_OPTION;

    LoadGameSizeMenu();

protected:
    void UseOption(Game &game, const std::string &option) override;
};

#endif //HEXADOKU_LOADGAMESIZEMENU_HPP
