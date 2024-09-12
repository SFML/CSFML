cmake_minimum_required(VERSION 3.22)

# define a macro that helps defining an option
macro(csfml_set_option var default type docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

# set a default build type if none was provided
# this has to be done before the project() instruction!
csfml_set_option(CMAKE_BUILD_TYPE Release STRING "Choose the type of build (Debug or Release)")

# project name
project(CSFML VERSION 3.0.0)

# we use the paths from the cmake GNUInstallDirs module as defaults
# you can override these if you like
# https://cmake.org/cmake/help/latest/module/GNUInstallDirs.html
include(GNUInstallDirs)

# include the configuration file
include(${PROJECT_SOURCE_DIR}/cmake/Config.cmake)

# add options to select which modules to build
csfml_set_option(CSFML_BUILD_WINDOW ON BOOL "ON to build CSFML's Window module. This setting is ignored, if the graphics module is built.")
csfml_set_option(CSFML_BUILD_GRAPHICS ON BOOL "ON to build CSFML's Graphics module.")
csfml_set_option(CSFML_BUILD_AUDIO ON BOOL "ON to build CSFML's Audio module.")
csfml_set_option(CSFML_BUILD_NETWORK ON BOOL "ON to build CSFML's Network module.")

# add an option for choosing the build type (shared or static)
csfml_set_option(BUILD_SHARED_LIBS ON BOOL "ON to build CSFML as shared libraries, OFF to build it as static libraries")

# add an option for building the API documentation
csfml_set_option(CSFML_BUILD_DOC OFF BOOL "ON to generate the API documentation, OFF to ignore it")

# add an option for linking to sfml either statically or dynamically
# default on windows to static and on other platforms to dynamic
if(SFML_OS_WINDOWS)
    set(LINK_STATICALLY_DEFAULT ON)
else()
    set(LINK_STATICALLY_DEFAULT OFF)
endif()
csfml_set_option(CSFML_LINK_SFML_STATICALLY ${LINK_STATICALLY_DEFAULT} BOOL "ON to link to a static version of SFML, OFF to link dynamically")

# define an option for choosing between static and dynamic C runtime (Windows only)
if(SFML_OS_WINDOWS)
    csfml_set_option(CSFML_USE_STATIC_STD_LIBS OFF BOOL "ON to statically link to the standard libraries, OFF to use them as DLLs")
endif()

# find SFML libraries (C++)
if(CSFML_LINK_SFML_STATICALLY)
    set(SFML_STATIC_LIBRARIES ON)
endif()
set(SFML_MODULES "System")
if(CSFML_BUILD_AUDIO)
    list(PREPEND SFML_MODULES "Audio")
endif()
if(CSFML_BUILD_GRAPHICS)
    list(PREPEND SFML_MODULES "Graphics")
endif()
if(CSFML_BUILD_WINDOW)
    list(PREPEND SFML_MODULES "Window")
endif()
if(CSFML_BUILD_NETWORK)
    list(PREPEND SFML_MODULES "Network")
endif()
find_package(SFML 3.0.0 COMPONENTS ${SFML_MODULES} REQUIRED)

# add the subdirectories
add_subdirectory(src/CSFML)
if(CSFML_BUILD_DOC)
    add_subdirectory(doc)
endif()

# on Linux and BSD-like OS, install pkg-config files by default
set(CSFML_INSTALL_PKGCONFIG_DEFAULT OFF)

if(SFML_OS_LINUX OR SFML_OS_FREEBSD OR SFML_OS_OPENBSD OR SFML_OS_NETBSD)
    set(CSFML_INSTALL_PKGCONFIG_DEFAULT ON)
endif()

csfml_set_option(CSFML_INSTALL_PKGCONFIG_FILES ${CSFML_INSTALL_PKGCONFIG_DEFAULT} BOOL "ON to automatically install pkg-config files so other projects can find SFML")

if(CSFML_INSTALL_PKGCONFIG_FILES)
    csfml_set_option(CSFML_PKGCONFIG_INSTALL_DIR "${CSFML_PKGCONFIG_DIR}" PATH "Install directory for CSFML's pkg-config .pc files")

    foreach(csfml_module IN ITEMS all system window graphics audio network)
        configure_file(
            "tools/pkg-config/csfml-${csfml_module}.pc.in"
            "tools/pkg-config/csfml-${csfml_module}.pc"
            @ONLY)
        install(FILES "${CMAKE_CURRENT_BINARY_DIR}/tools/pkg-config/csfml-${csfml_module}.pc"
            DESTINATION "${CSFML_PKGCONFIG_INSTALL_DIR}")
    endforeach()
endif()

# setup the install rules
install(DIRECTORY include/
        DESTINATION include
        COMPONENT devel)
install(FILES license.md DESTINATION ${INSTALL_MISC_DIR})
install(FILES readme.md DESTINATION ${INSTALL_MISC_DIR})

# stop configuration if consuming CSFML as a subdirectory
if(NOT PROJECT_IS_TOP_LEVEL)
    return()
endif()

# add an option for building the examples
csfml_set_option(CSFML_BUILD_EXAMPLES OFF BOOL "ON to build the CSFML examples, OFF to ignore them")
if(CSFML_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# add an option for building the tests
csfml_set_option(CSFML_BUILD_TEST_SUITE OFF BOOL "ON to build the CSFML test suite, OFF to ignore it")
if(CSFML_BUILD_TEST_SUITE)
    enable_testing()
    add_subdirectory(test)
endif()

csfml_set_option(CLANG_FORMAT_EXECUTABLE clang-format STRING "Override clang-format executable, requires version 14")
add_custom_target(format
    COMMAND ${CMAKE_COMMAND} -DCLANG_FORMAT_EXECUTABLE=${CLANG_FORMAT_EXECUTABLE} -P ./cmake/Format.cmake
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} VERBATIM)

csfml_set_option(CLANG_TIDY_EXECUTABLE clang-tidy STRING "Override clang-tidy executable, requires minimum version 14")
add_custom_target(tidy
    COMMAND ${CMAKE_COMMAND} -DCLANG_TIDY_EXECUTABLE=${CLANG_TIDY_EXECUTABLE} -DPROJECT_BINARY_DIR=${PROJECT_BINARY_DIR} -P ./cmake/Tidy.cmake
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} VERBATIM)
