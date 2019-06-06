#ifndef HEXADOKU_ATTRIBUTES_HPP
#define HEXADOKU_ATTRIBUTES_HPP

#include <ostream>
#include <ncurses.h>

enum class Attribute {
    NORMAL,         // Normal display (no highlight)
    BLINKING,       // Blinking
    UNDERLINE,      // Underlining
    SEMIBOLD,       // Half bright
    BOLD,           // Extra bright or bold
    STANDOUT,       // Best highlighting mode of the terminal.
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits> &operator<<(std::basic_ostream<_CharT, _Traits> &stream, const Attribute &attribute) {
    switch (attribute) {
        case Attribute::NORMAL:
            attron(A_NORMAL);
            break;
        case Attribute::BLINKING:
            attron(A_BLINK);
            break;
        case Attribute::UNDERLINE:
            attron(A_UNDERLINE);
            break;
        case Attribute::SEMIBOLD:
            attron(A_DIM);
            break;
        case Attribute::BOLD:
            attron(A_BOLD);
            break;
        case Attribute::STANDOUT:
            attron(A_STANDOUT);
            break;
    }
    return stream;
}


#endif //HEXADOKU_ATTRIBUTES_HPP
