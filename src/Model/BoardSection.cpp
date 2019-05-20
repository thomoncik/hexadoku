//
// Created by Jakub Kiermasz on 2019-05-11.
//

#include <Model/BoardSection.hpp>
#include <cmath>

BoardSection::BoardSection(int size) : size(size), cells(std::vector<BoardCell>(size)) {}

int BoardSection::GetSize() const {
    return size;
}

void BoardSection::SetSelected(bool isSelectd, int column, int row) {
    int rowSize = (int) sqrt(size);
    cells[row * rowSize + column].SetSelected(isSelectd);
}

void BoardSection::SetIsCorrect(bool isCorrect, int column, int row) {
    int rowSize = (int) sqrt(size);
    cells[row * rowSize + column].SetIsCorrect(isCorrect);
}

void BoardSection::SetValue(int value, int column, int row) {
    int rowSize = (int) sqrt(size);
    cells[row * rowSize + column].SetValue(value);
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

std::vector<int> BoardSection::GetValues() const {
    std::vector<int> values;
    values.reserve(this->cells.size());

    for (const auto &cell : this->cells) {
        values.push_back(cell.GetValue());
    }

    return values;
}
