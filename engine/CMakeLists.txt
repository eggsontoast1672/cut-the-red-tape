add_library(
  engine
  src/engine/general.cpp
  src/engine/graphics.cpp
  src/engine/math.cpp
  src/glad/glad.c
)

set_property(TARGET engine PROPERTY CXX_STANDARD 17)

target_include_directories(engine PUBLIC ${SDL2_INCLUDE_DIRS} include)
target_link_libraries(engine PRIVATE ${SDL2_LIBRARIES})
