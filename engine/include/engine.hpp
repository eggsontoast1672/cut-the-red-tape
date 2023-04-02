#pragma once

#include <cstdlib>
#include <iostream>

#include <GL/glew.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

namespace engine {
  auto exit(const char *message) -> void;
  auto exit_sdl(const char *message) -> void;
  auto run() -> void;
}
