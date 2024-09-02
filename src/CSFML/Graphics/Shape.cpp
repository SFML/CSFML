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
#include <CSFML/Graphics/Shape.h>
#include <CSFML/Graphics/ShapeStruct.hpp>
#include <CSFML/System/ConvertVector2.hpp>

#include <SFML/Graphics/Color.hpp>


////////////////////////////////////////////////////////////
sfShape* sfShape_create(sfShapeGetPointCountCallback getPointCount, sfShapeGetPointCallback getPoint, void* userData)
{
    return new sfShape(getPointCount, getPoint, userData);
}


////////////////////////////////////////////////////////////
void sfShape_destroy(sfShape* shape)
{
    delete shape;
}


////////////////////////////////////////////////////////////
void sfShape_setPosition(sfShape* shape, sfVector2f position)
{
    assert(shape);
    shape->This.setPosition(convertVector2(position));
}


////////////////////////////////////////////////////////////
void sfShape_setRotation(sfShape* shape, float angle)
{
    assert(shape);
    shape->This.setRotation(sf::degrees(angle));
}


////////////////////////////////////////////////////////////
void sfShape_setScale(sfShape* shape, sfVector2f scale)
{
    assert(shape);
    shape->This.setScale(convertVector2(scale));
}


////////////////////////////////////////////////////////////
void sfShape_setOrigin(sfShape* shape, sfVector2f origin)
{
    assert(shape);
    shape->This.setOrigin(convertVector2(origin));
}


////////////////////////////////////////////////////////////
sfVector2f sfShape_getPosition(const sfShape* shape)
{
    assert(shape);
    return convertVector2(shape->This.getPosition());
}


////////////////////////////////////////////////////////////
float sfShape_getRotation(const sfShape* shape)
{
    assert(shape);
    return shape->This.getRotation().asDegrees();
}


////////////////////////////////////////////////////////////
sfVector2f sfShape_getScale(const sfShape* shape)
{
    assert(shape);
    return convertVector2(shape->This.getScale());
}


////////////////////////////////////////////////////////////
sfVector2f sfShape_getOrigin(const sfShape* shape)
{
    assert(shape);
    return convertVector2(shape->This.getOrigin());
}


////////////////////////////////////////////////////////////
void sfShape_move(sfShape* shape, sfVector2f offset)
{
    assert(shape);
    shape->This.move(convertVector2(offset));
}


////////////////////////////////////////////////////////////
void sfShape_rotate(sfShape* shape, float angle)
{
    assert(shape);
    shape->This.rotate(sf::degrees(angle));
}


////////////////////////////////////////////////////////////
void sfShape_scale(sfShape* shape, sfVector2f factors)
{
    assert(shape);
    shape->This.scale(convertVector2(factors));
}


////////////////////////////////////////////////////////////
sfTransform sfShape_getTransform(const sfShape* shape)
{
    assert(shape);
    shape->Transform = convertTransform(shape->This.getTransform());
    return shape->Transform;
}


////////////////////////////////////////////////////////////
sfTransform sfShape_getInverseTransform(const sfShape* shape)
{
    assert(shape);
    shape->InverseTransform = convertTransform(shape->This.getInverseTransform());
    return shape->InverseTransform;
}


////////////////////////////////////////////////////////////
void sfShape_setTexture(sfShape* shape, const sfTexture* texture, bool resetRect)
{
    assert(shape);
    shape->This.setTexture(texture ? texture->This : nullptr, resetRect);
    shape->Texture = texture;
}


////////////////////////////////////////////////////////////
void sfShape_setTextureRect(sfShape* shape, sfIntRect rect)
{
    assert(shape);
    shape->This.setTextureRect(convertRect(rect));
}


////////////////////////////////////////////////////////////
void sfShape_setFillColor(sfShape* shape, sfColor color)
{
    assert(shape);
    shape->This.setFillColor(convertColor(color));
}


////////////////////////////////////////////////////////////
void sfShape_setOutlineColor(sfShape* shape, sfColor color)
{
    assert(shape);
    shape->This.setOutlineColor(convertColor(color));
}


////////////////////////////////////////////////////////////
void sfShape_setOutlineThickness(sfShape* shape, float thickness)
{
    assert(shape);
    shape->This.setOutlineThickness(thickness);
}


////////////////////////////////////////////////////////////
const sfTexture* sfShape_getTexture(const sfShape* shape)
{
    assert(shape);
    return shape->Texture;
}


////////////////////////////////////////////////////////////
sfIntRect sfShape_getTextureRect(const sfShape* shape)
{
    assert(shape);
    return convertRect(shape->This.getTextureRect());
}


////////////////////////////////////////////////////////////
sfColor sfShape_getFillColor(const sfShape* shape)
{
    assert(shape);
    return convertColor(shape->This.getFillColor());
}


////////////////////////////////////////////////////////////
sfColor sfShape_getOutlineColor(const sfShape* shape)
{
    assert(shape);
    return convertColor(shape->This.getOutlineColor());
}


////////////////////////////////////////////////////////////
float sfShape_getOutlineThickness(const sfShape* shape)
{
    assert(shape);
    return shape->This.getOutlineThickness();
}


////////////////////////////////////////////////////////////
size_t sfShape_getPointCount(const sfShape* shape)
{
    assert(shape);
    return shape->This.getPointCount();
}


////////////////////////////////////////////////////////////
sfVector2f sfShape_getPoint(const sfShape* shape, size_t index)
{
    assert(shape);
    return convertVector2(shape->This.getPoint(index));
}


////////////////////////////////////////////////////////////
sfFloatRect sfShape_getLocalBounds(const sfShape* shape)
{
    assert(shape);
    return convertRect(shape->This.getLocalBounds());
}


////////////////////////////////////////////////////////////
sfFloatRect sfShape_getGlobalBounds(const sfShape* shape)
{
    assert(shape);
    return convertRect(shape->This.getGlobalBounds());
}


////////////////////////////////////////////////////////////
void sfShape_update(sfShape* shape)
{
    assert(shape);
    shape->This.update();
}
