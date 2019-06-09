#ifndef HEXADOKU_ABSTRACTMENUSTATE_HPP
#define HEXADOKU_ABSTRACTMENUSTATE_HPP

#include <vector>
#include <string>
#include "State/AbstractState.hpp"

class AbstractMenuState : public AbstractState {
public:
    void OnEntry(StateContext &stateContext) override;

    void Update(StateContext &stateContext) override;

    void HandleInput(StateContext &stateContext, char input) override;

    void Draw(StateContext &stateContext) override;

    void OnExit(StateContext &stateContext) override;

protected:
    void DrawInfo() const;
    std::vector<std::string> options;
    unsigned long selectedOption;
    unsigned long labelSize{15};
    virtual void UseOption(StateContext &stateContext, const std::string &option) = 0;
};

#endif //HEXADOKU_ABSTRACTMENUSTATE_HPP
