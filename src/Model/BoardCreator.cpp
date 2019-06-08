#include <Model/BoardCreator.hpp>

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

