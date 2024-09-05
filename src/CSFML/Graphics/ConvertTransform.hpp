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
#include <CSFML/Graphics/Transform.h>

#include <SFML/Graphics/Transform.hpp>


////////////////////////////////////////////////////////////
// Convert sf::Transform to sfTransform
////////////////////////////////////////////////////////////
[[nodiscard]] inline sfTransform convertTransform(const sf::Transform& transform)
{
    const float* m = transform.getMatrix();
    return {m[0], m[4], m[12], m[1], m[5], m[13], m[3], m[7], m[15]};
}


////////////////////////////////////////////////////////////
// Convert sfTransform to sf::Transform
////////////////////////////////////////////////////////////
[[nodiscard]] inline sf::Transform convertTransform(const sfTransform& transform)
{
    const float* m = transform.matrix;

    // clang-format off
    return {m[0], m[1], m[2],
            m[3], m[4], m[5],
            m[6], m[7], m[8]};
    // clang-format on
}
