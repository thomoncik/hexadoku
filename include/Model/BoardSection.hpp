//
// Created by Jakub Kiermasz on 2019-05-11.
//

#ifndef HEXADOKU_BOARDSECTION_HPP
#define HEXADOKU_BOARDSECTION_HPP

#include <vector>
#include "BoardCell.hpp"

class BoardSection {
public:
    BoardSection(int size);
    int GetSize() const ;
    void SetSelected(bool isSelected, int row, int column);
    void SetValue(int value, int row, int column);
    void SetIsCorrect(bool isCorrect, int row, int column);
    std::vector<int> ValuesInRow(int row);
    std::vector<int> ValuesInColumn(int column);
private:
    std::vector<BoardCell> cells;
    int size;
};


#endif //HEXADOKU_BOARDSECTION_HPP
