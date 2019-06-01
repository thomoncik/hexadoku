
#include <Model/Hint.hpp>
#include <Model/BoardCell.hpp>

Hint::Hint() : column(0), row(0), value(BoardCell::EMPTY_VALUE) {

}

Hint::Hint(int column, int row, int value) : column(column), row(row), value(value) {

}


void Hint::SetColumn(int column) {
    this->column = column;
}

int Hint::GetColumn() {
    return column;
}

void Hint::SetRow(int row) {
    this->row = row;
}

int Hint::GetRow() {
    return row;
}

void Hint::SetValue(int value) {
    this->value = value;
}

int Hint::GetValue() {
    return value;
}

