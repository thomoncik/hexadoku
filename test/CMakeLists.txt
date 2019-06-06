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
        ../src/View/GameView.cpp
        ../src/State/PlayStateAbstract.cpp
        ../src/State/InsertionPlayState.cpp
        ../src/Menu/AbstractMenuState.cpp
        ../src/Menu/MainMenuState.cpp
        ../src/Menu/NewGameMenuState.cpp
        ../src/Menu/BoardCreatorMenu.cpp
        ../src/Menu/LoadGameMenu.cpp
        ../src/Menu/LoadGameSizeMenu.cpp)

add_definitions(-DTESTING)

add_executable(tests ${SOURCE_FILES} ${TEST_SOURCES})
target_link_libraries(tests Catch)
target_link_libraries(tests curses)
target_link_libraries(tests ${Boost_LIBRARIES})

add_test(NAME tests COMMAND tests -s -d yes --use-colour yes)
