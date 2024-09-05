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
#include <CSFML/System/Export.h>

#include <stdlib.h>


typedef int64_t (*sfInputStreamReadFunc)(void* data, size_t size, void* userData);
typedef int64_t (*sfInputStreamSeekFunc)(size_t position, void* userData);
typedef int64_t (*sfInputStreamTellFunc)(void* userData);
typedef int64_t (*sfInputStreamGetSizeFunc)(void* userData);


////////////////////////////////////////////////////////////
/// \brief Set of callbacks that allow users to define custom file streams
///
////////////////////////////////////////////////////////////
typedef struct sfInputStream
{
    sfInputStreamReadFunc    read;     ///< Function to read data from the stream
    sfInputStreamSeekFunc    seek;     ///< Function to set the current read position
    sfInputStreamTellFunc    tell;     ///< Function to get the current read position
    sfInputStreamGetSizeFunc getSize;  ///< Function to get the total number of bytes in the stream
    void*                    userData; ///< User data that will be passed to the callbacks
} sfInputStream;
