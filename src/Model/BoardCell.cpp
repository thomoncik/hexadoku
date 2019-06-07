//
// Created by Jakub Kiermasz on 2019-05-11.
//

#include <Model/BoardCell.hpp>

const int BoardCell::EMPTY_VALUE = 0;
const int BoardCell::MAX_HEXADOKU_VALUE = 16;
const int BoardCell::MAX_STANDARD_VALUE = 9;

BoardCell::BoardCell() : isSelected(false), isCorrect(true), value(EMPTY_VALUE) {

}

void BoardCell::SetValue(int value) {
    this->value = value;
}

int BoardCell::GetValue() const {
    return this->value;
}

void BoardCell::SetIsCorrect(bool isCorrect) {
    this->isCorrect = isCorrect;
}

void BoardCell::SetSelected(bool isSelected = true) {
    this->isSelected = isSelected;
}

bool BoardCell::IsSelected() const {
    return this->isSelected;
}

bool BoardCell::IsCorrect() const {
    return this->isCorrect;
}

