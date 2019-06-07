set(TARGET_NAME hexadoku)

set(SOURCE_FILES
        main.cpp
        Model/Board.cpp
        Model/BoardCell.cpp
        Model/BoardSection.cpp
        State/AbstractState.cpp
        Graphics/Assets.cpp
        Graphics/Attributes.cpp
        Graphics/Color.cpp
        StateContext.cpp
        Graphics/GfxStream.cpp
        State/Game/MoveGameState.cpp
        Graphics/Position.cpp
        View/AbstractView.cpp
        View/Board/CellView.cpp
        View/Board/BoardView.cpp
        View/Board/SectionView.cpp
        State/Game/AbstractGameState.cpp
        State/Game/InsertionGameState.cpp
        State/Menu/AbstractMenuState.cpp
        State/Menu/MainMenuState.cpp
        State/Menu/NewGameMenuState.cpp
        State/Menu/BoardCreatorMenu.cpp
        State/Menu/LoadGameMenu.cpp
        State/Menu/LoadGameSizeMenu.cpp
        State/BoardCreator/AbstractBoardCreatorState.cpp
        View/Game/MoveGameView.cpp
        View/Game/InsertionGameView.cpp
        Model/Game.cpp
        View/Game/AbstractGameView.cpp
        Model/Hint.cpp
        State/BoardCreator/InsertionBoardCreatorState.cpp
        State/BoardCreator/MoveBoardCreatorState.cpp
        Model/BoardCreator.cpp
        View/BoardCreator/AbstractBoardCreatorView.cpp
        View/BoardCreator/MoveBoardCreatorView.cpp
        View/BoardCreator/InsertionBoardCreatorView.cpp
        State/Menu/LoadBoardSizeMenuState.cpp
        State/Menu/LoadBoardMenuState.cpp
        State/BoardCreator/SaveBoardCreatorState.cpp
        State/Game/SaveGameState.cpp)

add_executable(hexadoku ${SOURCE_FILES})
target_link_libraries(hexadoku curses)
target_link_libraries(hexadoku ${Boost_LIBRARIES})

install(TARGETS ${TARGET_NAME} DESTINATION $ENV{HOME}/.local/bin)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/data/ DESTINATION $ENV{HOME}/.hexadoku/)
