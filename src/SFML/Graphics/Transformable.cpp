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
void sfTransformable_SetPosition(sfTransformable* transformable, float x, float y)
{
    CSFML_CALL(transformable, SetPosition(x, y));
}


////////////////////////////////////////////////////////////
void sfTransformable_SetRotation(sfTransformable* transformable, float angle)
{
    CSFML_CALL(transformable, SetRotation(angle));
}


////////////////////////////////////////////////////////////
void sfTransformable_SetScale(sfTransformable* transformable, float factorX, float factorY)
{
    CSFML_CALL(transformable, SetScale(factorX, factorY));
}


////////////////////////////////////////////////////////////
void sfTransformable_SetOrigin(sfTransformable* transformable, float x, float y)
{
    CSFML_CALL(transformable, SetOrigin(x, y));
}


////////////////////////////////////////////////////////////
void sfTransformable_GetPosition(const sfTransformable* transformable, float* x, float* y)
{
    CSFML_CHECK(transformable);

    sf::Vector2f point = transformable->This.GetPosition();

    if (x)
        *x = point.x;
    if (y)
        *y = point.y;
}


////////////////////////////////////////////////////////////
float sfTransformable_GetRotation(const sfTransformable* transformable)
{
    CSFML_CALL_RETURN(transformable, GetRotation(), 0.f);
}


////////////////////////////////////////////////////////////
void sfTransformable_GetScale(const sfTransformable* transformable, float* x, float* y)
{
    CSFML_CHECK(transformable);

    sf::Vector2f point = transformable->This.GetScale();

    if (x)
        *x = point.x;
    if (y)
        *y = point.y;
}


////////////////////////////////////////////////////////////
void sfTransformable_GetOrigin(const sfTransformable* transformable, float* x, float* y)
{
    CSFML_CHECK(transformable);

    sf::Vector2f point = transformable->This.GetOrigin();

    if (x)
        *x = point.x;
    if (y)
        *y = point.y;
}


////////////////////////////////////////////////////////////
void sfTransformable_Move(sfTransformable* transformable, float offsetX, float offsetY)
{
    CSFML_CALL(transformable, Move(offsetX, offsetY));
}


////////////////////////////////////////////////////////////
void sfTransformable_Rotate(sfTransformable* transformable, float angle)
{
    CSFML_CALL(transformable, Rotate(angle));
}


////////////////////////////////////////////////////////////
void sfTransformable_Scale(sfTransformable* transformable, float factorX, float factorY)
{
    CSFML_CALL(transformable, Scale(factorX, factorY));
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
