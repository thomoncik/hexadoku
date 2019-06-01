#ifndef HEXADOKU_HINT_HPP
#define HEXADOKU_HINT_HPP

class Hint {
public:
    Hint();

    Hint(int column, int row, int value);

    void SetColumn(int column);

    int GetColumn();

    void SetRow(int row);

    int GetRow();

    void SetValue(int value);

    int GetValue();

private:
    int column;
    int row;
    int value;
};

#endif //HEXADOKU_HINT_HPP
