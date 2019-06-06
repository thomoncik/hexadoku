#include "catch2/catch.hpp"
#include "fakeit/fakeit.hpp"

#include "Game.hpp"
#include "State/AbstractState.hpp"

using namespace fakeit;

SCENARIO("States can be changed") {

    GIVEN("A game and state") {
        Mock<AbstractState> stateMock;
        Fake(Dtor(stateMock));
        Fake(Method(stateMock, OnEntry), Method(stateMock, OnExit));

        Game game;

        WHEN("game state is changed to new one") {
            game.SetState(std::shared_ptr<AbstractState>(&stateMock.get()));

            THEN("OnEntry is called from new state") {
                Verify(Method(stateMock, OnEntry)).Once();
            }
        }
    }
}