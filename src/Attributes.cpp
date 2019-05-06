#include "../include/Attributes.hpp"

std::ostream &operator<<(std::ostream &stream, const Attribute &attribute) {
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
