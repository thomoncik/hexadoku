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

    int GetRowSize() const;

    void SetSelected(bool isSelected, int column, int row);

    void SetValue(int value, int column, int row);

    void SetIsCorrect(bool isCorrect, int column, int row);

    std::vector<int> GetValuesInRow(int row) const;

    std::vector<int> GetValuesInColumn(int column) const;

    std::vector<int> GetValues() const;

    int GetValue(int column, int row) const;

    BoardCell GetCell(int column, int row) const;

    /**
     * Checks if each cell in section is unique
     *
     * @return true if duplicate exists false otherwise
     */
    bool IsVioletingRules() const;

private:
    std::vector<BoardCell> cells;
    int size;
};


#endif //HEXADOKU_BOARDSECTION_HPP
