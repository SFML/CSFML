set(SRC example.c)

add_executable(example ${SRC})
target_link_libraries(example PRIVATE csfml-graphics csfml-audio)
set_file_warnings(${SRC})
