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
#include <CSFML/Graphics/ConvertColor.hpp>
#include <CSFML/Graphics/ConvertRect.hpp>
#include <CSFML/Graphics/ConvertTransform.hpp>
#include <CSFML/Graphics/RectangleShape.h>
#include <CSFML/Graphics/RectangleShapeStruct.hpp>
#include <CSFML/System/ConvertVector2.hpp>

#include <SFML/Graphics/Color.hpp>


////////////////////////////////////////////////////////////
sfRectangleShape* sfRectangleShape_create()
{
    return new sfRectangleShape;
}


////////////////////////////////////////////////////////////
sfRectangleShape* sfRectangleShape_copy(const sfRectangleShape* shape)
{
    assert(shape);
    return new sfRectangleShape(*shape);
}


////////////////////////////////////////////////////////////
void sfRectangleShape_destroy(const sfRectangleShape* shape)
{
    delete shape;
}


////////////////////////////////////////////////////////////
void sfRectangleShape_setPosition(sfRectangleShape* shape, sfVector2f position)
{
    assert(shape);
    shape->setPosition(convertVector2(position));
}


////////////////////////////////////////////////////////////
void sfRectangleShape_setRotation(sfRectangleShape* shape, float angle)
{
    assert(shape);
    shape->setRotation(sf::degrees(angle));
}


////////////////////////////////////////////////////////////
void sfRectangleShape_setScale(sfRectangleShape* shape, sfVector2f scale)
{
    assert(shape);
    shape->setScale(convertVector2(scale));
}


////////////////////////////////////////////////////////////
void sfRectangleShape_setOrigin(sfRectangleShape* shape, sfVector2f origin)
{
    assert(shape);
    shape->setOrigin(convertVector2(origin));
}


////////////////////////////////////////////////////////////
sfVector2f sfRectangleShape_getPosition(const sfRectangleShape* shape)
{
    assert(shape);
    return convertVector2(shape->getPosition());
}


////////////////////////////////////////////////////////////
float sfRectangleShape_getRotation(const sfRectangleShape* shape)
{
    assert(shape);
    return shape->getRotation().asDegrees();
}


////////////////////////////////////////////////////////////
sfVector2f sfRectangleShape_getScale(const sfRectangleShape* shape)
{
    assert(shape);
    return convertVector2(shape->getScale());
}


////////////////////////////////////////////////////////////
sfVector2f sfRectangleShape_getOrigin(const sfRectangleShape* shape)
{
    assert(shape);
    return convertVector2(shape->getOrigin());
}


////////////////////////////////////////////////////////////
void sfRectangleShape_move(sfRectangleShape* shape, sfVector2f offset)
{
    assert(shape);
    shape->move(convertVector2(offset));
}


////////////////////////////////////////////////////////////
void sfRectangleShape_rotate(sfRectangleShape* shape, float angle)
{
    assert(shape);
    shape->rotate(sf::degrees(angle));
}


////////////////////////////////////////////////////////////
void sfRectangleShape_scale(sfRectangleShape* shape, sfVector2f factors)
{
    assert(shape);
    shape->scale(convertVector2(factors));
}


////////////////////////////////////////////////////////////
sfTransform sfRectangleShape_getTransform(const sfRectangleShape* shape)
{
    assert(shape);
    shape->Transform = convertTransform(shape->getTransform());
    return shape->Transform;
}


////////////////////////////////////////////////////////////
sfTransform sfRectangleShape_getInverseTransform(const sfRectangleShape* shape)
{
    assert(shape);
    shape->InverseTransform = convertTransform(shape->getInverseTransform());
    return shape->InverseTransform;
}


////////////////////////////////////////////////////////////
void sfRectangleShape_setTexture(sfRectangleShape* shape, const sfTexture* texture, bool resetRect)
{
    assert(shape);
    shape->setTexture(texture ? texture->This : nullptr, resetRect);
    shape->Texture = texture;
}


////////////////////////////////////////////////////////////
void sfRectangleShape_setTextureRect(sfRectangleShape* shape, sfIntRect rect)
{
    assert(shape);
    shape->setTextureRect(convertRect(rect));
}


////////////////////////////////////////////////////////////
void sfRectangleShape_setFillColor(sfRectangleShape* shape, sfColor color)
{
    assert(shape);
    shape->setFillColor(convertColor(color));
}


////////////////////////////////////////////////////////////
void sfRectangleShape_setOutlineColor(sfRectangleShape* shape, sfColor color)
{
    assert(shape);
    shape->setOutlineColor(convertColor(color));
}


////////////////////////////////////////////////////////////
void sfRectangleShape_setOutlineThickness(sfRectangleShape* shape, float thickness)
{
    assert(shape);
    shape->setOutlineThickness(thickness);
}


////////////////////////////////////////////////////////////
const sfTexture* sfRectangleShape_getTexture(const sfRectangleShape* shape)
{
    assert(shape);
    return shape->Texture;
}


////////////////////////////////////////////////////////////
sfIntRect sfRectangleShape_getTextureRect(const sfRectangleShape* shape)
{
    assert(shape);
    return convertRect(shape->getTextureRect());
}


////////////////////////////////////////////////////////////
sfColor sfRectangleShape_getFillColor(const sfRectangleShape* shape)
{
    assert(shape);
    return convertColor(shape->getFillColor());
}


////////////////////////////////////////////////////////////
sfColor sfRectangleShape_getOutlineColor(const sfRectangleShape* shape)
{
    assert(shape);
    return convertColor(shape->getOutlineColor());
}


////////////////////////////////////////////////////////////
float sfRectangleShape_getOutlineThickness(const sfRectangleShape* shape)
{
    assert(shape);
    return shape->getOutlineThickness();
}


////////////////////////////////////////////////////////////
size_t sfRectangleShape_getPointCount(const sfRectangleShape* shape)
{
    assert(shape);
    return shape->getPointCount();
}


////////////////////////////////////////////////////////////
sfVector2f sfRectangleShape_getPoint(const sfRectangleShape* shape, size_t index)
{
    assert(shape);
    return convertVector2(shape->getPoint(index));
}


////////////////////////////////////////////////////////////
sfVector2f sfRectangleShape_getGeometricCenter(const sfRectangleShape* shape)
{
    assert(shape);
    return convertVector2(shape->getGeometricCenter());
}


////////////////////////////////////////////////////////////
void sfRectangleShape_setSize(sfRectangleShape* shape, sfVector2f size)
{
    assert(shape);
    shape->setSize(convertVector2(size));
}


////////////////////////////////////////////////////////////
sfVector2f sfRectangleShape_getSize(const sfRectangleShape* shape)
{
    assert(shape);
    return convertVector2(shape->getSize());
}


////////////////////////////////////////////////////////////
sfFloatRect sfRectangleShape_getLocalBounds(const sfRectangleShape* shape)
{
    assert(shape);
    return convertRect(shape->getLocalBounds());
}


////////////////////////////////////////////////////////////
sfFloatRect sfRectangleShape_getGlobalBounds(const sfRectangleShape* shape)
{
    assert(shape);
    return convertRect(shape->getGlobalBounds());
}
