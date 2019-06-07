#ifndef HEXADOKU_LOADORCREATEBOARDMENUSTATE_HPP
#define HEXADOKU_LOADORCREATEBOARDMENUSTATE_HPP

#include <State/Menu/AbstractMenuState.hpp>

class LoadOrCreateBoardMenuState : public AbstractMenuState {
public:
    static const std::string CREATE_NEW_OPTION;
    static const std::string FROM_FILE_OPTION;
    static const std::string BACK_OPTION;

    explicit LoadOrCreateBoardMenuState(int size);

protected:
    void UseOption(StateContext &stateContext, const std::string &option) override;

private:
    int size;
};

#endif //HEXADOKU_LOADORCREATEBOARDMENUSTATE_HPP
