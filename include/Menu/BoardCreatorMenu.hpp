#ifndef HEXADOKU_BOARDCREATORMENU_HPP
#define HEXADOKU_BOARDCREATORMENU_HPP
#include "AbstractMenuState.hpp"

class BoardCreatorMenu : public AbstractMenuState {
public:
    static const std::string STANDARD_SIZE_OPTION;
    static const std::string HEXADOKU_OPTION;
    static const std::string BACK_OPTION;

    BoardCreatorMenu();

protected:
    void UseOption(Game &game, const std::string &option) override;
};

#endif //HEXADOKU_BOARDCREATORMENU_HPP
