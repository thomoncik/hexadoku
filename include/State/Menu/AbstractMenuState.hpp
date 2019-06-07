#ifndef HEXADOKU_ABSTRACTMENUSTATE_HPP
#define HEXADOKU_ABSTRACTMENUSTATE_HPP

#include <vector>
#include <string>
#include "State/AbstractState.hpp"

class AbstractMenuState : public AbstractState {
public:
    void OnEntry(StateContext &game) override;

    void Update(StateContext &game) override;

    void HandleInput(StateContext &game, char input) override;

    void Draw(StateContext &game) override;

    void OnExit(StateContext &game) override;

protected:
    std::vector<std::string> options;
    unsigned long selectedOption;
    unsigned long labelSize{15};

    virtual void UseOption(StateContext &game, const std::string &option) = 0;
};

#endif //HEXADOKU_ABSTRACTMENUSTATE_HPP
