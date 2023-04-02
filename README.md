# Cut The Red Tape!

## Overview

A game of tape-throwing and rule-breaking.

I originally started to make this game for the [Mini Jame Gam #16][1], but
plans changed and I ended up making a different game. The idea for this project
was so good, though, that I just couldn't leave it behind.

It's some sort of a competition involving duct tape, but you have to cheat to
win when nobody is looking.

- Duct-tape-roll-throwing competition
- The one who can throw the roll of duct tape the furthest wins
- You have to unravel it while nobody is looking

[1]: https://itch.io/jam/mini-jame-gam-16

## Compiling

### Linux

If you're on Linux, you're in luck, because compiling is a snap. Make sure you
have a C++ compiler, CMake, pkg-config, and the SDL2 development files
installed.

On Ubuntu, the command below should get you into shape. You may have to run it
with super user privilages. If you're running an OS other than that, I assume
you can handle yourself in the package-downloading department.

```bash
apt install g++ cmake pkg-config libsdl2-dev
```

Then, once you have those installed, just create a build directory, `cd` into
it, generate the build files, and compile.

```bash
# Create a build directory
mkdir build

# cd into it
cd build

# Generate build files
cmake ..

# Compile
make
```

Once you've done that, the executable should be `build/game/tape`.

### Windows

Ok, so you're on Windows. All I can say is, you're in for it now.

The first thing you'll want to do is download Visual Studio. In the installer,
select the `C++ Desktop Development` option to get access to all the neat C++
tools. By the time that's done, I'm sure this section of the docs will be
finished.
