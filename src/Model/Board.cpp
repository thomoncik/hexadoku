//
// Created by Jakub Kiermasz on 2019-05-11.
//

#include <cmath>
#include <iostream>
#include <fstream>
#include "Model/Board.hpp"

const int Board::STANDARD_SIZE = 9;
const int Board::HEXADOKU_SIZE = 16;

const std::string Board::SAVED_STANDARD_BOARD_PATH = std::string(std::getenv("HOME")) + "/.hexadoku/board/standard/";
const std::string Board::SAVED_HEXADOKU_BOARD_PATH = std::string(std::getenv("HOME")) + "/.hexadoku/board/hexadoku/";

Board::Board(int size) : size(size),
                         sections(std::vector<BoardSection>(size, BoardSection(size))) {}

int Board::GetSize() const {
    return size;
}

int Board::GetSectionRowSize() const {
    return (int) sqrt(size);
}

const BoardSection &Board::GetSection(int index) const {
    return sections[index];
}

void Board::SetSelected(bool isSelected, int column, int row) {
    const int sectionId = this->GetSectionId(column, row);
    const int sectionColumn = column % this->GetSectionRowSize();
    const int sectionRow = row % this->GetSectionRowSize();

    sections[sectionId].SetSelected(isSelected, sectionColumn, sectionRow);
}

void Board::SetIsCorrect(bool isCorrect, int column, int row) {
    const int sectionId = this->GetSectionId(column, row);
    const int sectionColumn = column % this->GetSectionRowSize();
    const int sectionRow = row % this->GetSectionRowSize();

    sections[sectionId].SetIsCorrect(isCorrect, sectionColumn, sectionRow);
}

void Board::SetValue(int value, int column, int row) {
    const int sectionId = this->GetSectionId(column, row);
    const int sectionColumn = column % this->GetSectionRowSize();
    const int sectionRow = row % this->GetSectionRowSize();

    sections[sectionId].SetValue(value, sectionColumn, sectionRow);
}

int Board::GetSectionId(int column, int row) const {
    const int sectionSize = (int) sqrt(size);
    return row / sectionSize * sectionSize + column / sectionSize;
}

std::vector<int> Board::GetValuesInRow(int row) const {
    std::vector<int> values(this->size);
    for (int column = 0; column < this->size; ++column) {
        values[column] = this->GetValue(column, row);
    }

    return values;
}

std::vector<int> Board::GetValuesInColumn(int column) const {
    std::vector<int> values(this->size);
    for (int row = 0; row < this->size; ++row) {
        values[row] = this->GetValue(column, row);
    }

    return values;
}

std::vector<std::vector<int>> Board::GetValuesPerSection() const {
    std::vector<std::vector<int>> values;
    values.reserve(this->sections.size());

    for (const auto &section : this->sections) {
        values.push_back(section.GetValues());
    }

    return values;
}

std::vector<std::vector<int>> Board::GetValuesAsGrid() const {
    std::vector<std::vector<int>> result(this->size);
    for (int i = 0; i < this->size; ++i) {
        result[i] = this->GetValuesInRow(i);
    }

    return result;
}

void Board::LoadFromStream(std::istream &stream) {
    int value;
    for (int y = 0; y < this->size; ++y) {
        for (int x = 0; x < this->size; ++x) {
            stream >> value;
            this->SetValue(value, x, y);
        }
    }
}

void Board::SaveToStream(std::ostream &stream) const {
    for (int y = 0; y < this->size; ++y) {
        for (int x = 0; x < this->size; ++x) {
            stream << this->GetValue(x, y) << " ";
        }
    }
}

int Board::GetValue(int column, int row) const {
    const int sectionId = this->GetSectionId(column, row);
    const int sectionColumn = column % this->GetSectionRowSize();
    const int sectionRow = row % this->GetSectionRowSize();

    return sections[sectionId].GetValue(sectionColumn, sectionRow);
}

void Board::LoadFromFile(const std::string& filename) {
    std::ifstream fileStream;
    if (this->size == Board::STANDARD_SIZE) {
        fileStream.open(Board::SAVED_STANDARD_BOARD_PATH + filename);
    } else if (this->size == Board::HEXADOKU_SIZE) {
        fileStream.open(Board::SAVED_HEXADOKU_BOARD_PATH + filename);
    }
    this->LoadFromStream(fileStream);
    fileStream.close();
}

void Board::SaveToFile(const std::string& filename) const {
    std::ofstream fileStream;
    if (this->size == Board::STANDARD_SIZE) {
        fileStream.open(Board::SAVED_STANDARD_BOARD_PATH + filename);
    } else if (this->size == Board::HEXADOKU_SIZE) {
        fileStream.open(Board::SAVED_HEXADOKU_BOARD_PATH + filename);
    }
    this->SaveToStream(fileStream);
    fileStream.close();
}

int Board::Solve() {
    return 0;
}

bool Board::IsVioletingRules() const {
    return false;
}

