#ifndef HEXADOKU_HINT_HPP
#define HEXADOKU_HINT_HPP

#include "BoardCell.hpp"

class Hint {
public:
    Hint(int column, int row, int value);

    void SetColumn(int column);

    int GetColumn();

    void SetRow(int row);

    int GetRow();

    void SetValue(int value);

    int GetValue();

private:
    int column{0};
    int row{0};
    int value{BoardCell::EMPTY_VALUE};
};

#endif //HEXADOKU_HINT_HPP
