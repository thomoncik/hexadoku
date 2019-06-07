#ifndef HEXADOKU_LOADBOARDMENUSTATE_HPP
#define HEXADOKU_LOADBOARDMENUSTATE_HPP

#include <map>
#include <string>
#include <StateContext.hpp>
#include <State/AbstractState.hpp>

class LoadBoardMenuState : public AbstractState {
public:
    explicit LoadBoardMenuState(int size);

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

#endif //HEXADOKU_LOADBOARDMENUSTATE_HPP
