set(TARGET_NAME hexadoku)

set(SOURCE_FILES
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
        State/Menu/BoardCreatorMenuState.cpp
        State/Menu/LoadGameMenuState.cpp
        State/Menu/LoadGameSizeMenuState.cpp
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
        State/Menu/LoadOrCreateBoardMenuState.cpp
        State/Menu/LoadBoardMenuState.cpp
        State/BoardCreator/SaveBoardCreatorState.cpp
        State/Game/EndGameState.cpp
        State/Game/SaveGameState.cpp
        State/Menu/NewGameDifficultyMenuState.cpp
        State/Menu/NewGameFromFileMenuState.cpp
        State/Game/ConfirmExitGameState.cpp
        View/Game/ConfirmExitGameView.cpp
        State/BoardCreator/ConfirmExitBoardCreatorState.cpp
        View/BoardCreator/ConfirmExitBoardCreatorView.cpp)

add_library(hexadoku_lib ${SOURCE_FILES})
add_executable(hexadoku main.cpp)
target_link_libraries(hexadoku hexadoku_lib ${CONAN_LIBS})

install(TARGETS ${TARGET_NAME} DESTINATION $ENV{HOME}/.local/bin)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/data/ DESTINATION $ENV{HOME}/.hexadoku/)
