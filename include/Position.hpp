#ifndef HEXADOKU_POSITION_HPP
#define HEXADOKU_POSITION_HPP

#include <ncurses.h>
#include <ostream>

class Position {
public:
    Position(int x, int y);

    friend std::ostream &operator<<(std::ostream &stream, const Position &position);

private:
    int x;
    int y;
};

#endif //HEXADOKU_POSITION_HPP
