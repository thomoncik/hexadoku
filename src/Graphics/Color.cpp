#include "Graphics/Color.hpp"

ColorStarter colorStarter;

std::map<std::pair<NCURSES_COLOR_T, NCURSES_COLOR_T>, short> Color::definedColorPairs;

const Color Color::Black(COLOR_BLACK);
const Color Color::White(COLOR_WHITE);
const Color Color::Red(COLOR_RED);
const Color Color::Green(COLOR_GREEN);
const Color Color::Blue(COLOR_BLUE);
const Color Color::Yellow(COLOR_YELLOW);
const Color Color::Magenta(COLOR_MAGENTA);
const Color Color::Cyan(COLOR_CYAN);

Color::Color(NCURSES_COLOR_T foreground, NCURSES_COLOR_T background) {
    auto key = std::make_pair(foreground, background);
    auto iterator = Color::definedColorPairs.find(key);

    if (iterator != Color::definedColorPairs.end()) {
        this->colorPair = iterator->second;
    } else {
        this->colorPair = Color::definedColorPairs.size() + 1;
        Color::definedColorPairs[key] = this->colorPair;
        init_pair(this->colorPair, foreground, background);
    }
}