cmake_minimum_required(VERSION 3.21)

project(cut-the-red-tape)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# If only pkg-config were available on windows...
if(MSVC)
  set(SDL2_DIR ${CMAKE_SOURCE_DIR}/sdl2/cmake)
  find_package(SDL2 CONFIG REQUIRED)
else()
  find_package(PkgConfig)
  pkg_check_modules(SDL2 REQUIRED sdl2)
endif()

add_subdirectory(engine)
add_subdirectory(game)
