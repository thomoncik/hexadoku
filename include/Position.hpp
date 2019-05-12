#ifndef HEXADOKU_POSITION_HPP
#define HEXADOKU_POSITION_HPP

#include <ncurses.h>
#include <ostream>

class Position {
public:
    Position(int x, int y);

    template<typename _CharT, typename _Traits>
    friend std::basic_ostream<_CharT, _Traits> &operator<<(std::basic_ostream<_CharT, _Traits> &stream, const Position &position) {
        move(position.y, position.x);
        return stream;
    }

private:
    int x;
    int y;
};

#endif //HEXADOKU_POSITION_HPP
