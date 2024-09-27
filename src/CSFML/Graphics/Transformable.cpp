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
#include <CSFML/Graphics/ConvertTransform.hpp>
#include <CSFML/Graphics/Transformable.h>
#include <CSFML/Graphics/TransformableStruct.hpp>
#include <CSFML/System/ConvertVector2.hpp>


////////////////////////////////////////////////////////////
sfTransformable* sfTransformable_create()
{
    return new sfTransformable;
}


////////////////////////////////////////////////////////////
sfTransformable* sfTransformable_copy(const sfTransformable* transformable)
{
    assert(transformable);
    return new sfTransformable(*transformable);
}


////////////////////////////////////////////////////////////
void sfTransformable_destroy(const sfTransformable* transformable)
{
    delete transformable;
}


////////////////////////////////////////////////////////////
void sfTransformable_setPosition(sfTransformable* transformable, sfVector2f position)
{
    assert(transformable);
    transformable->setPosition(convertVector2(position));
}


////////////////////////////////////////////////////////////
void sfTransformable_setRotation(sfTransformable* transformable, float angle)
{
    assert(transformable);
    transformable->setRotation(sf::degrees(angle));
}


////////////////////////////////////////////////////////////
void sfTransformable_setScale(sfTransformable* transformable, sfVector2f scale)
{
    assert(transformable);
    transformable->setScale(convertVector2(scale));
}


////////////////////////////////////////////////////////////
void sfTransformable_setOrigin(sfTransformable* transformable, sfVector2f origin)
{
    assert(transformable);
    transformable->setOrigin(convertVector2(origin));
}


////////////////////////////////////////////////////////////
sfVector2f sfTransformable_getPosition(const sfTransformable* transformable)
{
    assert(transformable);
    return convertVector2(transformable->getPosition());
}


////////////////////////////////////////////////////////////
float sfTransformable_getRotation(const sfTransformable* transformable)
{
    assert(transformable);
    return transformable->getRotation().asDegrees();
}


////////////////////////////////////////////////////////////
sfVector2f sfTransformable_getScale(const sfTransformable* transformable)
{
    assert(transformable);
    return convertVector2(transformable->getScale());
}


////////////////////////////////////////////////////////////
sfVector2f sfTransformable_getOrigin(const sfTransformable* transformable)
{
    assert(transformable);
    return convertVector2(transformable->getOrigin());
}


////////////////////////////////////////////////////////////
void sfTransformable_move(sfTransformable* transformable, sfVector2f offset)
{
    assert(transformable);
    transformable->move(convertVector2(offset));
}


////////////////////////////////////////////////////////////
void sfTransformable_rotate(sfTransformable* transformable, float angle)
{
    assert(transformable);
    transformable->rotate(sf::degrees(angle));
}


////////////////////////////////////////////////////////////
void sfTransformable_scale(sfTransformable* transformable, sfVector2f factors)
{
    assert(transformable);
    transformable->scale(convertVector2(factors));
}


////////////////////////////////////////////////////////////
sfTransform sfTransformable_getTransform(const sfTransformable* transformable)
{
    assert(transformable);
    transformable->Transform = convertTransform(transformable->getTransform());
    return transformable->Transform;
}


////////////////////////////////////////////////////////////
sfTransform sfTransformable_getInverseTransform(const sfTransformable* transformable)
{
    assert(transformable);
    transformable->InverseTransform = convertTransform(transformable->getInverseTransform());
    return transformable->InverseTransform;
}
