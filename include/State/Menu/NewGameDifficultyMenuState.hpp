#ifndef HEXADOKU_NEWGAMEDIFFICULTYMENUSTATE_HPP
#define HEXADOKU_NEWGAMEDIFFICULTYMENUSTATE_HPP

#include <State/Menu/AbstractMenuState.hpp>

class NewGameDifficultyMenuState : public AbstractMenuState {
public:
    static const std::string EASY_OPTION;
    static const std::string NORMAL_OPTION;
    static const std::string HARD_OPTION;
    static const std::string FROM_FILE_OPTION;
    static const std::string BACK_OPTION;

    explicit NewGameDifficultyMenuState(int size);

protected:
    void UseOption(StateContext &stateContext, const std::string &option) override;

private:
    int size;
};

#endif //HEXADOKU_NEWGAMEDIFFICULTYMENUSTATE_HPP
