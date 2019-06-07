#ifndef HEXADOKU_LOADBOARDMENUSTATE_HPP
#define HEXADOKU_LOADBOARDMENUSTATE_HPP

#include <map>
#include <string>
#include <Game.hpp>
#include <State/AbstractState.hpp>

class LoadBoardMenuState : public AbstractState {
public:
    explicit LoadBoardMenuState(int size);

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

#endif //HEXADOKU_LOADBOARDMENUSTATE_HPP
