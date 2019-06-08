#include <catch2/catch.hpp>
#include <fakeit/fakeit.hpp>

#include <sstream>
#include <Model/Board.hpp>
#include <Model/Game.hpp>

using namespace fakeit;

SCENARIO("game can be loaded from file") {
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
        std::string timeInSeconds = "420", time = "07:00";
        fileMockStream << timeInSeconds << " ";
        for (const auto &row : values) {
            for (auto element : row) {
                fileMockStream << element << " ";
            }
        }

        Game game(Board::STANDARD_SIZE);

        WHEN("File is being parsed") {
            game.LoadFromStream(fileMockStream);

            THEN("Board is loaded") {
                REQUIRE(game.GetBoard()->GetValuesAsGrid() == values);
            }

            THEN("Board time is loaded") {
                REQUIRE(game.GetGameTimeString() == time);
            }
        }
    }

    GIVEN("Loaded file & hexadoku sized board") {
        std::stringstream fileMockStream;
        std::vector<std::vector<int>> values{
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
        std::string timeInSeconds = "135", time = "02:15";
        fileMockStream << timeInSeconds << " ";
        for (const auto &row : values) {
            for (auto element : row) {
                fileMockStream << element << " ";
            }
        }

        Game game(Board::HEXADOKU_SIZE);

        WHEN("File is being parsed") {
            game.LoadFromStream(fileMockStream);

            THEN("Board is loaded") {
                REQUIRE(game.GetBoard()->GetValuesAsGrid() == values);
            }

            THEN("Board time is loaded") {
                REQUIRE(game.GetGameTimeString() == time);
            }
        }
    }
}