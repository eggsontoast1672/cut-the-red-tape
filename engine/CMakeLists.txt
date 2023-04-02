find_package(PkgConfig)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(GLEW REQUIRED glew)

add_library(engine src/engine.cpp)

target_include_directories(engine PUBLIC include)

target_link_libraries(engine PRIVATE ${SDL2_LIBRARIES})
target_link_libraries(engine PRIVATE ${GLEW_LIBRARIES})
