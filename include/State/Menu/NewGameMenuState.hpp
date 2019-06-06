#ifndef HEXADOKU_NEWGAMEMENUSTATE_HPP
#define HEXADOKU_NEWGAMEMENUSTATE_HPP

#include "AbstractMenuState.hpp"

class NewGameMenuState : public AbstractMenuState {
public:
    static const std::string STANDARD_SIZE_OPTION;
    static const std::string HEXADOKU_OPTION;
    static const std::string FROM_FILE_OPTION;
    static const std::string BACK_OPTION;

    NewGameMenuState();

protected:
    void UseOption(Game &game, const std::string &option) override;
};

#endif //HEXADOKU_NEWGAMEMENUSTATE_HPP
