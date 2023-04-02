#include <engine/draw.hpp>
#include <engine/general.hpp>

using engine::math::Vector2;

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

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

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

    Vector2 p1(-0.5f, -0.5f);
    Vector2 p2(0.0f, 0.5f);
    Vector2 p3(0.5f, -0.5f);

    float vertices[] = {
      p1.x, p1.y,
      p2.x, p2.y,
      p3.x, p3.y
    };

    uint32_t vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    uint32_t vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    const char *vertex_source = R"glsl(
      #version 330 core

      layout (location = 0) in vec2 vi_pos;

      void main() {
        gl_Position = vec4(vi_pos.x, vi_pos.y, 0.0f, 1.0f);
      }
    )glsl";

    uint32_t vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_source, nullptr);
    glCompileShader(vertex_shader);

    const char *fragment_source = R"glsl(
      #version 330 core

      out vec4 fo_color;

      void main() {
        fo_color = vec4(1.0f, 0.5f, 0.2f, 1.0f);
      }
    )glsl";

    uint32_t fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_source, nullptr);
    glCompileShader(fragment_shader);

    uint32_t program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    glUseProgram(program);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    bool quit = false;
    while (!quit) {
      SDL_Event event;
      while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
          quit = true;
        }
      }

      glClear(GL_COLOR_BUFFER_BIT);
      glDrawArrays(GL_TRIANGLES, 0, 3);
      // draw::triangle(Vector2(-0.5f, -0.5f), Vector2(0.0f, 0.5f), Vector2(0.5f, -0.5f));

      SDL_GL_SwapWindow(window);
      // SDL_SetWindowTitle(window, framerate);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
  }
}
