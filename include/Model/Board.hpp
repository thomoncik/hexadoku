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

    explicit Board(int size);

    int GetSize() const;

    int GetSectionSize() const;

    const BoardSection &GetSection(int index) const;

    void SetSelected(bool isSelectd, int column, int row);

    void SetValue(int value, int column, int row);

    void SetIsCorrect(bool isCorrect, int column, int row);

    std::vector<int> ValuesInRow(int row);

    std::vector<int> ValuesInColumn(int column);

    std::vector<std::vector<int>> GetValues() const;

    std::vector<int> GetValues(int index) const;

    int GetSectionId(int column, int row) const;

private:
    std::vector<BoardSection> sections;
    int size;
    int sectionSize;
};


#endif //HEXADOKU_BOARD_HPP
