#include "../vendor/include/catch2/catch.hpp"
#include "../vendor/include/fakeit/fakeit.hpp"

#include "../include/Game.hpp"
#include "../include/AbstractState.hpp"

using namespace fakeit;

SCENARIO("States can be changed", "[Game]") {

    GIVEN("A game and state") {
        Game game;
        Mock<AbstractState> state;
        Fake(Method(state, OnEntry));
        Fake(Method(state, OnExit));

        WHEN("game state is changed to new one") {
            game.SetState(&state.get());

            THEN("OnEntry is called from new state") {
                Verify(Method(state, OnEntry)).Once();
            }
        }
    }
}