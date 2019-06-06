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
        ../src/State/AbstractState.cpp
        ../src/Graphics/Assets.cpp
        ../src/Graphics/Attributes.cpp
        ../src/Graphics/Color.cpp
        ../src/Game.cpp
        ../src/Graphics/GfxStream.cpp
        ../src/State/MovePlayState.cpp
        ../src/Graphics/Position.cpp
        ../src/View/AbstractView.cpp
        ../src/View/CellView.cpp
        ../src/View/BoardView.cpp
        ../src/View/SectionView.cpp
        ../src/State/PlayStateAbstract.cpp
        ../src/State/InsertionPlayState.cpp
        ../src/State/Menu/AbstractMenuState.cpp
        ../src/State/Menu/MainMenuState.cpp
        ../src/State/Menu/NewGameMenuState.cpp
        ../src/State/Menu/BoardCreatorMenu.cpp
        ../src/State/Menu/LoadGameMenu.cpp
        ../src/State/Menu/LoadGameSizeMenu.cpp
        ../src/State/BoardCreatorState.cpp
        ../src/View/MoveGameView.cpp
        ../src/View/InsertionGameView.cpp
        ../src/Model/PlayStateModel.cpp
        ../src/View/GameViewAbstract.cpp
        ../src/Model/Hint.cpp)

add_definitions(-DTESTING)

add_executable(tests ${SOURCE_FILES} ${TEST_SOURCES})
target_link_libraries(tests Catch)
target_link_libraries(tests curses)
target_link_libraries(tests ${Boost_LIBRARIES})

add_test(NAME tests COMMAND tests -s -d yes --use-colour yes)
