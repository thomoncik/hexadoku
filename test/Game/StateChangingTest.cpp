#include "catch2/catch.hpp"
#include "fakeit/fakeit.hpp"

#include "Game.hpp"
#include "State/AbstractState.hpp"

using namespace fakeit;

SCENARIO("States can be changed") {

    GIVEN("A game and state") {
        Mock<AbstractState> oldStateMock, newStateMock;
        Fake(Dtor(oldStateMock), Dtor(newStateMock));
        Fake(Method(newStateMock, OnEntry), Method(newStateMock, OnExit));
        Fake(Method(oldStateMock, OnEntry), Method(oldStateMock, OnExit));

        Game game;

        game.SetState(std::shared_ptr<AbstractState>(&oldStateMock.get()));

        WHEN("game state is changed to new one") {
            game.SetState(std::shared_ptr<AbstractState>(&newStateMock.get()));

            THEN("OnExit is called from old state") {
                Verify(Method(oldStateMock, OnExit)).Once();
            }

            THEN("OnEntry is called from new state") {
                Verify(Method(newStateMock, OnEntry)).Once();
            }
        }
    }
}