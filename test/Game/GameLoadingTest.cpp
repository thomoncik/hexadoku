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
        fileMockStream << "420 ";
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
        }
    }
}