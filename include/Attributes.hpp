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

std::ostream &operator<<(std::ostream &stream, const Attribute &atribute);


#endif //HEXADOKU_ATTRIBUTES_HPP
