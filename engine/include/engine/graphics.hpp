#pragma once

#include <glad/glad.h>

#include <engine/general.hpp>
#include <engine/math.hpp>

using engine::math::Vector2;

namespace engine::graphics {
  auto initialize() -> void;
  auto triangle(Vector2 p1, Vector2 p2, Vector2 p3) -> void;
}
