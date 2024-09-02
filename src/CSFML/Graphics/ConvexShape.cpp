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
#include <CSFML/Graphics/ConvertColor.hpp>
#include <CSFML/Graphics/ConvertRect.hpp>
#include <CSFML/Graphics/ConvertTransform.hpp>
#include <CSFML/Graphics/ConvexShape.h>
#include <CSFML/Graphics/ConvexShapeStruct.hpp>
#include <CSFML/System/ConvertVector2.hpp>

#include <SFML/Graphics/Color.hpp>


////////////////////////////////////////////////////////////
sfConvexShape* sfConvexShape_create()
{
    return new sfConvexShape;
}


////////////////////////////////////////////////////////////
sfConvexShape* sfConvexShape_copy(const sfConvexShape* shape)
{
    assert(shape);
    return new sfConvexShape(*shape);
}


////////////////////////////////////////////////////////////
void sfConvexShape_destroy(sfConvexShape* shape)
{
    delete shape;
}


////////////////////////////////////////////////////////////
void sfConvexShape_setPosition(sfConvexShape* shape, sfVector2f position)
{
    assert(shape);
    shape->This.setPosition(convertVector2(position));
}


////////////////////////////////////////////////////////////
void sfConvexShape_setRotation(sfConvexShape* shape, float angle)
{
    assert(shape);
    shape->This.setRotation(sf::degrees(angle));
}


////////////////////////////////////////////////////////////
void sfConvexShape_setScale(sfConvexShape* shape, sfVector2f scale)
{
    assert(shape);
    shape->This.setScale(convertVector2(scale));
}


////////////////////////////////////////////////////////////
void sfConvexShape_setOrigin(sfConvexShape* shape, sfVector2f origin)
{
    assert(shape);
    shape->This.setOrigin(convertVector2(origin));
}


////////////////////////////////////////////////////////////
sfVector2f sfConvexShape_getPosition(const sfConvexShape* shape)
{
    assert(shape);
    return convertVector2(shape->This.getPosition());
}


////////////////////////////////////////////////////////////
float sfConvexShape_getRotation(const sfConvexShape* shape)
{
    assert(shape);
    return shape->This.getRotation().asDegrees();
}


////////////////////////////////////////////////////////////
sfVector2f sfConvexShape_getScale(const sfConvexShape* shape)
{
    assert(shape);
    return convertVector2(shape->This.getScale());
}


////////////////////////////////////////////////////////////
sfVector2f sfConvexShape_getOrigin(const sfConvexShape* shape)
{
    assert(shape);
    return convertVector2(shape->This.getOrigin());
}


////////////////////////////////////////////////////////////
void sfConvexShape_move(sfConvexShape* shape, sfVector2f offset)
{
    assert(shape);
    shape->This.move(convertVector2(offset));
}


////////////////////////////////////////////////////////////
void sfConvexShape_rotate(sfConvexShape* shape, float angle)
{
    assert(shape);
    shape->This.rotate(sf::degrees(angle));
}


////////////////////////////////////////////////////////////
void sfConvexShape_scale(sfConvexShape* shape, sfVector2f factors)
{
    assert(shape);
    shape->This.scale(convertVector2(factors));
}


////////////////////////////////////////////////////////////
sfTransform sfConvexShape_getTransform(const sfConvexShape* shape)
{
    assert(shape);
    shape->Transform = convertTransform(shape->This.getTransform());
    return shape->Transform;
}


////////////////////////////////////////////////////////////
sfTransform sfConvexShape_getInverseTransform(const sfConvexShape* shape)
{
    assert(shape);
    shape->InverseTransform = convertTransform(shape->This.getInverseTransform());
    return shape->InverseTransform;
}


////////////////////////////////////////////////////////////
void sfConvexShape_setTexture(sfConvexShape* shape, const sfTexture* texture, bool resetRect)
{
    assert(shape);
    shape->This.setTexture(texture ? texture->This : nullptr, resetRect);
    shape->Texture = texture;
}


////////////////////////////////////////////////////////////
void sfConvexShape_setTextureRect(sfConvexShape* shape, sfIntRect rect)
{
    assert(shape);
    shape->This.setTextureRect(convertRect(rect));
}


////////////////////////////////////////////////////////////
void sfConvexShape_setFillColor(sfConvexShape* shape, sfColor color)
{
    assert(shape);
    shape->This.setFillColor(convertColor(color));
}


////////////////////////////////////////////////////////////
void sfConvexShape_setOutlineColor(sfConvexShape* shape, sfColor color)
{
    assert(shape);
    shape->This.setOutlineColor(convertColor(color));
}


////////////////////////////////////////////////////////////
void sfConvexShape_setOutlineThickness(sfConvexShape* shape, float thickness)
{
    assert(shape);
    shape->This.setOutlineThickness(thickness);
}


////////////////////////////////////////////////////////////
const sfTexture* sfConvexShape_getTexture(const sfConvexShape* shape)
{
    assert(shape);
    return shape->Texture;
}


////////////////////////////////////////////////////////////
sfIntRect sfConvexShape_getTextureRect(const sfConvexShape* shape)
{
    assert(shape);
    return convertRect(shape->This.getTextureRect());
}


////////////////////////////////////////////////////////////
sfColor sfConvexShape_getFillColor(const sfConvexShape* shape)
{
    assert(shape);
    return convertColor(shape->This.getFillColor());
}


////////////////////////////////////////////////////////////
sfColor sfConvexShape_getOutlineColor(const sfConvexShape* shape)
{
    assert(shape);
    return convertColor(shape->This.getOutlineColor());
}


////////////////////////////////////////////////////////////
float sfConvexShape_getOutlineThickness(const sfConvexShape* shape)
{
    assert(shape);
    return shape->This.getOutlineThickness();
}


////////////////////////////////////////////////////////////
size_t sfConvexShape_getPointCount(const sfConvexShape* shape)
{
    assert(shape);
    return shape->This.getPointCount();
}


////////////////////////////////////////////////////////////
sfVector2f sfConvexShape_getPoint(const sfConvexShape* shape, size_t index)
{
    assert(shape);
    return convertVector2(shape->This.getPoint(index));
}


////////////////////////////////////////////////////////////
void sfConvexShape_setPointCount(sfConvexShape* shape, size_t count)
{
    assert(shape);
    shape->This.setPointCount(count);
}


////////////////////////////////////////////////////////////
void sfConvexShape_setPoint(sfConvexShape* shape, size_t index, sfVector2f point)
{
    assert(shape);
    shape->This.setPoint(index, convertVector2(point));
}


////////////////////////////////////////////////////////////
sfFloatRect sfConvexShape_getLocalBounds(const sfConvexShape* shape)
{
    assert(shape);
    return convertRect(shape->This.getLocalBounds());
}


////////////////////////////////////////////////////////////
sfFloatRect sfConvexShape_getGlobalBounds(const sfConvexShape* shape)
{
    assert(shape);
    return convertRect(shape->This.getGlobalBounds());
}
