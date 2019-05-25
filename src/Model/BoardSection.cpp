//
// Created by Jakub Kiermasz on 2019-05-11.
//

#include <Model/BoardSection.hpp>
#include <cmath>

BoardSection::BoardSection(int size) : size(size), cells(std::vector<BoardCell>(size)) {}

int BoardSection::GetSize() const {
    return size;
}

int BoardSection::GetRowSize() const {
    return (int) sqrt(this->size);
}

void BoardSection::SetSelected(bool isSelectd, int column, int row) {
    const int cellId = this->GetRowSize() * row + column;
    cells[cellId].SetSelected(isSelectd);
}

void BoardSection::SetIsCorrect(bool isCorrect, int column, int row) {
    const int cellId = this->GetRowSize() * row + column;
    cells[cellId].SetIsCorrect(isCorrect);
}

void BoardSection::SetValue(int value, int column, int row) {
    const int cellId = this->GetRowSize() * row + column;
    cells[cellId].SetValue(value);
}

std::vector<int> BoardSection::GetValuesInColumn(int column) const {
    std::vector<int> values(size);
    for (int i = 0 + column; i < size; i += size) {
        values.push_back(cells[i].GetValue());
    }
    return values;
}

std::vector<int> BoardSection::GetValuesInRow(int row) const {
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

BoardCell BoardSection::GetCell(int column, int row) const {
    const int cellId = this->GetRowSize() * row + column;
    return this->cells[cellId];
}

int BoardSection::GetValue(int column, int row) const {
    const int cellId = this->GetRowSize() * row + column;
    return cells[cellId].GetValue();
}
