# AbstractState & StateContext

## AbstractState

In hexadoku we decided to use State design pattern in order to run the game, because games are very specific group of programs. Game has to be run in the game loop. In that loop we can distinguish few logical functions:

* Getting input
* Responding to that input \(updating game\)
* Rendering updated content

We decided to use AbstractState as an interface providing this 3 main actions as well as special actions executed when entering and leaving this state.

## StateContext

StateContext class is used to switch between concrete implementations of AbstractState class.



