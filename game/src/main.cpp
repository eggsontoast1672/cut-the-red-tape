#include <engine/general.hpp>

// engine::Texture background;

auto load() -> void {
  // background = engine::load_texture("images/background.png");
}

auto draw() -> void {
  // engine::draw_texture(background, engine::Vector2(0, 0));
}

auto main(int argc, char **argv) -> int {
  // engine::set_load_callback(load);
  // engine::set_draw_callback(draw);
  engine::run();

  return 0;
}
