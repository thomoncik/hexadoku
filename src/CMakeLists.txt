set(TARGET_NAME hexadoku)

set(SOURCE_FILES main.cpp Model/Board.cpp Model/BoardCell.cpp Model/BoardSection.cpp
        AbstractState.cpp Assets.cpp Attributes.cpp Color.cpp Game.cpp GameModeMenuState.cpp
        GfxStream.cpp MainMenuState.cpp PlayState.cpp Position.cpp)

add_executable(hexadoku ${SOURCE_FILES})
target_link_libraries(hexadoku curses)

install(TARGETS ${TARGET_NAME} DESTINATION ${PROJECT_SOURCE_DIR}/bin)
