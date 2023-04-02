#include <engine/draw.hpp>

namespace engine::draw {

auto triangle(Vector2 p1, Vector2 p2, Vector2 p3) -> void {
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

  glDrawArrays(GL_TRIANGLES, 0, 3);

  // glDeleteVertexArrays(1, &vao);
  // glDeleteBuffers(1, &vbo);
}

}
