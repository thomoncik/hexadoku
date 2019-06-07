#ifndef HEXADOKU_LOADGAMEMENU_HPP
#define HEXADOKU_LOADGAMEMENU_HPP

#include <State/AbstractState.hpp>
#include <string>
#include <map>

class LoadGameMenu : public AbstractState {
public:
    explicit LoadGameMenu(int size);

    void OnEntry(StateContext &game) override;

    void Update(StateContext &game) override;

    void HandleInput(StateContext &game, char input) override;

    void Draw(StateContext &game) override;

    void OnExit(StateContext &game) override;

protected:
    std::string loadingPath;

private:
    std::map<std::string, std::string> filePathToName;
    std::map<std::string, std::string>::iterator option;
    int size;
};

#endif //HEXADOKU_LOADGAMEMENU_HPP
