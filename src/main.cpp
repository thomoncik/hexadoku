#include <streambuf>
#include <ncurses.h>
#include <iostream>
#include <iomanip>

#include <string>
#include <memory>

#include "../include/MainMenuState.hpp"

int main(int argc, char **argv) {
    std::shared_ptr<AbstractState> state = std::make_shared<MainMenuState>();

    while (true) {
        state->Draw();
        state->HandleInput(getch());
        state->Update();
    }
}
