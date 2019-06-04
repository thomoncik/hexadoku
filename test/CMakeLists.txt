set(TEST_SOURCES
        main.cpp
        Game/StateChangingTest.cpp
        Board/BoardLoadingTest.cpp
        Board/BoardSaveTest.cpp
        Board/SolveTest.cpp
        Board/VioletingBoardRulesTest.cpp
        Section/VioletingSectionRulesTest.cpp)

set(SOURCE_FILES
        ../src/Model/Board.cpp
        ../src/Model/BoardCell.cpp
        ../src/Model/BoardSection.cpp
        ../src/AbstractState.cpp
        ../src/Assets.cpp
        ../src/Graphics/Attributes.cpp
        ../src/Graphics/Color.cpp
        ../src/Game.cpp
        ../src/Graphics/GfxStream.cpp
        ../src/MovePlayState.cpp
        ../src/Graphics/Position.cpp
        ../src/View/AbstractView.cpp
        ../src/View/CellView.cpp
        ../src/View/BoardView.cpp
        ../src/View/SectionView.cpp
        ../src/View/GameView.cpp
        ../src/PlayStateAbstract.cpp
        ../src/InsertionPlayState.cpp
        ../src/Menu/AbstractMenuState.cpp
        ../src/Menu/MainMenuState.cpp
        ../src/Menu/NewGameMenuState.cpp
        ../src/Menu/BoardCreatorMenu.cpp)

add_definitions(-DTESTING)

add_executable(tests ${SOURCE_FILES} ${TEST_SOURCES})
target_link_libraries(tests Catch)
target_link_libraries(tests curses)

add_test(NAME tests COMMAND tests -d yes --order lex)