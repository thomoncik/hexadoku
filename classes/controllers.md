---
description: >-
  All controllers are responsible for communication between Model and View,
  handling an input and related actions. All controllers which are application
  states conforms to an AbstractState.
---

# Controllers



### AbstractState

It requires to conform 5 methods:

* `OnEntry()`,
* `Update()`,
* `HandleInput()`,
* `Draw()`,
* `OnExit()`;

  that are called over and over again during application Life Cycle.

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

