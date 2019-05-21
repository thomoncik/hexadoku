//
// Created by Jakub Kiermasz on 2019-05-11.
//

#include "../../include/Model/Board.hpp"

const int Board::STANDARD_SIZE = 9;
const int Board::HEXADOKU_SIZE = 16;

Board::Board(int size) : size(size), sectionSize((size == STANDARD_SIZE) ? 3 : 4),
                         sections(std::vector<BoardSection>(size, BoardSection(size))) {}

int Board::GetSize() const {
    return size;
}

int Board::GetSectionSize() const {
    return sectionSize;
}

const BoardSection &Board::GetSection(int index) const {
    return sections[index];
}

void Board::SetSelected(bool isSelected, int column, int row) {
    sections[this->GetSectionId(column, row)].SetSelected(isSelected, column % sectionSize, row % sectionSize);
}

void Board::SetIsCorrect(bool isCorrect, int column, int row) {
    const int sectionId = row / sectionSize * sectionSize + column / sectionSize;
    sections[this->GetSectionId(column, row)].SetIsCorrect(isCorrect, column % sectionSize, row % sectionSize);
}

void Board::SetValue(int value, int column, int row) {
    const int sectionId = row / sectionSize * sectionSize + column / sectionSize;
    sections[this->GetSectionId(column, row)].SetValue(value, column % sectionSize, row % sectionSize);
}

int Board::GetSectionId(int column, int row) const {
    return row / this->sectionSize * this->sectionSize + column / this->sectionSize;
}

std::vector<int> Board::ValuesInRow(int row) {
    std::vector<int> values;
    int rowForSection = row % sectionSize;
    int firstSectionIndex = row / sectionSize * sectionSize;
    std::vector<int> firstSectionValues = sections[firstSectionIndex].ValuesInRow(rowForSection);
    std::vector<int> secondSectionValues = sections[firstSectionIndex + 1].ValuesInRow(rowForSection);
    std::vector<int> thirdSectionValues = sections[firstSectionIndex + 2].ValuesInRow(rowForSection);
    values.insert(std::end(values), std::begin(firstSectionValues), std::end(firstSectionValues));
    values.insert(std::end(values), std::begin(secondSectionValues), std::end(secondSectionValues));
    values.insert(std::end(values), std::begin(thirdSectionValues), std::end(thirdSectionValues));
    return values;
}

std::vector<int> Board::ValuesInColumn(int column) {
    std::vector<int> values;
    int columnForSection = column % sectionSize;
    int firstSectionIndex = column / sectionSize;
    std::vector<int> firstSectionValues = sections[firstSectionIndex].ValuesInColumn(columnForSection);
    std::vector<int> secondSectionValues = sections[firstSectionIndex + 1].ValuesInColumn(columnForSection);
    std::vector<int> thirdSectionValues = sections[firstSectionIndex + 2].ValuesInColumn(columnForSection);
    values.insert(std::end(values), std::begin(firstSectionValues), std::end(firstSectionValues));
    values.insert(std::end(values), std::begin(secondSectionValues), std::end(secondSectionValues));
    values.insert(std::end(values), std::begin(thirdSectionValues), std::end(thirdSectionValues));
    return values;
}

std::vector<std::vector<int>> Board::GetValues() const {
    std::vector<std::vector<int>> values;
    values.reserve(this->sections.size());

    for (const auto &section : this->sections) {
        values.push_back(section.GetValues());
    }

    return values;
}

std::vector<int> Board::GetValues(int index) const {
    return this->sections.at(index).GetValues();
}
