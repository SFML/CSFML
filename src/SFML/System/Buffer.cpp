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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/System/Buffer.h>
#include <SFML/System/BufferStruct.h>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfBuffer* sfBuffer_create(void)
{
    return new sfBuffer;
}


////////////////////////////////////////////////////////////
void sfBuffer_destroy(sfBuffer* buffer)
{
    delete buffer;
}


////////////////////////////////////////////////////////////
size_t sfBuffer_getSize(const sfBuffer* buffer)
{
    CSFML_CHECK_RETURN(buffer, 0);
    return buffer->buffer.size();
}


////////////////////////////////////////////////////////////
const sfUint8* sfBuffer_getData(const sfBuffer* buffer)
{
    CSFML_CHECK_RETURN(buffer, NULL);
    return !buffer->buffer.empty() ? &buffer->buffer[0] : NULL;
}
