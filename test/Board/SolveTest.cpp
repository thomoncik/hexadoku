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
}