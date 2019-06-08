#ifndef HEXADOKU_NEWGAMEFROMFILEMENUSTATE_HPP
#define HEXADOKU_NEWGAMEFROMFILEMENUSTATE_HPP

#include <State/AbstractState.hpp>
#include <map>

class NewGameFromFileMenuState : public AbstractState {
public:
    explicit NewGameFromFileMenuState(int size);

    void OnEntry(StateContext &stateContext) override;

    void Update(StateContext &stateContext) override;

    void HandleInput(StateContext &stateContext, char input) override;

    void Draw(StateContext &stateContext) override;

    void OnExit(StateContext &stateContext) override;

protected:
    std::string loadingPath;

private:
    std::map<std::string, std::string> filePathToName;
    std::map<std::string, std::string>::iterator option;
    int size;
};



#endif //HEXADOKU_NEWGAMEFROMFILEMENUSTATE_HPP
