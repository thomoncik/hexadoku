//
// Created by Jakub Kiermasz on 2019-05-11.
//

#include "../../include/Views/Board.hpp"

const int Board::STANDARD_SIZE = 9;
const int Board::HEXADOKU_SIZE = 16;

Board::Board(int size) : size(size), sectionSize((size == STANDARD_SIZE) ? 3 : 4),
                         sections(std::vector<BoardSection>(size, BoardSection(size))) {}

int Board::getSize() {
    return size;
}

void Board::SetSelected(bool isSelected, int row, int column) {
    const int sectionId = row / sectionSize * sectionSize + column / sectionSize;
    sections[sectionId].SetSelected(isSelected, row % sectionSize, column % sectionSize);
}

void Board::SetIsCorrect(bool isCorrect, int row, int column) {
    const int sectionId = row / sectionSize * sectionSize + column / sectionSize;
    sections[sectionId].SetIsCorrect(isCorrect, row % sectionSize, column % sectionSize);
}

void Board::SetValue(int value, int row, int column) {
    const int sectionId = row / sectionSize * sectionSize + column / sectionSize;
    sections[sectionId].SetValue(value, row % sectionSize, column % sectionSize);
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