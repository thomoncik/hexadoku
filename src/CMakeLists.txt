set(TARGET_NAME hexadoku)

set(SOURCE_FILES main.cpp Attributes.cpp Color.cpp GfxStream.cpp Position.cpp AbstractState.cpp MainMenuState.cpp
        Game.cpp PlayState.cpp Views/BoardCell.cpp Views/BoardSection.cpp)


add_executable(hexadoku ${SOURCE_FILES})
target_link_libraries(hexadoku curses)

install(TARGETS ${TARGET_NAME} DESTINATION ${PROJECT_SOURCE_DIR}/bin)
