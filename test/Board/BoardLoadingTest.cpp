#include <catch2/catch.hpp>
#include <fakeit/fakeit.hpp>

#include <sstream>
#include <Model/Board.hpp>

using namespace fakeit;

SCENARIO("BoardCreator can be loaded from file") {

    GIVEN("Loaded file & standard sized board") {
        std::stringstream fileMockStream;
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
        for (const auto &row : values) {
            for (auto element : row) {
                fileMockStream << element << " ";
            }
        }

        Board board(Board::STANDARD_SIZE);

        WHEN("File is being parsed") {
            board.LoadFromStream(fileMockStream);

            THEN("BoardCreator is loaded") {
                REQUIRE(board.GetValuesAsGrid() == values);
            }
        }
    }

    GIVEN("Loaded file & hexadoku board") {
        std::stringstream fileMockStream;
        std::vector<std::vector<int>> values{
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0},
                {0, 0, 5, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0},
                {0, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0},
                {0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 10, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 15},
        };
        for (const auto &row : values) {
            for (auto element : row) {
                fileMockStream << element << " ";
            }
        }

        Board board(Board::HEXADOKU_SIZE);

        WHEN("File is being parsed") {
            board.LoadFromStream(fileMockStream);

            THEN("BoardCreator is loaded") {
                REQUIRE(board.GetValuesAsGrid() == values);
            }
        }
    }
}