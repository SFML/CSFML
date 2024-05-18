
# include the SFML specific macros
include(${PROJECT_SOURCE_DIR}/cmake/Macros.cmake)

# add the CSFML sources path
include_directories(${PROJECT_SOURCE_DIR}/src)

# set the output directory for CSFML libraries
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")

# define the export symbol
add_definitions(-DCSFML_EXPORTS)

# disable stupid warnings with Visual C++
if(SFML_COMPILER_MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

# find SFML libraries (C++)
if(CSFML_LINK_SFML_STATICALLY)
    set(SFML_STATIC_LIBRARIES TRUE)
    add_definitions(-DSFML_STATIC)
endif()
set(SFML_MODULES "system")
if(CSFML_BUILD_AUDIO)
    list(PREPEND SFML_MODULES "audio")
endif()
if(CSFML_BUILD_GRAPHICS)
    list(PREPEND SFML_MODULES "graphics")
endif()
if(CSFML_BUILD_WINDOW)
    list(PREPEND SFML_MODULES "window")
endif()
if(CSFML_BUILD_NETWORK)
    list(PREPEND SFML_MODULES "network")
endif()
find_package(SFML 2.6 COMPONENTS ${SFML_MODULES} REQUIRED)

# add the modules subdirectories
add_subdirectory(System)

if(CSFML_BUILD_WINDOW OR CSFML_BUILD_GRAPHICS)
    add_subdirectory(Window)
endif()

if(CSFML_BUILD_NETWORK)
    add_subdirectory(Network)
endif()

if(CSFML_BUILD_GRAPHICS)
    add_subdirectory(Graphics)
endif()

if(CSFML_BUILD_AUDIO)
    add_subdirectory(Audio)
endif()

if(SFML_OS_WINDOWS)
    add_subdirectory(Main)
endif()
