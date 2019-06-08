#ifndef HEXADOKU_BOARDCREATORMENUSTATE_HPP
#define HEXADOKU_BOARDCREATORMENUSTATE_HPP
#include "AbstractMenuState.hpp"

class BoardCreatorMenuState : public AbstractMenuState {
public:
    static const std::string STANDARD_SIZE_OPTION;
    static const std::string HEXADOKU_OPTION;
    static const std::string BACK_OPTION;

    BoardCreatorMenuState();

protected:
    void UseOption(StateContext &stateContext, const std::string &option) override;
};

#endif //HEXADOKU_BOARDCREATORMENUSTATE_HPP
