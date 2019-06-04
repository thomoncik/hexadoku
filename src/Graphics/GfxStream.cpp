#include <iostream>

#include "Graphics/GfxStream.hpp"
#include "Graphics/Color.hpp"
#include "Graphics/Position.hpp"

namespace gfx {
    const unsigned SCREEN_WIDTH = 80;
    const unsigned SCREEN_HEIGHT = 24;

    GfxStream out(std::cout);
}

GfxStream::GfxStream(std::ostream &stream) : sourceStream(stream), sourceBuffer(stream.rdbuf()), std::ostream(&gfxBuffer) {
#ifndef TESTING
    stream.rdbuf(rdbuf());
    curs_set(0);
    nodelay(stdscr, TRUE);
    this->HideInput();
#endif
}

GfxStream::~GfxStream() {
#ifndef TESTING
    sourceStream.rdbuf(sourceBuffer);
    endwin();
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
