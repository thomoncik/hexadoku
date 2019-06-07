#include <catch2/catch.hpp>
#include <fakeit/fakeit.hpp>

#include <Model/Board.hpp>

using namespace fakeit;

SCENARIO("Board can be solved by solver") {
    GIVEN("Standard sized board with values leading to unique solutions") {
        std::vector<std::vector<int>> values{
                {0, 0, 5, 0, 0, 0, 3, 0, 0},
                {0, 0, 0, 0, 7, 0, 0, 8, 6},
                {4, 0, 8, 0, 9, 0, 0, 0, 7},
                {0, 0, 0, 0, 1, 3, 5, 6, 0},
                {0, 0, 0, 0, 0, 9, 0, 4, 0},
                {0, 0, 0, 7, 8, 5, 0, 0, 0},
                {0, 0, 0, 6, 3, 0, 0, 0, 0},
                {8, 0, 3, 0, 0, 0, 0, 7, 0},
                {0, 4, 0, 8, 0, 0, 0, 0, 5},
        };
        Board board = Board::FromGrid(values);

        WHEN("Solver is called") {
            int solutions = board.GetNumberOfSolutions();
            bool isSolved = board.Solve();

            THEN("Only one solution exists") {
                REQUIRE(solutions == 1);
                REQUIRE(isSolved);
            }

            AND_THEN("Solution is solved correctly") {
                std::vector<std::vector<int>> solved{
                        {6, 7, 5, 1, 4, 8, 3, 2, 9},
                        {1, 3, 9, 5, 7, 2, 4, 8, 6},
                        {4, 2, 8, 3, 9, 6, 1, 5, 7},
                        {2, 9, 7, 4, 1, 3, 5, 6, 8},
                        {5, 8, 1, 2, 6, 9, 7, 4, 3},
                        {3, 6, 4, 7, 8, 5, 2, 9, 1},
                        {9, 5, 2, 6, 3, 7, 8, 1, 4},
                        {8, 1, 3, 9, 5, 4, 6, 7, 2},
                        {7, 4, 6, 8, 2, 1, 9, 3, 5}
                };

                REQUIRE(board.GetValuesAsGrid() == solved);
            }
        }
    }

    GIVEN("Hexadoku sized board with values leading to unique solutions") {
        std::vector<std::vector<int>> values{
                {0,  9,  3,  2,  16, 0,  5,  12, 0,  10, 4,  6,  7,  14, 8,  11},
                {15, 0,  10, 12, 0,  6,  2,  9,  7,  11, 8,  0,  5,  4,  3,  0},
                {8,  4,  0,  5,  14, 11, 7,  0,  3,  2,  9,  12, 10, 15, 6,  0},
                {0,  7,  0,  14, 10, 3,  4,  8,  5,  15, 0,  16, 0,  2,  12, 9},
                {3,  8,  9,  10, 7,  12, 0,  5,  0,  6,  11, 4,  0,  1,  15, 2},
                {12, 16, 11, 4,  0,  0,  3,  14, 0,  5,  10, 1,  8,  7,  9,  6},
                {1,  0,  15, 0,  11, 16, 8,  6,  9,  7,  12, 3,  4,  5,  14, 10},
                {7,  14, 5,  0,  4,  9,  1,  10, 8,  16, 0,  15, 12, 0,  11, 3},
                {14, 5,  4,  9,  12, 10, 11, 0,  2,  0,  6,  7,  0,  8,  0,  1},
                {16, 15, 2,  11, 9,  1,  14, 0,  12, 4,  5,  8,  6,  10, 0,  7},
                {0,   0, 7,  1,  8,  5,  16, 4,  10, 0,  0,  11, 15, 9,  2,  12},
                {10, 12, 8,  0,  2,  7,  6,  0,  0,  1,  16, 9,  14, 11, 5,  4},
                {4,  10, 14, 15, 6,  8,  12, 16, 11, 9,  1,  2,  0,  3,  7,  5},
                {5,  11, 0,  7,  3,  0,  0,  2,  16, 12, 0,  10, 9,  6,  1,  8},
                {9,  3,  1,  16, 5,  14, 10, 11, 6,  8,  7,  0,  2,  0,  0,  15},
                {2,  0,  12, 8,  1,  0,  9,  7,  0,  3,  15, 5,  0,  0,  10, 14}
        };
        Board board = Board::FromGrid(values);

        WHEN("Solver is called") {
            int solutions = board.GetNumberOfSolutions();
            bool isSolved = board.Solve();

            THEN("Only one solution exists") {
                REQUIRE(solutions == 1);
                REQUIRE(isSolved);
            }

            AND_THEN("Solution is solved correctly") {
                std::vector<std::vector<int>> solved{
                        {13, 9,  3,  2,  16, 15, 5,  12, 1,  10, 4,  6,  7,  14, 8,  11},
                        {15, 1,  10, 12, 13, 6,  2,  9,  7,  11, 8,  14, 5,  4,  3,  16},
                        {8,  4,  16, 5,  14, 11, 7,  1,  3,  2,  9,  12, 10, 15, 6,  13},
                        {11, 7,  6,  14, 10, 3,  4,  8,  5,  15, 13, 16, 1,  2,  12, 9},
                        {3,  8,  9,  10, 7,  12, 13, 5,  14, 6,  11, 4,  16, 1,  15, 2},
                        {12, 16, 11, 4,  15, 2,  3,  14, 13, 5,  10, 1,  8,  7,  9,  6},
                        {1,  2,  15, 13, 11, 16, 8,  6,  9,  7,  12, 3,  4,  5,  14, 10},
                        {7,  14, 5,  6,  4,  9,  1,  10, 8,  16, 2,  15, 12, 13, 11, 3},
                        {14, 5,  4,  9,  12, 10, 11, 15, 2,  13, 6,  7,  3,  8,  16, 1},
                        {16, 15, 2,  11, 9,  1,  14, 3,  12, 4,  5,  8,  6,  10, 13, 7},
                        {6,  13, 7,  1,  8,  5,  16, 4,  10, 14, 3,  11, 15, 9,  2,  12},
                        {10, 12, 8,  3,  2,  7,  6,  13, 15, 1,  16, 9,  14, 11, 5,  4},
                        {4,  10, 14, 15, 6,  8,  12, 16, 11, 9,  1,  2,  13, 3,  7,  5},
                        {5,  11, 13, 7,  3,  4,  15, 2,  16, 12, 14, 10, 9,  6,  1,  8},
                        {9,  3,  1,  16, 5,  14, 10, 11, 6,  8,  7,  13, 2,  12, 4,  15},
                        {2,  6,  12, 8,  1,  13, 9,  7,  4,  3,  15, 5,  11, 16, 10, 14}
                };


                REQUIRE(board.GetValuesAsGrid() == solved);
            }
        }
    }
}