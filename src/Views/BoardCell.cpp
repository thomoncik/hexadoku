//
// Created by Jakub Kiermasz on 2019-05-11.
//

#include "../../include/BoardCell.hpp"
const int BoardCell::EMPTY_VALUE = 0;
BoardCell::BoardCell() : isSelected(false), isCorrect(true) {}
void BoardCell::SetValue(int value) {
    this->value = value;
}
int BoardCell::GetValue() {
    return value;
}
void BoardCell::SetIsCorrect(bool isCorrect) {
    this->isCorrect = isCorrect;
}
void BoardCell::SetSelected(bool isSelected) {
    this->isSelected = isSelected;
}

