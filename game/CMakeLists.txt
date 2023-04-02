add_executable(tape src/main.cpp)

target_link_libraries(tape PRIVATE engine)

add_custom_target(run COMMAND tape DEPENDS tape)
