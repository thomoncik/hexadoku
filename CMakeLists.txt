cmake_minimum_required(VERSION 3.9.2)
project(hexadoku)

set(CMAKE_CXX_STANDARD 14)
set(CURSES_USE_NCURSES TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(SOURCE_FILES src/main.cpp src/Color.cpp src/Position.cpp src/Attributes.cpp src/GfxStream.cpp)
add_executable(hexadoku ${SOURCE_FILES})
target_link_libraries(hexadoku curses)


install(TARGETS hexadoku DESTINATION bin)
