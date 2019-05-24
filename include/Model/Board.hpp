//
// Created by Jakub Kiermasz on 2019-05-11.
//

#ifndef HEXADOKU_BOARD_HPP
#define HEXADOKU_BOARD_HPP

#include <vector>
#include <istream>
#include "BoardSection.hpp"

class Board {
public:
    static const int STANDARD_SIZE;
    static const int HEXADOKU_SIZE;

    explicit Board(int size);

    int GetSize() const;

    int GetSectionRowSize() const;

    const BoardSection &GetSection(int index) const;

    void SetSelected(bool isSelectd, int column, int row);

    void SetValue(int value, int column, int row);

    void SetIsCorrect(bool isCorrect, int column, int row);

    std::vector<int> GetValuesInRow(int row) const;

    std::vector<int> GetValuesInColumn(int column) const;

    std::vector<std::vector<int>> GetValuesPerSection() const;

    std::vector<std::vector<int>> GetValuesAsGrid() const;

    int GetSectionId(int column, int row) const;

    void LoadFromStream(std::istream &stream);

private:
    std::vector<BoardSection> sections;
    int size;

    int GetValue(int column, int row) const;
};


#endif //HEXADOKU_BOARD_HPP
