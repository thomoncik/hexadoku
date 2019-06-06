#ifndef HEXADOKU_ABSTRACTMENUSTATE_HPP
#define HEXADOKU_ABSTRACTMENUSTATE_HPP

#include <vector>
#include <string>
#include "State/AbstractState.hpp"

class AbstractMenuState : public AbstractState {
public:
    void OnEntry(Game &game) override;

    void Update(Game &game) override;

    void HandleInput(Game &game, char input) override;

    void Draw(Game &game) override;

    void OnExit(Game &game) override;

protected:
    std::vector<std::string> options;
    unsigned long selectedOption;
    unsigned long labelSize{15};

    virtual void UseOption(Game &game, const std::string &option) = 0;
};

#endif //HEXADOKU_ABSTRACTMENUSTATE_HPP
