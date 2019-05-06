#include <streambuf>
#include <ncurses.h>
#include <iostream>
#include <iomanip>

#include "../include/GfxStream.hpp"
#include "../include/Position.hpp"
#include "../include/Color.hpp"
#include "../include/Attributes.hpp"

using namespace std::string_literals;

const auto logo = "   888    888                                 888          888               \n"
                  "   888    888                                 888          888               \n"
                  "   888    888                                 888          888               \n"
                  "   8888888888  .d88b.  888  888  8888b.   .d88888  .d88b.  888  888 888  888 \n"
                  "   888    888 d8P  Y8b `Y8bd8P'     \"88b d88\" 888 d88\"\"88b 888 .88P 888  888 \n"
                  "   888    888 88888888   X88K   .d888888 888  888 888  888 888888K  888  888 \n"
                  "   888    888 Y8b.     .d8\"\"8b. 888  888 Y88b 888 Y88..88P 888 \"88b Y88b 888 \n"
                  "   888    888  \"Y8888  888  888 \"Y888888  \"Y88888  \"Y88P\"  888  888  \"Y88888 \n"s;

int main(int argc, char **argv) {
    GfxStream::out << Position(0, 3) << Color::Blue << Attribute::BOLD << logo << GfxStream::nodecor;

    int selected = 0;
    std::array<std::string, 3> options = {"New game"s, "Puzzle creator"s, "Exit"s};
    while (true) {
        for (int i = 0; i < options.size(); ++i) {
            if (i == selected) {
                GfxStream::out << Attribute::STANDOUT;
            }
            GfxStream::out << std::setw("Puzzle creator"s.size()) << Position(30, 13 + i) << options.at(i) << GfxStream::nodecor;
        }

        char c = getch();
        if (c == 'j') {
            selected = (selected + 1) % options.size();
        } else if (c == 'k') {
            selected--;
            if (selected < 0) {
                selected = options.size() - 1;
            }
        } else if (c == 'q') {
            break;
        }
    }
    return 0;
}
