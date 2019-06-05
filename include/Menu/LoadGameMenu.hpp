#ifndef HEXADOKU_LOADGAMEMENU_HPP
#define HEXADOKU_LOADGAMEMENU_HPP

#include <AbstractState.hpp>
#include <string>
#include <map>

class LoadGameMenu : public AbstractState {
public:
    explicit LoadGameMenu(int size);

    void OnEntry(Game &game) override;

    void Update(Game &game) override;

    void HandleInput(Game &game, char input) override;

    void Draw(Game &game) override;

    void OnExit(Game &game) override;

protected:
    std::string loadingPath;

private:
    std::map<std::string, std::string> filePathToName;
    std::map<std::string, std::string>::iterator option;
    int size;
};

#endif //HEXADOKU_LOADGAMEMENU_HPP
