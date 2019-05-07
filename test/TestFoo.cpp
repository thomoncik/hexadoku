// tests-factorial.cpp
#include "../vendor/include/catch2/catch.hpp"

TEST_CASE( "True is true", "[always]" ) {
REQUIRE( true );
REQUIRE( false != true );
}