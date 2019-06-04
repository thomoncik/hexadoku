#include "catch2/catch.hpp"
#include "fakeit/fakeit.hpp"

#include "Game.hpp"
#include "AbstractState.hpp"

using namespace fakeit;

SCENARIO("States can be changed", "[Game]") {

    GIVEN("A game and state") {
        Game game;
        Mock<AbstractState> stateMock;
        Fake(Method(stateMock, OnEntry));
        Fake(Method(stateMock, OnExit));

        WHEN("game state is changed to new one") {
            game.SetState(std::shared_ptr<AbstractState>(&stateMock.get()));

            THEN("OnEntry is called from new state") {
                Verify(Method(stateMock, OnEntry)).Once();
            }
        }
    }
}