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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Transformable.h>
#include <SFML/Graphics/TransformableStruct.h>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfTransformable* sfTransformable_Create(void)
{
    sfTransformable* transformable = new sfTransformable;

    return transformable;
}


////////////////////////////////////////////////////////////
sfTransformable* sfTransformable_Copy(sfTransformable* transformable)
{
    CSFML_CHECK_RETURN(transformable, NULL);

    return new sfTransformable(*transformable);
}


////////////////////////////////////////////////////////////
void sfTransformable_Destroy(sfTransformable* transformable)
{
    delete transformable;
}


////////////////////////////////////////////////////////////
void sfTransformable_SetPosition(sfTransformable* transformable, sfVector2f position)
{
    CSFML_CALL(transformable, SetPosition(position.x, position.y));
}


////////////////////////////////////////////////////////////
void sfTransformable_SetRotation(sfTransformable* transformable, float angle)
{
    CSFML_CALL(transformable, SetRotation(angle));
}


////////////////////////////////////////////////////////////
void sfTransformable_SetScale(sfTransformable* transformable, sfVector2f scale)
{
    CSFML_CALL(transformable, SetScale(scale.x, scale.y));
}


////////////////////////////////////////////////////////////
void sfTransformable_SetOrigin(sfTransformable* transformable, sfVector2f origin)
{
    CSFML_CALL(transformable, SetOrigin(origin.x, origin.y));
}


////////////////////////////////////////////////////////////
sfVector2f sfTransformable_GetPosition(const sfTransformable* transformable)
{
    sfVector2f position = {0, 0};
    CSFML_CHECK_RETURN(transformable, position);

    sf::Vector2f sfmlPos = transformable->This.GetPosition();
    position.x = sfmlPos.x;
    position.y = sfmlPos.y;

    return position;
}


////////////////////////////////////////////////////////////
float sfTransformable_GetRotation(const sfTransformable* transformable)
{
    CSFML_CALL_RETURN(transformable, GetRotation(), 0.f);
}


////////////////////////////////////////////////////////////
sfVector2f sfTransformable_GetScale(const sfTransformable* transformable)
{
    sfVector2f scale = {0, 0};
    CSFML_CHECK_RETURN(transformable, scale);

    sf::Vector2f sfmlScale = transformable->This.GetScale();
    scale.x = sfmlScale.x;
    scale.y = sfmlScale.y;

    return scale;
}


////////////////////////////////////////////////////////////
sfVector2f sfTransformable_GetOrigin(const sfTransformable* transformable)
{
    sfVector2f origin = {0, 0};
    CSFML_CHECK_RETURN(transformable, origin);

    sf::Vector2f sfmlOrigin = transformable->This.GetOrigin();
    origin.x = sfmlOrigin.x;
    origin.y = sfmlOrigin.y;

    return origin;
}


////////////////////////////////////////////////////////////
void sfTransformable_Move(sfTransformable* transformable, sfVector2f offset)
{
    CSFML_CALL(transformable, Move(offset.x, offset.y));
}


////////////////////////////////////////////////////////////
void sfTransformable_Rotate(sfTransformable* transformable, float angle)
{
    CSFML_CALL(transformable, Rotate(angle));
}


////////////////////////////////////////////////////////////
void sfTransformable_Scale(sfTransformable* transformable, sfVector2f factors)
{
    CSFML_CALL(transformable, Scale(factors.x, factors.y));
}


////////////////////////////////////////////////////////////
const sfTransform* sfTransformable_GetTransform(const sfTransformable* transformable)
{
    CSFML_CHECK_RETURN(transformable, NULL);

    transformable->Transform.This = transformable->This.GetTransform();
    return &transformable->Transform;
}


////////////////////////////////////////////////////////////
const sfTransform* sfTransformable_GetInverseTransform(const sfTransformable* transformable)
{
    CSFML_CHECK_RETURN(transformable, NULL);

    transformable->InverseTransform.This = transformable->This.GetInverseTransform();
    return &transformable->InverseTransform;
}
