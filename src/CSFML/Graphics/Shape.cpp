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
#include <CSFML/Graphics/Shape.h>
#include <CSFML/Graphics/ShapeStruct.hpp>
#include <SFML/Graphics/Color.hpp>
#include <CSFML/Graphics/ConvertTransform.hpp>
#include <CSFML/Graphics/ConvertColor.hpp>
#include <CSFML/Graphics/ConvertRect.hpp>
#include <CSFML/System/ConvertVector2.hpp>
#include <CSFML/Internal.hpp>


////////////////////////////////////////////////////////////
sfShape* sfShape_create(sfShapeGetPointCountCallback getPointCount,
                        sfShapeGetPointCallback getPoint,
                        void* userData)
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
    CSFML_CALL(shape, setPosition(convertVector2(position)));
}


////////////////////////////////////////////////////////////
void sfShape_setRotation(sfShape* shape, float angle)
{
    CSFML_CALL(shape, setRotation(sf::degrees(angle)));
}


////////////////////////////////////////////////////////////
void sfShape_setScale(sfShape* shape, sfVector2f scale)
{
    CSFML_CALL(shape, setScale(convertVector2(scale)));
}


////////////////////////////////////////////////////////////
void sfShape_setOrigin(sfShape* shape, sfVector2f origin)
{
    CSFML_CALL(shape, setOrigin(convertVector2(origin)));
}


////////////////////////////////////////////////////////////
sfVector2f sfShape_getPosition(const sfShape* shape)
{
    sfVector2f position = {0, 0};
    CSFML_CHECK_RETURN(shape, position);

    return convertVector2(shape->This.getPosition());
}


////////////////////////////////////////////////////////////
float sfShape_getRotation(const sfShape* shape)
{
    CSFML_CALL_RETURN(shape, getRotation().asDegrees(), 0.f);
}


////////////////////////////////////////////////////////////
sfVector2f sfShape_getScale(const sfShape* shape)
{
    sfVector2f scale = {0, 0};
    CSFML_CHECK_RETURN(shape, scale);

    return convertVector2(shape->This.getScale());
}


////////////////////////////////////////////////////////////
sfVector2f sfShape_getOrigin(const sfShape* shape)
{
    sfVector2f origin = {0, 0};
    CSFML_CHECK_RETURN(shape, origin);

    return convertVector2(shape->This.getOrigin());
}


////////////////////////////////////////////////////////////
void sfShape_move(sfShape* shape, sfVector2f offset)
{
    CSFML_CALL(shape, move(convertVector2(offset)));
}


////////////////////////////////////////////////////////////
void sfShape_rotate(sfShape* shape, float angle)
{
    CSFML_CALL(shape, rotate(sf::degrees(angle)));
}


////////////////////////////////////////////////////////////
void sfShape_scale(sfShape* shape, sfVector2f factors)
{
    CSFML_CALL(shape, scale(convertVector2(factors)));
}


////////////////////////////////////////////////////////////
sfTransform sfShape_getTransform(const sfShape* shape)
{
    CSFML_CHECK_RETURN(shape, sfTransform_Identity);

    shape->Transform = convertTransform(shape->This.getTransform());
    return shape->Transform;
}


////////////////////////////////////////////////////////////
sfTransform sfShape_getInverseTransform(const sfShape* shape)
{
    CSFML_CHECK_RETURN(shape, sfTransform_Identity);

    shape->InverseTransform = convertTransform(shape->This.getInverseTransform());
    return shape->InverseTransform;
}


////////////////////////////////////////////////////////////
void sfShape_setTexture(sfShape* shape, const sfTexture* texture, bool resetRect)
{
    CSFML_CALL(shape, setTexture(texture ? texture->This : nullptr, resetRect));
    shape->Texture = texture;
}


////////////////////////////////////////////////////////////
void sfShape_setTextureRect(sfShape* shape, sfIntRect rect)
{
    CSFML_CALL(shape, setTextureRect(convertRect(rect)));
}


////////////////////////////////////////////////////////////
void sfShape_setFillColor(sfShape* shape, sfColor color)
{
    CSFML_CALL(shape, setFillColor(convertColor(color)));
}


////////////////////////////////////////////////////////////
void sfShape_setOutlineColor(sfShape* shape, sfColor color)
{
    CSFML_CALL(shape, setOutlineColor(convertColor(color)));
}


////////////////////////////////////////////////////////////
void sfShape_setOutlineThickness(sfShape* shape, float thickness)
{
    CSFML_CALL(shape, setOutlineThickness(thickness));
}


////////////////////////////////////////////////////////////
const sfTexture* sfShape_getTexture(const sfShape* shape)
{
    CSFML_CHECK_RETURN(shape, nullptr);

    return shape->Texture;
}


////////////////////////////////////////////////////////////
sfIntRect sfShape_getTextureRect(const sfShape* shape)
{
    sfIntRect rect = {{0, 0}, {0, 0}};
    CSFML_CHECK_RETURN(shape, rect);

    return convertRect(shape->This.getTextureRect());
}


////////////////////////////////////////////////////////////
sfColor sfShape_getFillColor(const sfShape* shape)
{
    sfColor color = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(shape, color);

    return convertColor(shape->This.getFillColor());
}


////////////////////////////////////////////////////////////
sfColor sfShape_getOutlineColor(const sfShape* shape)
{
    sfColor color = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(shape, color);

    return convertColor(shape->This.getOutlineColor());
}


////////////////////////////////////////////////////////////
float sfShape_getOutlineThickness(const sfShape* shape)
{
    CSFML_CALL_RETURN(shape, getOutlineThickness(), 0.f);
}


////////////////////////////////////////////////////////////
size_t sfShape_getPointCount(const sfShape* shape)
{
    CSFML_CALL_RETURN(shape, getPointCount(), 0);
}


////////////////////////////////////////////////////////////
sfVector2f sfShape_getPoint(const sfShape* shape, size_t index)
{
    sfVector2f point = {0, 0};
    CSFML_CHECK_RETURN(shape, point);

    return convertVector2(shape->This.getPoint(index));
}


////////////////////////////////////////////////////////////
sfFloatRect sfShape_getLocalBounds(const sfShape* shape)
{
    sfFloatRect rect = {{0, 0}, {0, 0}};
    CSFML_CHECK_RETURN(shape, rect);

    return convertRect(shape->This.getLocalBounds());
}


////////////////////////////////////////////////////////////
sfFloatRect sfShape_getGlobalBounds(const sfShape* shape)
{
    sfFloatRect rect = {{0, 0}, {0, 0}};
    CSFML_CHECK_RETURN(shape, rect);

    return convertRect(shape->This.getGlobalBounds());
}


////////////////////////////////////////////////////////////
void sfShape_update(sfShape* shape)
{
    CSFML_CALL(shape, update());
}
