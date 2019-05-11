#ifndef HEXADOKU_COLOR_HPP
#define HEXADOKU_COLOR_HPP

#include <ncurses.h>
#include <utility>
#include <ostream>
#include <map>

struct ColorStarter {
    ColorStarter() {
        #ifndef TESTING
        initscr();
        start_color();
        #endif
    }
};

class Color {
public:
    explicit Color(NCURSES_COLOR_T foreground = COLOR_WHITE, NCURSES_COLOR_T background = COLOR_BLACK);

    friend std::ostream &operator<<(std::ostream &stream, const Color &color);

    static const Color Black;
    static const Color White;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
    static const Color Yellow;
    static const Color Magenta;
    static const Color Cyan;

private:
    static std::map<std::pair<NCURSES_COLOR_T, NCURSES_COLOR_T>, short> definedColorPairs;

    short colorPair;
};

#endif //HEXADOKU_COLOR_HPP
