#ifndef HEXADOKU_COLOR_HPP
#define HEXADOKU_COLOR_HPP

#include <ncurses.h>
#include <utility>
#include <ostream>
#include <map>

struct ColorStarter {
    ColorStarter() {
        setlocale(LC_ALL, "");
        initscr();
        start_color();
    }
};

class Color {
public:
    explicit Color(NCURSES_COLOR_T foreground = COLOR_WHITE, NCURSES_COLOR_T background = COLOR_BLACK);

    template<typename _CharT, typename _Traits>
    friend std::basic_ostream<_CharT, _Traits> &operator<<(std::basic_ostream<_CharT, _Traits> &stream, const Color &color) {
        attron(COLOR_PAIR(color.colorPair));
        return stream;
    }


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
