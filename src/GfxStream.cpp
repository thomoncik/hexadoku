#include <iostream>

#include "../include/GfxStream.hpp"
#include "../include/Color.hpp"
#include "../include/Position.hpp"

namespace gfx {
    const unsigned SCREEN_WIDTH = 80;
    const unsigned SCREEN_HEIGHT = 24;

    GfxStream out(std::wcout);
}

GfxStream::~GfxStream() {
#ifndef TESTING
    sourceStream.rdbuf(sourceBuffer);
    endwin();
#endif
}

GfxStream::GfxStream(std::wostream &stream) : sourceStream(stream), sourceBuffer(stream.rdbuf()), std::wostream(&gfxBuffer) {
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
