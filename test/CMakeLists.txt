set(TEST_SOURCES main.cpp StateChangingTest.cpp)

set(SOURCE_FILES ../src/Model/Board.cpp ../src/Model/BoardCell.cpp ../src/Model/BoardSection.cpp
        ../src/AbstractState.cpp ../src/Assets.cpp ../src/Attributes.cpp ../src/Color.cpp ../src/Game.cpp
        ../src/GameModeMenuState.cpp ../src/GfxStream.cpp ../src/MainMenuState.cpp ../src/PlayState.cpp ../src/Position.cpp)

add_definitions(-DTESTING)

add_executable(tests ${SOURCE_FILES} ${TEST_SOURCES})
target_link_libraries(tests Catch)
target_link_libraries(tests curses)

add_test(NAME tests COMMAND tests -d yes --order lex)