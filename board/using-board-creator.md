# Generating board

## Idea

To generate sudoku \(hexadoku\) board backtracking algorithm is used. In first step we have board filled with empty values. Algorithm then tries to put new value in place of empty one without violating sudoku rules. That is:

* Values in each row have to be unique
* Values in each column have to be unique
* Values in each section \(smaller square\) have to be unique

There is one unofficial, additional rule in the world of sudoku: there can be only one solution. After running backtracking while constantly permuting vector of possible values we get random sudoku board.

To generate puzzle all we have to do is to remove some of the values while remaining only one solution.

