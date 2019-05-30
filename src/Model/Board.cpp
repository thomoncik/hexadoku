#include <random>

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

int Board::GetNumberOfSolutions(std::vector<std::vector<int>> &grid) {
    return GetNumberOfSolutions(std::move(grid));
}

int Board::GetNumberOfSolutions(std::vector<std::vector<int>> &&grid) {
    Board board = Board::FromGrid(grid);
    if (board.IsViolatingRules()) {
        return 0;
    } else if (board.IsFilled()) {
        return 1;
    }

    int maxValue = (board.size == STANDARD_SIZE) ? BoardCell::MAX_STANDARD_VALUE : BoardCell::MAX_HEXADOKU_VALUE;
    int solutions = 0;

    for (int y = 0; y < board.size; ++y) {
        for (int x = 0; x < board.size; ++x) {
            if (board.GetValue(x, y) == BoardCell::EMPTY_VALUE) {
                for (int value = 1; value <= maxValue; ++value) {
                    grid[y][x] = value;
                    solutions += Board::GetNumberOfSolutions(grid);
                    grid[y][x] = BoardCell::EMPTY_VALUE;
                }
                return solutions;
            }

        }
    }

    return solutions;
}

bool Board::Solve() {
    int maxValue = (this->size == STANDARD_SIZE) ? BoardCell::MAX_STANDARD_VALUE : BoardCell::MAX_HEXADOKU_VALUE;

    if (this->IsViolatingRules()) {
        return false;
    } else if (this->IsFilled()) {
        return true;
    }

    for (int y = 0; y < this->size; ++y) {
        for (int x = 0; x < this->size; ++x) {
            if (this->GetValue(x, y) == BoardCell::EMPTY_VALUE) {
                for (int value = 1; value <= maxValue; ++value) {
                    this->SetValue(value, x, y);
                    if (this->Solve()) {
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
    return Board::GetNumberOfSolutions(this->GetValuesAsGrid());
}

void Board::Generate(Board::Difficulty difficulty) {
    this->GenerateRecursively();

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

        int oldValue = this->GetValue(x, y);
        this->SetValue(BoardCell::EMPTY_VALUE, x, y);
        if (this->GetNumberOfSolutions() != 1) {
            this->SetValue(oldValue, x, y);
        }
    }
}

bool Board::GenerateRecursively() {
    int maxValue = (this->size == STANDARD_SIZE) ? BoardCell::MAX_STANDARD_VALUE : BoardCell::MAX_HEXADOKU_VALUE;
    std::vector<int> values(maxValue);
    for (int i = 0; i < maxValue; ++i) {
        values[i] = i + 1;
    }
    std::shuffle(values.begin(), values.end(), std::mt19937(std::random_device()()));

    if (this->IsViolatingRules()) {
        return false;
    } else if (this->IsFilled()) {
        return true;
    }

    for (int y = 0; y < this->size; ++y) {
        for (int x = 0; x < this->size; ++x) {
            if (this->GetValue(x, y) == BoardCell::EMPTY_VALUE) {
                for (int value : values) {
                    this->SetValue(value, x, y);
                    if (this->GenerateRecursively()) {
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

void Board::Reset() {
    for (int y = 0; y < this->GetSize(); ++y) {
        for (int x = 0; x < this->GetSize(); ++x) {
            this->SetValue(BoardCell::EMPTY_VALUE, x, y);
        }
    }
}

