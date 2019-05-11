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
    sourceStream.rdbuf(sourceBuffer);
    endwin();
}

GfxStream::GfxStream(std::ostream &stream) : sourceStream(stream), sourceBuffer(stream.rdbuf()), std::ostream(&gfxBuffer) {
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
