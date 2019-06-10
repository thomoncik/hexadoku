---
description: >-
  All views are responsible for displaying controller's content. All view
  abstracts conforms to an AbstractView.
---

# Views

## Board Creator and Game

* ConfirmExitBoardCreatorView
* InsertionBoardCreatorView
* MoveBoardCreatorView
* ConfirmExitGameView
* InsertionGameView
* MoveGameView

These views conform to `AbstractBoardCreatorView` or `AbstractGameView`. These are intended to draw the board and information related to current board creator controller and its logic. To draw the board they use BoardView.

## Board

* BoardView
* SectionView
* CellView

All board's views confrom to `AbstractView` because they have no abstract class. Board' draw logic is splitted to draw right amount of sections. Sections are drawing its cells and cells are drawing its values. These views use passed on Board model to display the data.

