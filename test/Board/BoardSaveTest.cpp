#include <catch2/catch.hpp>
#include <fakeit/fakeit.hpp>

#include <sstream>
#include <Model/Board.hpp>

using namespace fakeit;

SCENARIO("BoardCreator can be saved to stream") {
    GIVEN("Standard sized filled board") {
        Board board(Board::STANDARD_SIZE);
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
        for (int y = 0; y < Board::STANDARD_SIZE; ++y) {
            for (int x = 0; x < Board::STANDARD_SIZE; ++x) {
                board.SetValue(values[y][x], x, y);
            }
        }
        
        WHEN("BoardCreator is saved to stream") {
            std::stringstream stream;
            board.SaveToStream(stream);

            THEN("BoardCreator is loaded") {
                std::vector<std::vector<int>> loadedValues(Board::STANDARD_SIZE, std::vector<int>(Board::STANDARD_SIZE));
                for (int y = 0; y < Board::STANDARD_SIZE; ++y) {
                    for (int x = 0; x < Board::STANDARD_SIZE; ++x) {
                        bool absorber;
                        stream >> loadedValues[y][x] >> absorber;
                    }
                }
                REQUIRE(board.GetValuesAsGrid() == loadedValues);
            }
        }
    }

    GIVEN("Filled hexadoku board") {
        Board board(Board::HEXADOKU_SIZE);
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
        for (int y = 0; y < Board::HEXADOKU_SIZE; ++y) {
            for (int x = 0; x < Board::HEXADOKU_SIZE; ++x) {
                board.SetValue(values[y][x], x, y);
            }
        }

        WHEN("BoardCreator is saved to stream") {
            std::stringstream stream;
            board.SaveToStream(stream);

            THEN("BoardCreator is loaded") {
                std::vector<std::vector<int>> loadedValues(Board::HEXADOKU_SIZE, std::vector<int>(Board::HEXADOKU_SIZE));
                for (int y = 0; y < Board::HEXADOKU_SIZE; ++y) {
                    for (int x = 0; x < Board::HEXADOKU_SIZE; ++x) {
                        bool absorber;
                        stream >> loadedValues[y][x] >> absorber;
                    }
                }
                REQUIRE(board.GetValuesAsGrid() == loadedValues);
            }
        }
    }
}