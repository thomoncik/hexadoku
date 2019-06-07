#ifndef HEXADOKU_LOADGAMESIZEMENUSTATE_HPP
#define HEXADOKU_LOADGAMESIZEMENUSTATE_HPP

#include "AbstractMenuState.hpp"

class LoadGameSizeMenuState : public AbstractMenuState {
public:
    static const std::string STANDARD_SIZE_OPTION;
    static const std::string HEXADOKU_OPTION;
    static const std::string BACK_OPTION;

    LoadGameSizeMenuState();

protected:
    void UseOption(StateContext &stateContext, const std::string &option) override;
};

#endif //HEXADOKU_LOADGAMESIZEMENUSTATE_HPP
