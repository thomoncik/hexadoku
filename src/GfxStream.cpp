#include "../include/GfxStream.hpp"

#include <iostream>

#include "../include/Color.hpp"
#include "../include/Position.hpp"

const unsigned GfxStream::SCREEN_WIDTH = 24;
const unsigned GfxStream::SCREEN_HEIGHT = 80;

namespace gfx {
    GfxStream out(std::cout);
}

GfxStream::~GfxStream() {
    #ifndef TESTING
    sourceStream.rdbuf(sourceBuffer);
    endwin();
    #endif
}

GfxStream::GfxStream(std::ostream &stream) : sourceStream(stream), sourceBuffer(stream.rdbuf()), std::ostream(&gfxBuffer) {
    #ifndef TESTING
    stream.rdbuf(rdbuf());
    curs_set(0);
    nodelay(stdscr, TRUE);
    this->HideInput();
    #endif
}

void GfxStream::ShowInput() {
    #ifndef TESTING
    echo();
    #endif
}

void GfxStream::HideInput() {
    #ifndef TESTING
    noecho();
    #endif
}
