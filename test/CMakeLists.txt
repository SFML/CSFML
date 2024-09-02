include(FetchContent)

set(CATCH_CONFIG_FAST_COMPILE ON CACHE BOOL "")
set(CATCH_CONFIG_NO_EXPERIMENTAL_STATIC_ANALYSIS_SUPPORT ON CACHE BOOL "")
FetchContent_Declare(Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.7.0
    GIT_SHALLOW ON)
FetchContent_MakeAvailable(Catch2)
include(Catch)

# Build Catch2 in C++17 mode to enable C++17 features
target_compile_features(Catch2 PRIVATE cxx_std_17)

# Ensure that Catch2 sources and headers are not analyzed by any tools
set_target_properties(Catch2 PROPERTIES COMPILE_OPTIONS "" EXPORT_COMPILE_COMMANDS OFF)
set_target_properties(Catch2WithMain PROPERTIES EXPORT_COMPILE_COMMANDS OFF)
get_target_property(CATCH2_INCLUDE_DIRS Catch2 INTERFACE_INCLUDE_DIRECTORIES)
target_include_directories(Catch2 SYSTEM INTERFACE ${CATCH2_INCLUDE_DIRS})

set(CMAKE_CATCH_DISCOVER_TESTS_DISCOVERY_MODE PRE_TEST)

add_executable(test-csfml-system
    System/Buffer.test.cpp
    System/Clock.test.cpp
    System/Sleep.test.cpp
    System/Time.test.cpp
    System/Vector2.test.cpp
    System/Vector3.test.cpp
)
target_link_libraries(test-csfml-system PRIVATE csfml-system Catch2::Catch2WithMain)
set_target_warnings(test-csfml-system)
catch_discover_tests(test-csfml-system)

add_executable(test-csfml-window
    Window/Joystick.test.cpp
)
target_link_libraries(test-csfml-window PRIVATE csfml-window Catch2::Catch2WithMain)
set_target_warnings(test-csfml-window)
catch_discover_tests(test-csfml-window)

add_executable(test-csfml-network
    Network/Ftp.test.cpp
    Network/IpAddress.test.cpp
    Network/SocketStatus.test.cpp
)
target_link_libraries(test-csfml-network PRIVATE csfml-network Catch2::Catch2WithMain SFML::Network)
set_target_warnings(test-csfml-network)
catch_discover_tests(test-csfml-network)

# Copy DLLs into the same directory
if(SFML_OS_WINDOWS AND NOT CSFML_LINK_SFML_STATICALLY)
    add_custom_command(TARGET test-csfml-system  POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:test-csfml-system>  $<TARGET_FILE_DIR:test-csfml-system> COMMAND_EXPAND_LISTS)
    add_custom_command(TARGET test-csfml-window  POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:test-csfml-window>  $<TARGET_FILE_DIR:test-csfml-window> COMMAND_EXPAND_LISTS)
    add_custom_command(TARGET test-csfml-network POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:test-csfml-network> $<TARGET_FILE_DIR:test-csfml-network> COMMAND_EXPAND_LISTS)
endif()
