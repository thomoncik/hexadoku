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

bool BoardCreator::IsCorrect(int column, int row) const {
    int value = board->GetValue(column, row);
    if (value == BoardCell::EMPTY_VALUE) return true;
    std::vector<int> columnValues = board->GetValuesInColumn(column);
    std::vector<int> rowValues = board->GetValuesInRow(row);
    if (std::count(columnValues.begin(), columnValues.end(), value) > 1) {
        return false;
    }
    return std::count(rowValues.begin(), rowValues.end(), value) <= 1;
}

void BoardCreator::SetIsCorrect(bool isCorrect, int column, int row) {
    board->SetIsCorrect(isCorrect, column, row);
}