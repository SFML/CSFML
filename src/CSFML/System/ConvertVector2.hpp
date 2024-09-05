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
#include <CSFML/System/Vector2.h>

#include <SFML/System/Vector2.hpp>


////////////////////////////////////////////////////////////
// Convert sf::Vector2 to sfVector2
////////////////////////////////////////////////////////////
[[nodiscard]] inline sfVector2i convertVector2(const sf::Vector2i vector)
{
    return {vector.x, vector.y};
}
[[nodiscard]] inline sfVector2u convertVector2(const sf::Vector2u vector)
{
    return {vector.x, vector.y};
}
[[nodiscard]] inline sfVector2f convertVector2(const sf::Vector2f vector)
{
    return {vector.x, vector.y};
}


////////////////////////////////////////////////////////////
// Convert sfVector2 to sf::Vector2
////////////////////////////////////////////////////////////
[[nodiscard]] inline sf::Vector2i convertVector2(const sfVector2i vector)
{
    return {vector.x, vector.y};
}
[[nodiscard]] inline sf::Vector2u convertVector2(const sfVector2u vector)
{
    return {vector.x, vector.y};
}
[[nodiscard]] inline sf::Vector2f convertVector2(const sfVector2f vector)
{
    return {vector.x, vector.y};
}
