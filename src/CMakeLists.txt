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
        Game.cpp
        Graphics/GfxStream.cpp
        State/MovePlayState.cpp
        Graphics/Position.cpp
        View/AbstractView.cpp
        View/CellView.cpp
        View/BoardView.cpp
        View/SectionView.cpp
        View/GameView.cpp
        State/PlayStateAbstract.cpp
        State/InsertionPlayState.cpp
        Menu/AbstractMenuState.cpp
        Menu/MainMenuState.cpp
        Menu/NewGameMenuState.cpp
        Menu/BoardCreatorMenu.cpp
        Menu/LoadGameMenu.cpp
        Menu/LoadGameSizeMenu.cpp Menu/LoadGameMenu.cpp)

add_executable(hexadoku ${SOURCE_FILES})
target_link_libraries(hexadoku curses)
target_link_libraries(hexadoku ${Boost_LIBRARIES})

install(TARGETS ${TARGET_NAME} DESTINATION $ENV{HOME}/.local/bin)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/data/ DESTINATION $ENV{HOME}/.hexadoku/)
