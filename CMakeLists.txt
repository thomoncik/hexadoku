cmake_minimum_required(VERSION 3.9.2)
project(hexadoku)

enable_testing()
set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/vendor/include)

set(CURSES_NEED_WIDE TRUE)
set(CURSES_USE_NCURSES TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CATCH_INCLUDE_DIR vendor/include/catch2)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE include/catch2)

add_subdirectory(src)
add_subdirectory(test)