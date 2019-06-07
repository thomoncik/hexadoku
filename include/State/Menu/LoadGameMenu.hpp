#ifndef HEXADOKU_LOADGAMEMENU_HPP
#define HEXADOKU_LOADGAMEMENU_HPP

#include <State/AbstractState.hpp>
#include <string>
#include <map>

class LoadGameMenu : public AbstractState {
public:
    explicit LoadGameMenu(int size);

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

#endif //HEXADOKU_LOADGAMEMENU_HPP
