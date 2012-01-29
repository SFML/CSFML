////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2009 Laurent Gomila (laurent.gom@gmail.com)
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

#ifndef SFML_CONVERTRENDERSTATES_H
#define SFML_CONVERTRENDERSTATES_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/TransformStruct.h>
#include <SFML/Graphics/TextureStruct.h>
#include <SFML/Graphics/ShaderStruct.h>


////////////////////////////////////////////////////////////
// Convert sfRenderStates* to sf::RenderStates
////////////////////////////////////////////////////////////
inline sf::RenderStates ConvertRenderStates(const sfRenderStates* states)
{
    if (!states)
    {
        return sf::RenderStates::Default;
    }
    else
    {
        sf::RenderStates sfmlStates;
        sfmlStates.BlendMode = static_cast<sf::BlendMode>(states->BlendMode);
        sfmlStates.Transform = states->Transform ? states->Transform->This : sf::Transform::Identity;
        sfmlStates.Texture = states->Texture ? states->Texture->This : NULL;
        sfmlStates.Shader = states->Shader ? &states->Shader->This : NULL;

        return sfmlStates;
    }
}


#endif // SFML_CONVERTRENDERSTATES_H
