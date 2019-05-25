#include <catch2/catch.hpp>
#include <fakeit/fakeit.hpp>

#include <Model/Board.hpp>

using namespace fakeit;

SCENARIO("Duplicates in row are reported") {
    GIVEN("Standard sized board with duplicate in row") {
        Board board(Board::STANDARD_SIZE);
        board.SetValue(3, 2, 0);
        board.SetValue(3, 4, 0);

        WHEN("Duplicates are checked") {
            bool duplicates = board.IsViolatingRules();

            THEN("Duplicates are found") {
                REQUIRE(duplicates);
            }
        }
    }

    GIVEN("Hexadoku board with duplicate in row") {
        Board board(Board::HEXADOKU_SIZE);
        board.SetValue(3, 2, 0);
        board.SetValue(3, 4, 0);

        WHEN("Duplicates are checked") {
            bool duplicates = board.IsViolatingRules();

            THEN("Duplicates are found") {
                REQUIRE(duplicates);
            }
        }
    }
}

SCENARIO("Duplicates in column are reported") {
    GIVEN("Standard sized board with duplicate in column") {
        Board board(Board::STANDARD_SIZE);
        board.SetValue(3, 0, 2);
        board.SetValue(3, 0, 4);

        WHEN("Duplicates are checked") {
            bool duplicates = board.IsViolatingRules();

            THEN("Duplicates are found") {
                REQUIRE(duplicates);
            }
        }
    }

    GIVEN("Hexadoku board with duplicate in row") {
        Board board(Board::HEXADOKU_SIZE);
        board.SetValue(3, 0, 2);
        board.SetValue(3, 0, 4);

        WHEN("Duplicates are checked") {
            bool duplicates = board.IsViolatingRules();

            THEN("Duplicates are found") {
                REQUIRE(duplicates);
            }
        }
    }
}

SCENARIO("Duplicates in section are reported") {
    GIVEN("Board with duplicate in section") {
        Board board(Board::STANDARD_SIZE);
        board.SetValue(3, 0, 0);
        board.SetValue(3, 0, 1);

        WHEN("Duplicates are checked") {
            bool duplicates = board.IsViolatingRules();

            THEN("Duplicates are found") {
                REQUIRE(duplicates);
            }
        }
    }
}

SCENARIO("Looking for duplicates in empty board") {
    GIVEN("Empty board") {
        Board board(Board::STANDARD_SIZE);
        WHEN("Duplicates are checked") {
            bool duplicates = board.IsViolatingRules();
            THEN("No duplicates are found") {
                REQUIRE(!duplicates);
            }
        }
    }
}
