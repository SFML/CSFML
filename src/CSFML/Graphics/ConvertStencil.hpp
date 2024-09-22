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
#include <CSFML/Graphics/StencilMode.h>

#include <SFML/Graphics/StencilMode.hpp>


////////////////////////////////////////////////////////////
// Convert sf::StencilValue to sfStencilValue
////////////////////////////////////////////////////////////
[[nodiscard]] inline sfStencilValue convertStencilValue(const sf::StencilValue value)
{
    return {value.value};
}

////////////////////////////////////////////////////////////
// Convert sfStencilValue to sf::StencilValue
////////////////////////////////////////////////////////////
[[nodiscard]] inline sf::StencilValue convertStencilValue(const sfStencilValue value)
{
    return {value.value};
}


////////////////////////////////////////////////////////////
// Convert sf::StencilMode to sfStencilMode
////////////////////////////////////////////////////////////
[[nodiscard]] inline sfStencilMode convertStencilMode(const sf::StencilMode value)
{
    return {static_cast<sfStencilComparison>(value.stencilComparison),
            static_cast<sfStencilUpdateOperation>(value.stencilUpdateOperation),
            convertStencilValue(value.stencilReference),
            convertStencilValue(value.stencilMask),
            value.stencilOnly};
}

////////////////////////////////////////////////////////////
// Convert sfStencilMode to sf::StencilMode
////////////////////////////////////////////////////////////
[[nodiscard]] inline sf::StencilMode convertStencilMode(const sfStencilMode value)
{
    return {static_cast<sf::StencilComparison>(value.stencilComparison),
            static_cast<sf::StencilUpdateOperation>(value.stencilUpdateOperation),
            convertStencilValue(value.stencilReference),
            convertStencilValue(value.stencilMask),
            value.stencilOnly};
}
