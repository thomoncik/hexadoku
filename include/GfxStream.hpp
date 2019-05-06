#ifndef HEXADOKU_GFXSTREAM_HPP
#define HEXADOKU_GFXSTREAM_HPP


#include <ostream>
#include <ncurses.h>
#include "Position.hpp"
#include "Color.hpp"

class GfxStreamBuffer : public std::streambuf {
public:
    GfxStreamBuffer() = default;

    int overflow(int c) override {
        return printw("%c", c);
    }
};

class GfxStream : public std::ostream {
public:
    GfxStreamBuffer tbuf_;
    std::ostream &src_;
    std::streambuf *const srcbuf_;

    explicit GfxStream(std::ostream &o) : src_(o), srcbuf_(o.rdbuf()), std::ostream(&tbuf_) {
        o.rdbuf(rdbuf());
        curs_set(0);
        noecho();
    }

    ~GfxStream() override {
        src_.rdbuf(srcbuf_);
        endwin();
    }

    static GfxStream out;


    template<typename _CharT, typename _Traits>
    inline static std::basic_ostream<_CharT, _Traits> &nodecor(std::basic_ostream<_CharT, _Traits> &__os) {
        attrset(A_NORMAL);
        __os << Color::White << Position(0, 0);
        return __os;
    }
};

#endif //HEXADOKU_GFXSTREAM_HPP
