set(TEST_SOURCES main.cpp TestFoo.cpp StateChangingTest.cpp)

set(SOURCE_FILES ../src/Views/Board.cpp ../src/Views/BoardCell.cpp ../src/Views/BoardSection.cpp
        ../src/AbstractState.cpp ../src/Assets.cpp ../src/Attributes.cpp ../src/Color.cpp ../src/Game.cpp
        ../src/GamemodeMenuState.cpp ../src/GfxStream.cpp ../src/MainMenuState.cpp ../src/PlayState.cpp ../src/Position.cpp)

add_definitions(-DTESTING)

add_executable(tests ${SOURCE_FILES} ${TEST_SOURCES})
target_link_libraries(tests Catch)
target_link_libraries(tests curses)

add_test(NAME tests COMMAND tests)