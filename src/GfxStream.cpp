#include "../include/GfxStream.hpp"

#include <iostream>

#include "../include/Color.hpp"
#include "../include/Position.hpp"

GfxStream GfxStream::out(std::cout);
const unsigned GfxStream::SCREEN_WIDTH = 24;
const unsigned GfxStream::SCREEN_HEIGHT = 80;