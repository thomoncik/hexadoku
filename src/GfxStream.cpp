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
    sourceStream.rdbuf(sourceBuffer);
    endwin();
}

GfxStream::GfxStream(std::wostream &stream) : sourceStream(stream), sourceBuffer(stream.rdbuf()), std::wostream(&gfxBuffer) {
    stream.rdbuf(rdbuf());
    curs_set(0);
    nodelay(stdscr, TRUE);
    this->HideInput();
}

void GfxStream::ShowInput() {
    echo();
}

void GfxStream::HideInput() {
    noecho();
}
