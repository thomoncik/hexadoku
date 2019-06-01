//
// Created by Jakub Kiermasz on 2019-05-11.
//

#include <cmath>
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <chrono>
#include <functional>
#include "Model/Board.hpp"

const int Board::STANDARD_SIZE = 9;
const int Board::HEXADOKU_SIZE = 16;

const std::string Board::SAVED_STANDARD_BOARD_PATH = std::string(std::getenv("HOME")) + "/.hexadoku/board/standard/";
const std::string Board::SAVED_HEXADOKU_BOARD_PATH = std::string(std::getenv("HOME")) + "/.hexadoku/board/hexadoku/";

Board Board::FromGrid(const std::vector<std::vector<int>> &&grid) {
    Board board(grid.size());

    for (int row = 0; row < grid.size(); ++row) {
        for (int column = 0; column < grid[row].size(); ++column) {
            board.SetValue(grid[row][column], column, row);
        }
    }

    return board;
}

Board Board::FromGrid(const std::vector<std::vector<int>> &grid) {
    Board board(grid.size());

    for (int row = 0; row < grid.size(); ++row) {
        for (int column = 0; column < grid[row].size(); ++column) {
            board.SetValue(grid[row][column], column, row);
        }
    }

    return board;
}

Board::Board(int size) : size(size), sections(std::vector<BoardSection>(size, BoardSection(size))) {

}

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

const BoardSection &Board::GetSection(int column, int row) const {
    return GetSection(GetSectionId(column, row));
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

void Board::LoadFromFile(const std::string &filename) {
    std::ifstream fileStream;
    if (this->size == Board::STANDARD_SIZE) {
        fileStream.open(Board::SAVED_STANDARD_BOARD_PATH + filename);
    } else if (this->size == Board::HEXADOKU_SIZE) {
        fileStream.open(Board::SAVED_HEXADOKU_BOARD_PATH + filename);
    }
    this->LoadFromStream(fileStream);
    fileStream.close();
}

void Board::SaveToFile(const std::string &filename) const {
    std::ofstream fileStream;
    if (this->size == Board::STANDARD_SIZE) {
        fileStream.open(Board::SAVED_STANDARD_BOARD_PATH + filename);
    } else if (this->size == Board::HEXADOKU_SIZE) {
        fileStream.open(Board::SAVED_HEXADOKU_BOARD_PATH + filename);
    }
    this->SaveToStream(fileStream);
    fileStream.close();
}

bool Board::HasUniqueSolution(std::vector<std::vector<int>> &grid) {
    int filledCells = 0;
    for (const auto &row : grid) {
        for (auto cellValue : row) {
            if (cellValue != BoardCell::EMPTY_VALUE) {
                filledCells++;
            }
        }
    }

    Board board = Board::FromGrid(grid);
    return board.HasUniqueSolution(filledCells) == 1;
}

int Board::HasUniqueSolution(int filledCells) {
    if (filledCells == (GetSize() * GetSize())) {
        return 1;
    }

    int solutions = 0;
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            auto values = GetAvailableValues(x, y);
            if (GetValue(x, y) == BoardCell::EMPTY_VALUE) {
                for (auto value : values) {
                    SetValue(value, x, y);
                    solutions += HasUniqueSolution(filledCells + 1);
                    if (solutions > 1) {
                        return solutions;
                    }
                    SetValue(BoardCell::EMPTY_VALUE, x, y);
                }
                return solutions;
            }

        }
    }

    return solutions;
}

bool Board::Solve() {
    int filledCells = 0;
    for (int i = 0; i < GetSize(); ++i) {
        for (int j = 0; j < GetSize(); ++j) {
            if (GetValue(j, i) != BoardCell::EMPTY_VALUE) {
                filledCells++;
            }
        }
    }

    return Solve(filledCells);
}

bool Board::Solve(int filledCells) {
    if (filledCells == (GetSize() * GetSize())) {
        return true;
    }

    for (int y = 0; y < this->size; ++y) {
        for (int x = 0; x < this->size; ++x) {
            if (this->GetValue(x, y) == BoardCell::EMPTY_VALUE) {
                auto values = this->GetAvailableValues(x, y);
                std::shuffle(values.begin(), values.end(), std::mt19937(std::random_device()()));

                for (auto value : values) {
                    this->SetValue(value, x, y);
                    if (this->Solve(filledCells + 1)) {
                        return true;
                    }
                    this->SetValue(BoardCell::EMPTY_VALUE, x, y);
                }
                return false;
            }

        }
    }

    return false;
}

bool Board::IsViolatingRules() const {
    for (int row = 0; row < this->size; ++row) {
        std::vector<bool> exists(this->size + 1, false);
        for (auto value : this->GetValuesInRow(row)) {
            if (value != BoardCell::EMPTY_VALUE && exists[value]) {
                return true;
            }

            exists[value] = true;
        }
    }

    for (int column = 0; column < this->size; ++column) {
        std::vector<bool> exists(this->size + 1, false);
        for (auto value : this->GetValuesInColumn(column)) {
            if (value != BoardCell::EMPTY_VALUE && exists[value]) {
                return true;
            }

            exists[value] = true;
        }
    }

    for (const auto &section : this->sections) {
        if (section.IsViolatingRules()) {
            return true;
        }
    }

    return false;
}

bool Board::IsFilled() const {
    for (const auto &row : this->GetValuesAsGrid()) {
        for (auto value : row) {
            if (value == BoardCell::EMPTY_VALUE) {
                return false;
            }
        }
    }

    return true;
}

int Board::GetNumberOfSolutions() const {
    std::vector<std::vector<int>> grid = this->GetValuesAsGrid();
    return Board::HasUniqueSolution(grid);
}

void Board::Generate(Board::Difficulty difficulty) {
    Reset();
    Solve();

    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<std::mt19937::result_type> distribution(0, this->GetSize() - 1);
    auto randomCoordinate = std::bind(distribution, generator);

    int cluesToRemove;
    switch (difficulty) {
        case Difficulty::EASY:
            cluesToRemove = 20;
            break;
        case Difficulty::NORMAL:
            cluesToRemove = 40;
            break;
        case Difficulty::HARD:
            cluesToRemove = 60;
            break;
    }

    while (cluesToRemove--) {
        int x = randomCoordinate();
        int y = randomCoordinate();

        int oldValue = GetValue(x, y);
        SetValue(BoardCell::EMPTY_VALUE, x, y);
        if (GetNumberOfSolutions() != 1) {
            SetValue(oldValue, x, y);
        }
    }
}

std::vector<int> Board::GetAvailableValues(int column, int row) const {
    std::vector<bool> isAvailable(GetSize() + 1, true);

    for (auto value : GetSection(column, row).GetValues()) {
        isAvailable[value] = false;
    }
    for (auto value : GetValuesInRow(row)) {
        isAvailable[value] = false;
    }
    for (auto value : GetValuesInColumn(column)) {
        isAvailable[value] = false;
    }

    std::vector<int> result;
    for (int i = 1; i <= GetSize(); ++i) {
        if (isAvailable[i]) {
            result.push_back(i);
        }
    }
    return result;
}

void Board::Reset() {
    for (int y = 0; y < this->GetSize(); ++y) {
        for (int x = 0; x < this->GetSize(); ++x) {
            this->SetValue(BoardCell::EMPTY_VALUE, x, y);
        }
    }
}

Hint Board::GetHint() const {
    Board boardCopy = *this;
    boardCopy.Solve();
    
    std::vector<int> rowToCheck(GetSize());
    for (int i = 0; i < rowToCheck.size(); ++i) {
        rowToCheck[i] = i;
    }
    std::shuffle(rowToCheck.begin(), rowToCheck.end(), std::mt19937(std::random_device()()));
    
    std::vector<std::vector<int>> columnToCheck(GetSize(), std::vector<int>(GetSize()));
    for (int i = 0; i < GetSize(); ++i) {
        for (int j = 0; j < GetSize(); ++j) {
            columnToCheck[i][j] = j;
        }
        std::shuffle(columnToCheck[i].begin(), columnToCheck[i].end(), std::mt19937(std::random_device()()));
    }

    for (int i = 0; i < rowToCheck.size(); ++i) {
        for (int j = 0; j < columnToCheck[i].size(); ++j) {
            const int column = columnToCheck[i][j];
            const int row = rowToCheck[i];

            if (GetValue(column, row) == BoardCell::EMPTY_VALUE) {
                return {column, row, boardCopy.GetValue(column, row)};
            }
        }
    }
    
    return {};
}

