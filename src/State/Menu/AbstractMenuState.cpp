#include <Graphics/GfxStream.hpp>
#include <Graphics/Assets.hpp>
#include <Graphics/Attributes.hpp>
#include <State/Menu/AbstractMenuState.hpp>
#include <iomanip>
#include <algorithm>

void AbstractMenuState::OnEntry(StateContext &stateContext) {
    selectedOption = 0;
}

void AbstractMenuState::Update(StateContext &stateContext) {

}

void AbstractMenuState::HandleInput(StateContext &stateContext, char input) {
    if (input == 'j') {
        selectedOption = (selectedOption + 1) % options.size();
    } else if (input == 'k') {
        selectedOption == 0 ? (selectedOption = options.size() - 1) : (selectedOption--);
    } else if (input == ' ') {
        UseOption(stateContext, options[selectedOption]);
    }
}

void AbstractMenuState::Draw(StateContext &stateContext) {
    gfx::out << gfx::clear;
    gfx::out << Position(0, 3) << Color::Blue << Attribute::BOLD;
    gfx::out << Assets::HEXADOKU_LOGO << gfx::nodecor;
    
    for (unsigned i = 0; i < options.size(); ++i) {
        gfx::out << Position(15, 13 + i) << std::setw(labelSize);
        if (selectedOption == i) {
            gfx::out << Attribute::STANDOUT;
        }
        gfx::out << options[i] << gfx::nodecor;
    }
    DrawInfo();
}

void AbstractMenuState::OnExit(StateContext &stateContext) {

}

void AbstractMenuState::DrawInfo() const {
    int x = 50;
    int y = 13;
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y);
    gfx::out << Attribute::BOLD << "Movement";
    gfx::out << gfx::nodecor << Color::Magenta << Position(x, y + 1);
    gfx::out << " j - Move down" << Position(x, y + 2);
    gfx::out << " k - Move up" << Position(x, y + 3);
    gfx::out << " Space - Confirm" << Position(x, y + 3);
    gfx::out << gfx::nodecor;
}

