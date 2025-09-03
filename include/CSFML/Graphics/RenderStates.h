////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2025 Laurent Gomila (laurent@sfml-dev.org)
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
#include <CSFML/Graphics/Export.h>

#include <CSFML/Graphics/BlendMode.h>
#include <CSFML/Graphics/CoordinateType.h>
#include <CSFML/Graphics/StencilMode.h>
#include <CSFML/Graphics/Transform.h>
#include <CSFML/Graphics/Types.h>


////////////////////////////////////////////////////////////
/// \brief Define the states used for drawing to a RenderTarget
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfBlendMode      blendMode;      ///< Blending mode
    sfStencilMode    stencilMode;    //!< Stencil mode
    sfTransform      transform;      ///< Transform
    sfCoordinateType coordinateType; //!< Texture coordinate type
    const sfTexture* texture;        ///< Texture
    const sfShader*  shader;         ///< Shader
} sfRenderStates;

////////////////////////////////////////////////////////////
/// \brief Define the default values for a RenderState
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const sfRenderStates sfRenderStates_default;
