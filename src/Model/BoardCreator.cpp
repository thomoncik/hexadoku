#include <Model/BoardCreator.hpp>
#include <algorithm>

BoardCreator::BoardCreator(int size) : board(std::make_shared<Board>(size)) {

}

BoardCreator::BoardCreator(std::shared_ptr<Board> board) : board(std::move(board)) {

}

void BoardCreator::SetSelected(bool selected, int column, int row) {
    SetSelectedColumn(column);
    SetSelectedRow(row);
    board->SetSelected(selected, column, row);
}

int BoardCreator::GetSelectedColumn() const {
    return column;
}

void BoardCreator::SetSelectedColumn(int column) {
    this->column = column;
}

int BoardCreator::GetSelectedRow() const {
    return row;
}

void BoardCreator::SetSelectedRow(int row) {
    this->row = row;
}

void BoardCreator::SetValue(int value, int column, int row) {
    board->SetValue(value, column, row);
}

std::shared_ptr<Board> BoardCreator::GetBoard() const {
    return board;
}

void BoardCreator::Validate(int column, int row) {
    int value = board->GetValue(column, row);
    ValidateColumn(column, value);
    ValidateRow(row, value);
    ValidateSection(column, row, value);
}

void BoardCreator::ValidateColumn(int column, int value) {
    auto columnValues = board->GetValuesInColumn(column);
    for (int i = 0; i < board->GetSize(); ++i) {
        bool isViolatingRules = (std::count(columnValues.begin(), columnValues.end(), value) > 1);
        if (isViolatingRules) {
            isViolatingRules = board->GetValue(column, i) == value;
        }
        board->SetIsCorrect(!isViolatingRules, column, i);
    }
}

void BoardCreator::ValidateRow(int row, int value) {
    auto rowValues = board->GetValuesInRow(row);
    for (int i = 0; i < board->GetSize(); ++i) {
        bool isViolatingRules = (std::count(rowValues.begin(), rowValues.end(), value) > 1);
        if (isViolatingRules) {
            isViolatingRules = board->GetValue(i, row) == value;
        }
        board->SetIsCorrect(!isViolatingRules, i, row);
    }
}

void BoardCreator::ValidateSection(int column, int row, int value) {
    auto section = board->GetSection(column, row);
    auto sectionValues = section.GetValues();
    for (int i = 0; i < sectionValues.size(); ++i) {
        bool isViolatingRules = (std::count(sectionValues.begin(), sectionValues.end(), value) > 1);
        if (isViolatingRules) {
            isViolatingRules = sectionValues[i] == value;
        }
        board->SetIsCorrect(board->GetSectionId(column, row), i, !isViolatingRules);
    }
}