#include "catch2/catch.hpp"
#include "fakeit/fakeit.hpp"

#include "Game.hpp"
#include "AbstractState.hpp"

using namespace fakeit;

SCENARIO("States can be changed", "[Game]") {

    GIVEN("A game and state") {
        Game game;
        Mock<AbstractState> oldStateMock, newStateMock;
        Fake(Method(newStateMock, OnEntry));
        Fake(Method(newStateMock, OnExit));
        Fake(Method(oldStateMock, OnEntry));
        Fake(Method(oldStateMock, OnExit));

        AbstractState *oldState = &oldStateMock.get();
        AbstractState *newState = &newStateMock.get();
        
        game.SetState(oldState);

        WHEN("game state is changed to new one") {
            game.SetState(newState);

            THEN("OnExit is called from old state") {
                Verify(Method(oldStateMock, OnExit)).Once();
            }

            THEN("OnEntry is called from new state") {
                Verify(Method(newStateMock, OnEntry)).Once();
            }
        }
    }
}