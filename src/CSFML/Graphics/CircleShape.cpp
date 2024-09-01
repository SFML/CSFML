////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2023 Laurent Gomila (laurent@sfml-dev.org)
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
#include <CSFML/Graphics/CircleShape.h>
#include <CSFML/Graphics/CircleShapeStruct.hpp>
#include <CSFML/Graphics/ConvertColor.hpp>
#include <CSFML/Graphics/ConvertRect.hpp>
#include <CSFML/Graphics/ConvertTransform.hpp>
#include <CSFML/System/ConvertVector2.hpp>

#include <SFML/Graphics/Color.hpp>


////////////////////////////////////////////////////////////
sfCircleShape* sfCircleShape_create()
{
    auto* shape    = new sfCircleShape;
    shape->Texture = nullptr;

    return shape;
}


////////////////////////////////////////////////////////////
sfCircleShape* sfCircleShape_copy(const sfCircleShape* shape)
{
    assert(shape);
    return new sfCircleShape(*shape);
}


////////////////////////////////////////////////////////////
void sfCircleShape_destroy(sfCircleShape* shape)
{
    delete shape;
}


////////////////////////////////////////////////////////////
void sfCircleShape_setPosition(sfCircleShape* shape, sfVector2f position)
{
    assert(shape);
    shape->This.setPosition(convertVector2(position));
}


////////////////////////////////////////////////////////////
void sfCircleShape_setRotation(sfCircleShape* shape, float angle)
{
    assert(shape);
    shape->This.setRotation(sf::degrees(angle));
}


////////////////////////////////////////////////////////////
void sfCircleShape_setScale(sfCircleShape* shape, sfVector2f scale)
{
    assert(shape);
    shape->This.setScale(convertVector2(scale));
}


////////////////////////////////////////////////////////////
void sfCircleShape_setOrigin(sfCircleShape* shape, sfVector2f origin)
{
    assert(shape);
    shape->This.setOrigin(convertVector2(origin));
}


////////////////////////////////////////////////////////////
sfVector2f sfCircleShape_getPosition(const sfCircleShape* shape)
{
    assert(shape);
    return convertVector2(shape->This.getPosition());
}


////////////////////////////////////////////////////////////
float sfCircleShape_getRotation(const sfCircleShape* shape)
{
    assert(shape);
    return shape->This.getRotation().asDegrees();
}


////////////////////////////////////////////////////////////
sfVector2f sfCircleShape_getScale(const sfCircleShape* shape)
{
    assert(shape);
    return convertVector2(shape->This.getScale());
}


////////////////////////////////////////////////////////////
sfVector2f sfCircleShape_getOrigin(const sfCircleShape* shape)
{
    assert(shape);
    return convertVector2(shape->This.getOrigin());
}


////////////////////////////////////////////////////////////
void sfCircleShape_move(sfCircleShape* shape, sfVector2f offset)
{
    assert(shape);
    shape->This.move(convertVector2(offset));
}


////////////////////////////////////////////////////////////
void sfCircleShape_rotate(sfCircleShape* shape, float angle)
{
    assert(shape);
    shape->This.rotate(sf::degrees(angle));
}


////////////////////////////////////////////////////////////
void sfCircleShape_scale(sfCircleShape* shape, sfVector2f factors)
{
    assert(shape);
    shape->This.scale(convertVector2(factors));
}


////////////////////////////////////////////////////////////
sfTransform sfCircleShape_getTransform(const sfCircleShape* shape)
{
    assert(shape);
    shape->Transform = convertTransform(shape->This.getTransform());
    return shape->Transform;
}


////////////////////////////////////////////////////////////
sfTransform sfCircleShape_getInverseTransform(const sfCircleShape* shape)
{
    assert(shape);
    shape->InverseTransform = convertTransform(shape->This.getInverseTransform());
    return shape->InverseTransform;
}


////////////////////////////////////////////////////////////
void sfCircleShape_setTexture(sfCircleShape* shape, const sfTexture* texture, bool resetRect)
{
    assert(shape);
    shape->This.setTexture(texture ? texture->This : nullptr, resetRect);
    shape->Texture = texture;
}


////////////////////////////////////////////////////////////
void sfCircleShape_setTextureRect(sfCircleShape* shape, sfIntRect rect)
{
    assert(shape);
    shape->This.setTextureRect(convertRect(rect));
}


////////////////////////////////////////////////////////////
void sfCircleShape_setFillColor(sfCircleShape* shape, sfColor color)
{
    assert(shape);
    shape->This.setFillColor(convertColor(color));
}


////////////////////////////////////////////////////////////
void sfCircleShape_setOutlineColor(sfCircleShape* shape, sfColor color)
{
    assert(shape);
    shape->This.setOutlineColor(convertColor(color));
}


////////////////////////////////////////////////////////////
void sfCircleShape_setOutlineThickness(sfCircleShape* shape, float thickness)
{
    assert(shape);
    shape->This.setOutlineThickness(thickness);
}


////////////////////////////////////////////////////////////
const sfTexture* sfCircleShape_getTexture(const sfCircleShape* shape)
{
    assert(shape);
    return shape->Texture;
}


////////////////////////////////////////////////////////////
sfIntRect sfCircleShape_getTextureRect(const sfCircleShape* shape)
{
    assert(shape);
    return convertRect(shape->This.getTextureRect());
}


////////////////////////////////////////////////////////////
sfColor sfCircleShape_getFillColor(const sfCircleShape* shape)
{
    assert(shape);
    return convertColor(shape->This.getFillColor());
}


////////////////////////////////////////////////////////////
sfColor sfCircleShape_getOutlineColor(const sfCircleShape* shape)
{
    assert(shape);
    return convertColor(shape->This.getOutlineColor());
}


////////////////////////////////////////////////////////////
float sfCircleShape_getOutlineThickness(const sfCircleShape* shape)
{
    assert(shape);
    return shape->This.getOutlineThickness();
}


////////////////////////////////////////////////////////////
size_t sfCircleShape_getPointCount(const sfCircleShape* shape)
{
    assert(shape);
    return shape->This.getPointCount();
}


////////////////////////////////////////////////////////////
sfVector2f sfCircleShape_getPoint(const sfCircleShape* shape, size_t index)
{
    assert(shape);
    return convertVector2(shape->This.getPoint(index));
}


////////////////////////////////////////////////////////////
void sfCircleShape_setRadius(sfCircleShape* shape, float radius)
{
    assert(shape);
    shape->This.setRadius(radius);
}


////////////////////////////////////////////////////////////
float sfCircleShape_getRadius(const sfCircleShape* shape)
{
    assert(shape);
    return shape->This.getRadius();
}


////////////////////////////////////////////////////////////
void sfCircleShape_setPointCount(sfCircleShape* shape, size_t count)
{
    assert(shape);
    shape->This.setPointCount(count);
}


////////////////////////////////////////////////////////////
sfFloatRect sfCircleShape_getLocalBounds(const sfCircleShape* shape)
{
    assert(shape);
    return convertRect(shape->This.getLocalBounds());
}


////////////////////////////////////////////////////////////
sfFloatRect sfCircleShape_getGlobalBounds(const sfCircleShape* shape)
{
    assert(shape);
    return convertRect(shape->This.getGlobalBounds());
}
