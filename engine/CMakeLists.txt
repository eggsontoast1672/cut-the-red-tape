add_library(
  engine
  src/engine.cpp
  src/glad/glad.c
)

target_include_directories(engine PUBLIC ${SDL2_INCLUDE_DIRS} include)
target_link_libraries(engine PRIVATE ${SDL2_LIBRARIES})
