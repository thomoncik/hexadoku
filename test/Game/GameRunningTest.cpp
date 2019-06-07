#include "catch2/catch.hpp"
#include "fakeit/fakeit.hpp"

#include "Game.hpp"
#include "AbstractState.hpp"

using namespace fakeit;

SCENARIO("Game can be ran", "[Game]") {

    GIVEN("A game and state") {
        Game game;
        Mock<AbstractState> stateMock;
        Fake(Method(stateMock, OnEntry));
        Fake(Method(stateMock, Draw));
        Fake(Method(stateMock, HandleInput));
        /*
         * Following mock is to set game state to nullptr within Update method,
         * which is the last one called by Ran() in game loop.
         * As the game state is set to nullptr the game loop stops.
         */
        When(Method(stateMock, Update)).Do([](Game &g) { g.SetState(nullptr); });
        Fake(Method(stateMock, OnExit));

        AbstractState *state = &stateMock.get();
        game.SetState(state);

        WHEN("game is ran") {
            game.Run();

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
