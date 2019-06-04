set(TARGET_NAME hexadoku)

set(SOURCE_FILES main.cpp Model/Board.cpp Model/BoardCell.cpp Model/BoardSection.cpp
        AbstractState.cpp Assets.cpp Attributes.cpp Color.cpp Game.cpp
        GfxStream.cpp MovePlayState.cpp Position.cpp MenuState.cpp View/AbstractView.cpp View/CellView.cpp
        View/BoardView.cpp View/SectionView.cpp View/GameView.cpp PlayStateAbstract.cpp InsertionPlayState.cpp AbstractMenuState.cpp MainMenuState.cpp NewGameMenuState.cpp)


add_executable(hexadoku ${SOURCE_FILES})
target_link_libraries(hexadoku curses)

install(TARGETS ${TARGET_NAME} DESTINATION $ENV{HOME}/.local/bin)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/data/ DESTINATION $ENV{HOME}/.hexadoku/)
