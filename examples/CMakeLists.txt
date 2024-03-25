add_executable(example example.c)
target_link_libraries(example PRIVATE csfml-graphics csfml-audio)
set_target_warnings(example)
