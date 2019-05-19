set(TARGET_NAME hexadoku)

set(SOURCE_FILES main.cpp Model/Board.cpp Model/BoardCell.cpp Model/BoardSection.cpp
        AbstractState.cpp Assets.cpp Attributes.cpp Color.cpp Game.cpp
        GfxStream.cpp PlayState.cpp Position.cpp MenuState.cpp View/AbstractView.cpp View/CellView.cpp
        View/BoardView.cpp View/SectionView.cpp)

add_executable(hexadoku ${SOURCE_FILES})
target_link_libraries(hexadoku curses)

install(TARGETS ${TARGET_NAME} DESTINATION ${PROJECT_SOURCE_DIR}/bin)
