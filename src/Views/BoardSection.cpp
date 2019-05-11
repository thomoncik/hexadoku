//
// Created by Jakub Kiermasz on 2019-05-11.
//

#include "../../include/Views/BoardSection.hpp"
//BoardSection::BoardSection(int size) : size(size), cells(std::vector<BoardCell>(size)) {}

BoardSection::BoardSection(int size) : size(size), cells(std::vector<BoardCell>(size)) {}

void BoardSection::SetSelected(bool isSelectd, int row, int column) {
    cells[row * size + column].SetSelected(isSelectd);
}

void BoardSection::SetIsCorrect(bool isCorrect, int row, int column) {
    cells[row * size + column].SetIsCorrect(isCorrect);
}

void BoardSection::SetValue(int value, int row, int column) {
    cells[row * size + column].SetValue(value);
}

std::vector<int> BoardSection::ValuesInColumn(int column) {
    std::vector<int> values(size);
    for (int i = 0 + column; i < size; i += size) {
        values.push_back(cells[i].GetValue());
    }
    return values;
}

std::vector<int> BoardSection::ValuesInRow(int row) {
    std::vector<int> values(size);
    for (int i = 0 + row * size; i < size; i += size) {
        values.push_back(cells[i].GetValue());
    }
    return values;
}