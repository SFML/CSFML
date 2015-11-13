
cmake_minimum_required(VERSION 2.8.3)

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
project(CSFML)

# include the configuration file
include(${CMAKE_SOURCE_DIR}/cmake/Config.cmake)

# setup version numbers
set(VERSION_MAJOR 2)
set(VERSION_MINOR 5)
set(VERSION_PATCH 0)

# add the CSFML header path
include_directories(${CMAKE_SOURCE_DIR}/include)

# add an option for choosing the build type (shared or static)
csfml_set_option(BUILD_SHARED_LIBS TRUE BOOL "TRUE to build CSFML as shared libraries, FALSE to build it as static libraries")

# add an option for building the API documentation
csfml_set_option(CSFML_BUILD_DOC FALSE BOOL "TRUE to generate the API documentation, FALSE to ignore it")

# add an option for linking to sfml either statically or dynamically
# default on windows to static and on other platforms to dynamic
if(SFML_OS_WINDOWS)
    set(LINK_STATICALLY_DEFAULT TRUE)
else()
    set(LINK_STATICALLY_DEFAULT FALSE)
endif()
csfml_set_option(CSFML_LINK_SFML_STATICALLY ${LINK_STATICALLY_DEFAULT} BOOL "TRUE to link to a static version of SFML, FALSE to link dynamically")

# disable the rpath stuff
set(CMAKE_SKIP_BUILD_RPATH TRUE)

# define an option for choosing between static and dynamic C runtime (Windows only)
if(SFML_OS_WINDOWS)
    set(STATIC_STD_LIBS FALSE CACHE BOOL "TRUE to statically link to the standard libraries, FALSE to use them as DLLs")

    # for VC++, we can apply it globally by modifying the compiler flags
    if(SFML_COMPILER_MSVC AND STATIC_STD_LIBS)
        foreach(flag
                CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
                CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
            if(${flag} MATCHES "/MD")
                string(REGEX REPLACE "/MD" "/MT" ${flag} "${${flag}}")
            endif()
        endforeach()
    endif()
endif()

# add the subdirectories
add_subdirectory(src/SFML)
if(CSFML_BUILD_DOC)
    add_subdirectory(doc)
endif()

# setup the install rules
install(DIRECTORY include
        DESTINATION .
        COMPONENT devel
        PATTERN ".svn" EXCLUDE)
install(FILES license.txt DESTINATION ${INSTALL_MISC_DIR})
install(FILES readme.txt DESTINATION ${INSTALL_MISC_DIR})
