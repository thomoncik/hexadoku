# Hexadoku [![Build Status](https://travis-ci.org/thomoncik/hexadoku.svg?branch=master)](https://travis-ci.org/thomoncik/hexadoku)

Hexadoku is a a sudoku game where you can choose to play 9x9 or 16x16 grid

## Installation

Make sure you have [conan](https://github.com/conan-io/conan) installed.

Add `export TERMINFO=$(infocmp -0qQ1)` to your .bashrc 

```bash
git clone https://github.com/thomoncik/hexadoku.git
mkdir hexadoku/build
cd hexadoku/build
conan install ..
cmake ..
make install
```

## Usage

Just type ```hexadoku``` in terminal.

## Contributing
(-)

## License
[MIT](https://choosealicense.com/licenses/mit/)
