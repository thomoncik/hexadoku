set(TEST_SOURCES
        main.cpp
        Game/StateChangingTest.cpp
        Game/GameRunningTest.cpp
        Game/GameLoadingTest.cpp
        Board/BoardLoadingTest.cpp
        Board/BoardSaveTest.cpp
        Board/SolveTest.cpp
        Board/ViolatingBoardRulesTest.cpp
        Section/ViolatingSectionRulesTest.cpp)

add_definitions(-DTESTING)
add_executable(tests ${SOURCE_FILES} ${TEST_SOURCES})
target_link_libraries(tests hexadoku_lib ${CONAN_LIBS})

add_test(NAME tests COMMAND tests -s -d yes --use-colour yes)
