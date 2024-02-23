# detect the OS
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(SFML_OS_WINDOWS 1)

    # detect the architecture (note: this test won't work for cross-compilation)
    include(CheckTypeSize)
    check_type_size(void* SIZEOF_VOID_PTR)
    if("${SIZEOF_VOID_PTR}" STREQUAL "4")
        set(ARCH_32BITS 1)
    elseif("${SIZEOF_VOID_PTR}" STREQUAL "8")
        set(ARCH_64BITS 1)
    else()
        message(FATAL_ERROR "Unsupported architecture")
        return()
    endif()
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(SFML_OS_LINUX 1)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
    set(SFML_OS_FREEBSD 1)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(SFML_OS_MACOSX 1)

    # detect OS X version. (use '/usr/bin/sw_vers -productVersion' to extract V from '10.V.x'.)
    EXEC_PROGRAM(/usr/bin/sw_vers ARGS -productVersion OUTPUT_VARIABLE MACOSX_VERSION_RAW)
    STRING(REGEX REPLACE "10\\.([0-9]+).*" "\\1" MACOSX_VERSION "${MACOSX_VERSION_RAW}")
    if(${MACOSX_VERSION} LESS 5)
        message(FATAL_ERROR "Unsupported version of OS X : ${MACOSX_VERSION_RAW}")
        return()
    endif()
else()
    message(FATAL_ERROR "Unsupported operating system")
    return()
endif()

# set pkgconfig install directory
# this could be e.g. macports on mac or msys2 on windows etc.
set(CSFML_PKGCONFIG_DIR "${CMAKE_INSTALL_LIBDIR}/pkgconfig")

if(SFML_OS_FREEBSD OR SFML_OS_OPENBSD OR SFML_OS_NETBSD)
    set(CSFML_PKGCONFIG_DIR "libdata/pkgconfig")
endif()

# detect the compiler and its version
# Note: The detection is order is important because:
# - Visual Studio can both use MSVC and Clang
# - GNUCXX can still be set on macOS when using Clang
if(MSVC)
    set(SFML_COMPILER_MSVC 1)

    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        set(SFML_COMPILER_CLANG_CL 1)
    endif()
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(SFML_COMPILER_CLANG 1)

    execute_process(COMMAND "${CMAKE_CXX_COMPILER}" "--version" OUTPUT_VARIABLE CLANG_VERSION_OUTPUT)
    string(REGEX REPLACE ".*clang version ([0-9]+\\.[0-9]+).*" "\\1" SFML_CLANG_VERSION "${CLANG_VERSION_OUTPUT}")
elseif(CMAKE_COMPILER_IS_GNUCXX)
    set(SFML_COMPILER_GCC 1)

    execute_process(COMMAND "${CMAKE_CXX_COMPILER}" "-dumpversion" OUTPUT_VARIABLE GCC_VERSION_OUTPUT)
    string(REGEX REPLACE "([0-9]+\\.[0-9]+).*" "\\1" SFML_GCC_VERSION "${GCC_VERSION_OUTPUT}")
    execute_process(COMMAND "${CMAKE_CXX_COMPILER}" "--version" OUTPUT_VARIABLE GCC_COMPILER_VERSION)
    string(REGEX MATCHALL ".*(tdm[64]*-[1-9]).*" SFML_COMPILER_GCC_TDM "${GCC_COMPILER_VERSION}")
    execute_process(COMMAND "${CMAKE_CXX_COMPILER}" "-dumpmachine" OUTPUT_VARIABLE GCC_MACHINE)
    string(STRIP "${GCC_MACHINE}" GCC_MACHINE)

    if(GCC_MACHINE MATCHES ".*w64.*")
        set(SFML_COMPILER_GCC_W64 1)
    endif()
else()
    message(FATAL_ERROR "Unsupported compiler")
    return()
endif()

# define the install directory for miscellaneous files
if(SFML_OS_WINDOWS)
    set(INSTALL_MISC_DIR .)
elseif(SFML_OS_LINUX OR SFML_OS_FREEBSD OR SFML_OS_MACOSX)
    set(INSTALL_MISC_DIR share/CSFML)
endif()
