include(CMakeParseArguments)
include(${PROJECT_SOURCE_DIR}/cmake/CompilerWarnings.cmake)

# add a new target which is a CSFML library
# ex: csfml_add_library(csfml-graphics
#                       SOURCES sprite.cpp image.cpp ...
#                       DEPENDS sfml-window sfml-system)
macro(csfml_add_library target)

    # parse the arguments
    cmake_parse_arguments(THIS "" "" "SOURCES;DEPENDS;EXTERNAL_LIBS" ${ARGN})

    # create the target
    add_library(${target} ${THIS_SOURCES})

    # add the CSFML header path
    target_include_directories(${target} PUBLIC ${PROJECT_SOURCE_DIR}/include)

    # add warnings
    set_target_warnings(${target})

    # require C11 and C++17
    target_compile_features(${target} PUBLIC c_std_11 cxx_std_17)

    # define the export symbol of the module
    string(REPLACE "-" "_" NAME_UPPER "${target}")
    string(TOUPPER "${NAME_UPPER}" NAME_UPPER)
    set_target_properties(${target} PROPERTIES DEFINE_SYMBOL ${NAME_UPPER}_EXPORTS)

    if(SFML_OS_WINDOWS)
        # include the major version number in Windows shared library names (but not import library names)
        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -d)
        set_target_properties(${target} PROPERTIES SUFFIX "-${PROJECT_VERSION_MAJOR}${CMAKE_SHARED_LIBRARY_SUFFIX}")
    else()
        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -d)
    endif()
    if (SFML_OS_WINDOWS AND SFML_COMPILER_GCC)
        # on Windows/gcc get rid of "lib" prefix for shared libraries,
        # and transform the ".dll.a" suffix into ".a" for import libraries
        set_target_properties(${target} PROPERTIES PREFIX "")
        set_target_properties(${target} PROPERTIES IMPORT_SUFFIX ".a")
    endif()

    # set the version and soversion of the target (for compatible systems -- mostly Linuxes)
    set_target_properties(${target} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR})
    set_target_properties(${target} PROPERTIES VERSION ${PROJECT_VERSION})

    # set the target's folder (for IDEs that support it, e.g. Visual Studio)
    set_target_properties(${target} PROPERTIES FOLDER "CSFML")

    # apply the SFML_USE_STATIC_STD_LIBS option if it is enabled
    if(SFML_OS_WINDOWS AND SFML_COMPILER_GCC)
        if(SFML_USE_STATIC_STD_LIBS AND NOT SFML_COMPILER_GCC_TDM)
            set_target_properties(${target} PROPERTIES LINK_FLAGS "-static-libgcc -static-libstdc++")
        elseif(NOT SFML_USE_STATIC_STD_LIBS AND SFML_COMPILER_GCC_TDM)
            set_target_properties(${target} PROPERTIES LINK_FLAGS "-shared-libgcc -shared-libstdc++")
        endif()
    endif()

    # ensure public symbols are hidden by default (exported ones are explicitly marked)
    set_target_properties(${target} PROPERTIES CXX_VISIBILITY_PRESET hidden VISIBILITY_INLINES_HIDDEN YES)

    # link the target to its external dependencies (C++ SFML libraries)
    target_link_libraries(${target} PRIVATE ${THIS_DEPENDS})

    # build dylibs
    if(SFML_OS_MACOSX AND BUILD_SHARED_LIBS)
        # adapt install directory to allow distributing dylibs in user’s application bundle
        set_target_properties(${target} PROPERTIES INSTALL_NAME_DIR "@rpath")
    endif()

    # add the install rule
    install(TARGETS ${target}
            RUNTIME DESTINATION bin COMPONENT bin
            LIBRARY DESTINATION lib${LIB_SUFFIX} COMPONENT bin
            ARCHIVE DESTINATION lib${LIB_SUFFIX} COMPONENT devel)

endmacro()
