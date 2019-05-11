#ifndef HEXADOKU_GFXSTREAM_HPP
#define HEXADOKU_GFXSTREAM_HPP

#include <ostream>
#include <ncurses.h>
#include <iostream>

#include "Position.hpp"
#include "Color.hpp"

class GfxStreamBuffer : public std::streambuf {
public:
    int overflow(int character) override {
        return printw("%c", character);
    }
};

class GfxStream : public std::ostream {
public:
    static const unsigned SCREEN_WIDTH;
    static const unsigned SCREEN_HEIGHT;

    explicit GfxStream(std::ostream &stream);

    ~GfxStream() override;

    void ShowInput();

    void HideInput();

private:
    GfxStreamBuffer gfxBuffer;
    std::ostream &sourceStream;
    std::streambuf *const sourceBuffer;
};

namespace gfx {
    template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits> &nodecor(std::basic_ostream<_CharT, _Traits> &stream) {
        attrset(A_NORMAL);
        return stream << Color::White << Position(0, 0);
    }

    template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits> &clear(std::basic_ostream<_CharT, _Traits> &stream) {
        attrset(A_NORMAL);
        stream << Color::White << Position(0, 0) << std::string(GfxStream::SCREEN_WIDTH * GfxStream::SCREEN_HEIGHT - 1, ' ');
        return stream << Position(0, 0);
    }

    extern GfxStream out;
}

#endif //HEXADOKU_GFXSTREAM_HPP
