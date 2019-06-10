---
description: >-
  All models are responsible for defining how data should look like and how to
  handling logic.
---

# Models

## Board Creator

BoardCreator is associated with all board creator controllers. It holds the board which will be saved, saves it if when it's needed and decides what to do with the board.

## Game

Game is used by game states. It holds the board which will is used to perform a game, inserts values to the board and is responsible for the logic associated with the board.

## Hint

It provides correct value based on the given row, column and board.

## Board

### Board

Board keeps its sections and manages the logic associated with them. In most cases, it passes a value based on a given column and row or asks for it to the appropriate section.

### Board Section

BoardSection hold associated cells and manages their logic. Usually it provides a value based on a given cooridnates or asks for it to the appropriate cell.

### Board Cell

BoardCell stores sudoku board values and manages their behavior. It is also responsible for the information needed to display the board, such as: `isCorrect` and `isHighlighted`.

