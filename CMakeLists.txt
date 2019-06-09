cmake_minimum_required(VERSION 3.9.2)
project(hexadoku)

enable_testing()
set(CMAKE_CXX_STANDARD 14)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

set(CURSES_NEED_WIDE TRUE)
set(CURSES_USE_NCURSES TRUE)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/vendor/include)

add_subdirectory(src)
add_subdirectory(test)
