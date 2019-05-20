//
// Created by Jakub Kiermasz on 2019-05-11.
//

#include <Model/BoardCell.hpp>

const int BoardCell::EMPTY_VALUE = 0;

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

void BoardCell::SetSelected(bool isSelected) {
    this->isSelected = isSelected;
}

