#include <catch2/catch.hpp>
#include <fakeit.hpp>

#include "StateContext.hpp"
#include "State/AbstractState.hpp"

using namespace fakeit;

SCENARIO("Game can be ran") {

    GIVEN("A game and state") {
        StateContext stateContext;
        Mock<AbstractState> stateMock;
        Fake(Method(stateMock, OnEntry));
        Fake(Method(stateMock, Draw));
        Fake(Method(stateMock, HandleInput));
        /*
         * Following mock is to set game state to nullptr within Update method,
         * which is the last one called by Ran() in game loop.
         * As the game state is set to nullptr the game loop stops.
         */
        When(Method(stateMock, Update)).Do([](StateContext &g) { g.SetState(nullptr); });
        Fake(Method(stateMock, OnExit));

        stateContext.SetState(std::shared_ptr<AbstractState>(&stateMock.get()));

        WHEN("game is ran") {
            stateContext.Run();

            THEN("Draw is called from state") {
                Verify(Method(stateMock, Draw)).Once();
            }

            THEN("HandleInput is called from state") {
                Verify(Method(stateMock, HandleInput)).Once();
            }

            THEN("Update is called from state") {
                Verify(Method(stateMock, Update)).Once();
            }

            THEN("Draw, HandleInput, Update are called with right order") {
                Verify(Method(stateMock, Draw), Method(stateMock, HandleInput), Method(stateMock, Update));
            }
        }
    }
}
