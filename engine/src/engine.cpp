#include <engine.hpp>

namespace engine {
  auto exit(const char *message) -> void {
    std::cerr << message << std::endl;
    std::exit(1);
  }

  auto exit_sdl(const char *message) -> void {
    std::cerr << message << ": " << SDL_GetError() << std::endl;
    std::exit(1);
  }

  auto run() -> void {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
      engine::exit_sdl("Failed to initialize SDL");

    SDL_Window *window = SDL_CreateWindow(
      "Test",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      SDL_WINDOW_OPENGL
    );

    if (window == nullptr)
      engine::exit_sdl("Failed to create window");

    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (context == nullptr)
      engine::exit_sdl("Failed to greate OpenGL context");

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
      engine::exit("Failed to initialize glad");

    bool quit = false;
    while (!quit) {
      SDL_Event event;
      while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
          quit = true;
        }
      }

      glClear(GL_COLOR_BUFFER_BIT);
      SDL_GL_SwapWindow(window);
      // SDL_SetWindowTitle(window, framerate);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
  }
}
