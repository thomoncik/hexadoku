//
// Created by Jakub Kiermasz on 2019-05-11.
//

#ifndef HEXADOKU_BOARD_HPP
#define HEXADOKU_BOARD_HPP

#include <vector>
#include <istream>
#include <ostream>
#include "BoardSection.hpp"

class Board {
public:
    enum class Difficulty {
        EASY,
        NORMAL,
        HARD,
    };

    static const int STANDARD_SIZE;
    static const int HEXADOKU_SIZE;

    static const std::string SAVED_STANDARD_BOARD_PATH;
    static const std::string SAVED_HEXADOKU_BOARD_PATH;

    /**
     * Creates Board object from grid of given values
     *
     * @return created Board object
     */
    static Board FromGrid(const std::vector<std::vector<int>> &grid);

    /**
     * Creates Board object from grid of given values
     *
     * @return created Board object
     */
    static Board FromGrid(const std::vector<std::vector<int>> &&grid);

    /**
     * Checks how many solutions are possible for given grid
     *
     * @return number of solutions
     */
    static int GetNumberOfSolutions(std::vector<std::vector<int>> &grid);

    /**
     * Checks how many solutions are possible for given grid
     *
     * @return number of solutions
     */
    static int GetNumberOfSolutions(std::vector<std::vector<int>> &&grid);

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

    void SaveToStream(std::ostream &stream) const;

    void LoadFromFile(const std::string &filename);

    void SaveToFile(const std::string &filename) const;

    /**
     * Checks how many solutions are possible
     *
     * @return number of solutions
     */
    int GetNumberOfSolutions() const;

    /**
     * Solve board if possible
     *
     * @return True if solution is good
     */
    bool Solve();

    /**
     * Generate new board with desired difficulty.
     * The harder the puzzle the less clues are given.
     */
    void Generate(Board::Difficulty difficulty);

    /**
     * Checks if each column, each row, and each section contains no duplicates.
     *
     * @return true if duplicate exists in row/column/section
     */
    bool IsViolatingRules() const;

    /**
     * Checks if board is completely filled.
     *
     * @return true if no empty cell is present in board
     */
    bool IsFilled() const;

    /**
     * Fills board with EMPTY_VALUE.
     */
    void Reset();

private:

    std::vector<BoardSection> sections;

    int size;

    int GetValue(int column, int row) const;

    /**
     * Tries to generete board using backtracking algorithm to fill grid
     *
     * @return true if board is filled while keeping rules
     */
    bool GenerateRecursively();
};


#endif //HEXADOKU_BOARD_HPP
