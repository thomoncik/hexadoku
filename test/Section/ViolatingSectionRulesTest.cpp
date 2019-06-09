#include <catch2/catch.hpp>
#include <fakeit.hpp>

#include <Model/BoardSection.hpp>
#include <Model/Board.hpp>

using namespace fakeit;

SCENARIO("Duplicates in sections are reported") {
    GIVEN("Standard sized section with duplicate") {
        BoardSection section(Board::STANDARD_SIZE);
        section.SetValue(3, 0, 0);
        section.SetValue(3, 1, 0);

        WHEN("Duplicates are checked") {
            bool duplicates = section.IsViolatingRules();

            THEN("Duplicates are found") {
                REQUIRE(duplicates);
            }
        }
    }

    GIVEN("Hexadoku section with duplicate") {
        BoardSection section(Board::HEXADOKU_SIZE);
        section.SetValue(3, 0, 0);
        section.SetValue(3, 4, 0);

        WHEN("Duplicates are checked") {
            bool duplicates = section.IsViolatingRules();

            THEN("Duplicates are found") {
                REQUIRE(duplicates);
            }
        }
    }

    GIVEN("Standard sized section without duplicates") {
        BoardSection section(Board::STANDARD_SIZE);
        std::vector<std::vector<int>> values = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
        };
        for (int i = 0; i < values.size(); ++i) {
            for (int j = 0; j < values[i].size(); ++j) {
                section.SetValue(values[i][j], j, i);
            }
        }

        WHEN("Duplicates are checked") {
            bool duplicates = section.IsViolatingRules();

            THEN("No duplicates are found") {
                REQUIRE(!duplicates);
            }
        }
    }

    GIVEN("Hexadoku section without duplicates") {
        BoardSection section(Board::HEXADOKU_SIZE);
        std::vector<std::vector<int>> values = {
                {1,  2,  3,  10},
                {4,  5,  6,  11},
                {7,  8,  9,  12},
                {13, 14, 15, 16},
        };
        for (int i = 0; i < values.size(); ++i) {
            for (int j = 0; j < values[i].size(); ++j) {
                section.SetValue(values[i][j], j, i);
            }
        }

        WHEN("Duplicates are checked") {
            bool duplicates = section.IsViolatingRules();

            THEN("No duplicates are found") {
                REQUIRE(!duplicates);
            }
        }
    }

    GIVEN("Empty section") {
        BoardSection section(Board::STANDARD_SIZE);
        BoardSection hexSection(Board::HEXADOKU_SIZE);

        WHEN("Duplicates are checked") {
            bool duplicates = section.IsViolatingRules();
            bool hexDuplicates = hexSection.IsViolatingRules();

            THEN("No duplicates are found") {
                REQUIRE(!duplicates);
                REQUIRE(!hexDuplicates);
            }
        }
    }
}
