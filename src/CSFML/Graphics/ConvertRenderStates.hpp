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
#include <CSFML/Graphics/ConvertTransform.hpp>
#include <CSFML/Graphics/RenderStates.h>
#include <CSFML/Graphics/ShaderStruct.hpp>
#include <CSFML/Graphics/TextureStruct.hpp>

#include <SFML/Graphics/RenderStates.hpp>


////////////////////////////////////////////////////////////
// Convert sfRenderStates* to sf::RenderStates
////////////////////////////////////////////////////////////
[[nodiscard]] inline sf::RenderStates convertRenderStates(const sfRenderStates* states)
{
    if (!states)
        return {};

    sf::RenderStates renderStates;
    renderStates.blendMode.colorSrcFactor = static_cast<sf::BlendMode::Factor>(states->blendMode.colorSrcFactor);
    renderStates.blendMode.colorDstFactor = static_cast<sf::BlendMode::Factor>(states->blendMode.colorDstFactor);
    renderStates.blendMode.colorEquation  = static_cast<sf::BlendMode::Equation>(states->blendMode.colorEquation);
    renderStates.blendMode.alphaSrcFactor = static_cast<sf::BlendMode::Factor>(states->blendMode.alphaSrcFactor);
    renderStates.blendMode.alphaDstFactor = static_cast<sf::BlendMode::Factor>(states->blendMode.alphaDstFactor);
    renderStates.blendMode.alphaEquation  = static_cast<sf::BlendMode::Equation>(states->blendMode.alphaEquation);
    renderStates.stencilMode.stencilComparison = static_cast<sf::StencilComparison>(states->stencilMode.stencilComparison);
    renderStates.stencilMode.stencilUpdateOperation = static_cast<sf::StencilUpdateOperation>(
        states->stencilMode.stencilUpdateOperation);
    renderStates.stencilMode.stencilReference.value = states->stencilMode.stencilReference.value;
    renderStates.stencilMode.stencilMask.value      = states->stencilMode.stencilMask.value;
    renderStates.stencilMode.stencilOnly            = states->stencilMode.stencilOnly;
    renderStates.transform                          = convertTransform(states->transform);
    renderStates.coordinateType                     = static_cast<sf::CoordinateType>(states->coordinateType);
    renderStates.texture                            = states->texture ? states->texture->This : nullptr;
    renderStates.shader                             = states->shader;
    return renderStates;
}
