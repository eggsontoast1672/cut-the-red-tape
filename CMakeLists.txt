cmake_minimum_required(VERSION 3.22)
project(cut-the-red-tape)

find_package(PkgConfig)
pkg_check_modules(SFML REQUIRED sfml-all)

add_executable(tape
  src/main.cpp
)
target_link_libraries(tape ${SFML_LIBRARIES})

add_custom_target(run COMMAND tape DEPENDS tape)
