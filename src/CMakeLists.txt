set(TARGET_NAME hexadoku)

set(SOURCE_FILES main.cpp Views/Board.cpp Views/BoardCell.cpp Views/BoardSection.cpp
        AbstractState.cpp Assets.cpp Attributes.cpp Color.cpp Game.cpp GamemodeMenuState.cpp
        GfxStream.cpp MainMenuState.cpp PlayState.cpp Position.cpp)

add_executable(hexadoku ${SOURCE_FILES})
target_link_libraries(hexadoku curses)

install(TARGETS ${TARGET_NAME} DESTINATION ${PROJECT_SOURCE_DIR}/bin)
