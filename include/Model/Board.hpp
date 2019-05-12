//
// Created by Jakub Kiermasz on 2019-05-11.
//

#ifndef HEXADOKU_BOARD_HPP
#define HEXADOKU_BOARD_HPP

#include <vector>

#include "BoardSection.hpp"

class Board {
public:
    static const int STANDARD_SIZE;
    static const int HEXADOKU_SIZE;
    Board(int size);
    int GetSize() const;
    int GetSectionSize() const;
    const BoardSection& GetSection(int index) const;
    void SetSelected(bool isSelectd, int row, int column);
    void SetValue(int value, int row, int column);
    void SetIsCorrect(bool isCorrect, int row, int column);
    std::vector<int> ValuesInRow(int row);
    std::vector<int> ValuesInColumn(int column);
private:
    std::vector<BoardSection> sections;
    int size;
    int sectionSize;
};


#endif //HEXADOKU_BOARD_HPP
