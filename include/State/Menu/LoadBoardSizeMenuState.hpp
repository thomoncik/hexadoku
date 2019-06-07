#ifndef HEXADOKU_LOADBOARDSIZEMENUSTATE_HPP
#define HEXADOKU_LOADBOARDSIZEMENUSTATE_HPP

#include <State/Menu/AbstractMenuState.hpp>

class LoadBoardSizeMenuState : public AbstractMenuState {
public:
    static const std::string STANDARD_SIZE_OPTION;
    static const std::string HEXADOKU_OPTION;
    static const std::string BACK_OPTION;

    LoadBoardSizeMenuState();

protected:
    void UseOption(StateContext &stateContext, const std::string &option) override;
};

#endif //HEXADOKU_LOADBOARDSIZEMENUSTATE_HPP
