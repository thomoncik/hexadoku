#include "../include/Position.hpp"

std::ostream &operator<<(std::ostream &stream, const Position &position) {
    move(position.y, position.x);
    return stream;
}

Position::Position(int x, int y) : x(x), y(y) {

}