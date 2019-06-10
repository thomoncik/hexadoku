---
description: >-
  All controllers are responsible for communication between Model and View,
  handling an input and related actions. All controllers which are application
  states conforms to an AbstractState.
---

# Controllers

## AbstractState

In hexadoku we decided to use State design pattern in order to run the game, because games are very specific group of programs. Game has to be run in the game loop. In that loop we can distinguish few logical functions:

* Getting input
* Responding to that input \(updating game\)
* Rendering updated content

We decided to use AbstractState as an interface providing this 3 main actions as well as special actions executed when entering and leaving this state.

It requires to conform 5 methods:

* `OnEntry()`,
* `Update()`,
* `HandleInput()`,
* `Draw()`,
* `OnExit()`;

  that are called over and over again during application Life Cycle.

## StateContext

StateContext class is used to switch between concrete implementations of AbstractState class.

## Board Creator

* ConfirmExitBoardCreatorState
* InsertionBoardCreatorState
* MoveBoardCreatorState
* SaveBoardCreatorState

All BoardCreator's controllers conforms to `AbstractBoardCreatorState`. These are intended to let user create and save board which can be used for the game.

## Game

* ConfirmExitGameState
* EndGameState
* InsertionGameState
* MoveGameState
* SaveGameState

Game's controllers conforms to `AbstractGameState`. These controllers are intended to perform a game. Board for the game can be created automatically in many levels of difficulty, loaded from unfinished game or saved board template. During the game they measure the time and decide what to do after it ends.

## Menu

* BoardCreatorMenuState
* LoadBoardMenuState
* LoadGameMenuState
* LoadGameSizeMenuState
* LoadOrCreateBoardMenuState
* MainMenuState
* NewGameDifficultyMenuState
* NewGameFromFileMenuState
* NewGameMenuState

These controllers conforms to `AbstractMenuState`. All are responsible for menu navigation and user selection selection. Depending on the selected action, they change the application into the appropriate mode. They are responsible for choosing the basic options needed to run remaining modes.

