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
#include <CSFML/System/ConvertVector2.hpp>
#include <CSFML/Window/Cursor.h>
#include <CSFML/Window/CursorStruct.hpp>


////////////////////////////////////////////////////////////
sfCursor* sfCursor_createFromPixels(const uint8_t* pixels, sfVector2u size, sfVector2u hotspot)
{
    auto cursor = sf::Cursor::createFromPixels(pixels, convertVector2(size), convertVector2(hotspot));
    if (!cursor)
        return nullptr;

    return new sfCursor{std::move(*cursor)};
}


////////////////////////////////////////////////////////////
sfCursor* sfCursor_createFromSystem(sfCursorType type)
{
    auto cursor = sf::Cursor::createFromSystem(static_cast<sf::Cursor::Type>(type));
    if (!cursor)
        return nullptr;

    return new sfCursor{std::move(*cursor)};
}


////////////////////////////////////////////////////////////
void sfCursor_destroy(const sfCursor* cursor)
{
    delete cursor;
}
