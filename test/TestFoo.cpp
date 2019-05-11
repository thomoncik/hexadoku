#include "../vendor/include/catch2/catch.hpp"
#include "../vendor/include/fakeit/fakeit.hpp"

TEST_CASE( "True is true", "[always]" ) {
REQUIRE( true );
//REQUIRE( false != true );
}