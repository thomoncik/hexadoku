set(TARGET_NAME tests)

# Make test executable
set(TEST_SOURCES main.cpp TestFoo.cpp)
add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests Catch)
target_link_libraries(tests curses)

add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME} -o report.xml -r junit)