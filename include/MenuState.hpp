#ifndef HEXADOKU_MENUSTATE_HPP
#define HEXADOKU_MENUSTATE_HPP

#include <vector>
#include <string>

#include "AbstractState.hpp"

class MenuState : public AbstractState {
public:
    static MenuState *const MAIN_MENU;
    static MenuState *const GAME_MODE_MENU;

    MenuState();

    void OnEntry(Game &game) override;

    void Update(Game &game) override;

    void HandleInput(Game &game, char input) override;

    void Draw(Game &game) override;

    void OnExit(Game &game) override;

    void AddOption(std::pair<std::string, AbstractState *> option);

private:
    static bool initPredefinedMenus();
    static bool arePredefinedMenusInitialized;

    std::vector<std::pair<std::string, AbstractState *>> options;
    unsigned long selectedOption;
    unsigned long labelSize;
};


#endif //HEXADOKU_MENUSTATE_HPP
