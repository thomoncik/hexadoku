---
description: Hexadoku is a sudoku puzzle where you can choose to play 9x9 or 16x16 grid.
---

# Hexadoku

## Building on Linux and macOS

### Prerequisites

You will need [cmake](https://cmake.org), [conan](https://github.com/conan-io/conan) & compiler of your choice installed. 

### Building

```bash
$ git clone https://github.com/thomoncik/hexadoku.git
$ mkdir hexadoku/build
$ cd hexadoku/build
$ conan install ..
$ cmake ..
$ make install
```

If everything goes well you can type `hexadoku` in terminal and enjoy.

{% hint style="info" %}
Try adding following line to your .bashrc or .bash\_profile if you get error opening `terminal.export TERMINFO=$(infocmp -0qQ1)`
{% endhint %}

## Building on Windows

The best way you can build hexadoku on Windows is to use [Windows Subsystem for Linux](https://docs.microsoft.com/pl-pl/windows/wsl/install-win10). Other option is to use [cygwin](https://www.cygwin.com/) or build it natively \(not recommended\). If you still want to do it you can build it the same way as on Linux or macOS. Just make sure you have cmake, conan and c++ compiler installed.

