#ifndef HEXADOKU_BOARDCREATOR_HPP
#define HEXADOKU_BOARDCREATOR_HPP

#include <memory>
#include <Model/Board.hpp>

class BoardCreator {
public:
    explicit BoardCreator(int size);

    explicit BoardCreator(std::shared_ptr<Board> board);

    void SetSelected(bool selected, int column, int row);

    int GetSelectedColumn() const;

    void SetSelectedColumn(int column);

    int GetSelectedRow() const;

    void SetSelectedRow(int row);

    void SetValue(int value, int column, int row);

    std::shared_ptr<Board> GetBoard() const;

private:

    std::shared_ptr<Board> board;
    int column{0};

    int row{0};
};

#endif //HEXADOKU_BOARDCREATOR_HPP
