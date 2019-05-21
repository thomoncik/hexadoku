//
// Created by Jakub Kiermasz on 2019-05-11.
//

#ifndef HEXADOKU_BOARDSECTION_HPP
#define HEXADOKU_BOARDSECTION_HPP

#include <vector>
#include "BoardCell.hpp"

class BoardSection {
public:
    explicit BoardSection(int size);

    int GetSize() const;

    void SetSelected(bool isSelected, int column, int row);

    void SetValue(int value, int column, int row);

    void SetIsCorrect(bool isCorrect, int column, int row);

    std::vector<int> ValuesInRow(int row);

    std::vector<int> ValuesInColumn(int column);

    std::vector<int> GetValues() const;

    BoardCell GetCell(int column, int row) const;

private:
    std::vector<BoardCell> cells;
    int size;
};


#endif //HEXADOKU_BOARDSECTION_HPP
