////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2024 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdint.h>


////////////////////////////////////////////////////////////
// Define the CSFML version
////////////////////////////////////////////////////////////
#define CSFML_VERSION_MAJOR 3
#define CSFML_VERSION_MINOR 0
#define CSFML_VERSION_PATCH 0


////////////////////////////////////////////////////////////
// Check if we need to mark functions as extern "C"
////////////////////////////////////////////////////////////
#ifdef __cplusplus
#define CSFML_EXTERN_C extern "C"
#else
#define CSFML_EXTERN_C extern
#endif


////////////////////////////////////////////////////////////
// Identify the operating system
////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(__WIN32__)

// Windows
#define CSFML_SYSTEM_WINDOWS

#elif defined(linux) || defined(__linux)

// Linux
#define CSFML_SYSTEM_LINUX

#elif defined(__APPLE__) || defined(MACOSX) || defined(macintosh) || defined(Macintosh)

// MacOS
#define CSFML_SYSTEM_MACOS

#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)

// FreeBSD
#define CSFML_SYSTEM_FREEBSD

#else

// Unsupported system
#error This operating system is not supported by SFML library

#endif


////////////////////////////////////////////////////////////
// Define helpers to create portable import / export macros for each module
////////////////////////////////////////////////////////////
#if !defined(CSFML_STATIC)

#if defined(CSFML_SYSTEM_WINDOWS)

// Windows compilers need specific (and different) keywords for export and import
#define CSFML_API_EXPORT extern "C" __declspec(dllexport)
#define CSFML_API_IMPORT CSFML_EXTERN_C __declspec(dllimport)

// For Visual C++ compilers, we also need to turn off this annoying C4251 warning
#ifdef _MSC_VER

#pragma warning(disable : 4251)

#endif

#else // Linux, FreeBSD, Mac OS X

#define CSFML_API_EXPORT extern "C" __attribute__((__visibility__("default")))
#define CSFML_API_IMPORT CSFML_EXTERN_C __attribute__((__visibility__("default")))

#endif

#else

// Static build doesn't need import/export macros
#define CSFML_API_EXPORT extern "C"
#define CSFML_API_IMPORT CSFML_EXTERN_C

#endif

////////////////////////////////////////////////////////////
// Cross-platform warning for deprecated functions and classes
//
// Usage:
// struct CSFML_DEPRECATED MyStruct
// {
//     ...
// };
//
// CSFML_DEPRECATED void globalFunc(void);
////////////////////////////////////////////////////////////
#if defined(CSFML_NO_DEPRECATED_WARNINGS)

// User explicitly requests to disable deprecation warnings
#define CSFML_DEPRECATED

#elif defined(_MSC_VER)

// Microsoft C++ compiler
// Note: On newer MSVC versions, using deprecated functions causes a compiler error. In order to
// trigger a warning instead of an error, the compiler flag /sdl- (instead of /sdl) must be specified.
#define CSFML_DEPRECATED __declspec(deprecated)

#elif defined(__GNUC__)

// g++ and Clang
#define CSFML_DEPRECATED __attribute__((deprecated))

#else

// Other compilers are not supported, leave class or function as-is.
// With a bit of luck, the #pragma directive works, otherwise users get a warning (no error!) for unrecognized #pragma.
#pragma message("CSFML_DEPRECATED is not supported for your compiler, please contact the CSFML team")
#define CSFML_DEPRECATED

#endif


////////////////////////////////////////////////////////////
/// Define sfChar32
///
/// Work around macOS not providing <uchar.h>
////////////////////////////////////////////////////////////
#include <stdint.h>
typedef uint32_t sfChar32;
