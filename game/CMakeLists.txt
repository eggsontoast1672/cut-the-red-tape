add_executable(tape src/main.cpp)

target_link_libraries(tape PRIVATE engine)

if(MSVC)
  add_custom_command(
    TARGET tape POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${SDL2_LIBDIR}/SDL2.dll $<TARGET_FILE_DIR:tape>
  )
endif()

add_custom_target(run COMMAND tape DEPENDS tape)
