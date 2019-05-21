#ifndef HEXADOKU_GFXSTREAM_HPP
#define HEXADOKU_GFXSTREAM_HPP

#include <ncurses.h>
#include <iostream>

#include "Position.hpp"
#include "Color.hpp"

class GfxStream;

namespace gfx {
    extern const unsigned SCREEN_WIDTH;
    extern const unsigned SCREEN_HEIGHT;
    extern GfxStream out;

    template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits> &nodecor(std::basic_ostream<_CharT, _Traits> &stream) {
        attrset(A_NORMAL);
        return stream << Color::White << Position(0, 0);
    }

    template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits> &clear(std::basic_ostream<_CharT, _Traits> &stream) {
        attrset(A_NORMAL);
        stream << Color::White;
        erase();
        return stream << Position(0, 0);
    }

    namespace box {
        template<typename _CharT, typename _Traits>
        inline std::basic_ostream<_CharT, _Traits> &ulcorner(std::basic_ostream<_CharT, _Traits> &stream) {
            addch(ACS_ULCORNER);
            return stream;
        }

        template<typename _CharT, typename _Traits>
        inline std::basic_ostream<_CharT, _Traits> &llcorner(std::basic_ostream<_CharT, _Traits> &stream) {
            addch(ACS_LLCORNER);
            return stream;
        }

        template<typename _CharT, typename _Traits>
        inline std::basic_ostream<_CharT, _Traits> &urcorner(std::basic_ostream<_CharT, _Traits> &stream) {
            addch(ACS_URCORNER);
            return stream;
        }

        template<typename _CharT, typename _Traits>
        inline std::basic_ostream<_CharT, _Traits> &lrcorner(std::basic_ostream<_CharT, _Traits> &stream) {
            addch(ACS_LRCORNER);
            return stream;
        }

        template<typename _CharT, typename _Traits>
        inline std::basic_ostream<_CharT, _Traits> &ltee(std::basic_ostream<_CharT, _Traits> &stream) {
            addch(ACS_LTEE);
            return stream;
        }

        template<typename _CharT, typename _Traits>
        inline std::basic_ostream<_CharT, _Traits> &rtee(std::basic_ostream<_CharT, _Traits> &stream) {
            addch(ACS_RTEE);
            return stream;
        }

        template<typename _CharT, typename _Traits>
        inline std::basic_ostream<_CharT, _Traits> &btee(std::basic_ostream<_CharT, _Traits> &stream) {
            addch(ACS_BTEE);
            return stream;
        }

        template<typename _CharT, typename _Traits>
        inline std::basic_ostream<_CharT, _Traits> &ttee(std::basic_ostream<_CharT, _Traits> &stream) {
            addch(ACS_TTEE);
            return stream;
        }

        template<typename _CharT, typename _Traits>
        inline std::basic_ostream<_CharT, _Traits> &hln(std::basic_ostream<_CharT, _Traits> &stream) {
            addch(ACS_HLINE);
            return stream;
        }

        template<typename _CharT, typename _Traits>
        inline std::basic_ostream<_CharT, _Traits> &vln(std::basic_ostream<_CharT, _Traits> &stream) {
            addch(ACS_VLINE);
            return stream;
        }

        template<typename _CharT, typename _Traits>
        inline std::basic_ostream<_CharT, _Traits> &plus(std::basic_ostream<_CharT, _Traits> &stream) {
            addch(ACS_PLUS);
            return stream;
        }
    }
}

class GfxStreamBuffer : public std::streambuf {
public:
    int_type overflow(int_type character) override {
#ifndef TESTING
        return addch(character);
#else
        return character;
#endif
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

#endif //HEXADOKU_GFXSTREAM_HPP
