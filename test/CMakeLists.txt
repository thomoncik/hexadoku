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
        ../src/StateContext.cpp
        ../src/Graphics/GfxStream.cpp
        ../src/State/Game/MoveGameState.cpp
        ../src/Graphics/Position.cpp
        ../src/View/AbstractView.cpp
        ../src/View/Board/CellView.cpp
        ../src/View/Board/BoardView.cpp
        ../src/View/Board/SectionView.cpp
        ../src/State/Game/AbstractGameState.cpp
        ../src/State/Game/InsertionGameState.cpp
        ../src/State/Menu/AbstractMenuState.cpp
        ../src/State/Menu/MainMenuState.cpp
        ../src/State/Menu/NewGameMenuState.cpp
        ../src/State/Menu/BoardCreatorMenu.cpp
        ../src/State/Menu/LoadGameMenu.cpp
        ../src/State/Menu/LoadGameSizeMenu.cpp
        ../src/State/BoardCreator/AbstractBoardCreatorState.cpp
        ../src/View/Game/MoveGameView.cpp
        ../src/View/Game/InsertionGameView.cpp
        ../src/Model/Game.cpp
        ../src/View/Game/AbstractGameView.cpp
        ../src/Model/Hint.cpp
        ../src/State/BoardCreator/InsertionBoardCreatorState.cpp
        ../src/State/BoardCreator/MoveBoardCreatorState.cpp
        ../src/Model/BoardCreator.cpp
        ../src/View/BoardCreator/AbstractBoardCreatorView.cpp
        ../src/View/BoardCreator/MoveBoardCreatorView.cpp
        ../src/View/BoardCreator/InsertionBoardCreatorView.cpp
        ../src/State/Menu/LoadBoardSizeMenuState.cpp
        ../src/State/Menu/LoadBoardMenuState.cpp
        ../src/State/BoardCreator/SaveBoardCreatorState.cpp
        ../src/State/Game/SaveGameState.cpp)

add_definitions(-DTESTING)

add_executable(tests ${SOURCE_FILES} ${TEST_SOURCES})
target_link_libraries(tests Catch)
target_link_libraries(tests curses)
target_link_libraries(tests ${Boost_LIBRARIES})

add_test(NAME tests COMMAND tests -s -d yes --use-colour yes)
