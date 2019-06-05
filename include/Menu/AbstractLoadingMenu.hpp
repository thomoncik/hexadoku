#ifndef HEXADOKU_ABSTRACTLOADINGMENU_HPP
#define HEXADOKU_ABSTRACTLOADINGMENU_HPP

#include <AbstractState.hpp>
#include <string>
#include <map>

class AbstractLoadingMenu : public AbstractState {
public:
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
};

#endif //HEXADOKU_ABSTRACTLOADINGMENU_HPP
