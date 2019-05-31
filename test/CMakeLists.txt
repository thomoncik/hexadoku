set(TEST_SOURCES main.cpp Game/StateChangingTest.cpp)

set(SOURCE_FILES ../src/Model/Board.cpp ../src/Model/BoardCell.cpp ../src/Model/BoardSection.cpp
        ../src/AbstractState.cpp ../src/Assets.cpp ../src/Attributes.cpp ../src/Color.cpp ../src/Game.cpp
        ../src/GfxStream.cpp ../src/MovePlayState.cpp ../src/Position.cpp ../src/MenuState.cpp
        ../src/View/AbstractView.cpp ../src/View/CellView.cpp ../src/View/BoardView.cpp ../src/View/SectionView.cpp
<<<<<<< HEAD
        ../src/View/GameViewAbstract.cpp Board/BoardLoadingTest.cpp Board/BoardSaveTest.cpp Board/SolveTest.cpp Board/VioletingBoardRulesTest.cpp Section/VioletingSectionRulesTest.cpp ../src/PlayStateAbstract.cpp ../src/InsertionPlayState.cpp ../src/View/MoveGameView.cpp ../src/View/InsertionGameView.cpp)
=======
        ../src/View/GameView.cpp Board/BoardLoadingTest.cpp Board/BoardSaveTest.cpp Board/SolveTest.cpp Board/VioletingBoardRulesTest.cpp Section/VioletingSectionRulesTest.cpp ../src/PlayStateAbstract.cpp ../src/InsertionPlayState.cpp ../src/Model/PlayStateModel.cpp)
>>>>>>> Fix timer reset on entry.

add_definitions(-DTESTING)

add_executable(tests ${SOURCE_FILES} ${TEST_SOURCES})
target_link_libraries(tests Catch)
target_link_libraries(tests curses)

add_test(NAME tests COMMAND tests -d yes --order lex)