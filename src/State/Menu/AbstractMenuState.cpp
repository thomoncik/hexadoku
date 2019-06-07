#include <Graphics/GfxStream.hpp>
#include <Graphics/Assets.hpp>
#include <Graphics/Attributes.hpp>
#include <State/Menu/AbstractMenuState.hpp>
#include <iomanip>
#include <algorithm>

void AbstractMenuState::OnEntry(StateContext &game) {
    selectedOption = 0;
}

void AbstractMenuState::Update(StateContext &game) {

}

void AbstractMenuState::HandleInput(StateContext &game, char input) {
    if (input == 'j') {
        selectedOption = (selectedOption + 1) % options.size();
    } else if (input == 'k') {
        selectedOption == 0 ? (selectedOption = options.size() - 1) : (selectedOption--);
    } else if (input == ' ') {
        UseOption(game, options[selectedOption]);
    }
}

void AbstractMenuState::Draw(StateContext &game) {
    gfx::out << gfx::clear;
    gfx::out << Position(0, 3) << Color::Blue << Attribute::BOLD;
    gfx::out << Assets::HEXADOKU_LOGO << gfx::nodecor;
    
    for (unsigned i = 0; i < options.size(); ++i) {
        gfx::out << Position(30, 13 + i) << std::setw(labelSize);
        if (selectedOption == i) {
            gfx::out << Attribute::STANDOUT;
        }
        gfx::out << options[i] << gfx::nodecor;
    }
}

void AbstractMenuState::OnExit(StateContext &game) {

}

