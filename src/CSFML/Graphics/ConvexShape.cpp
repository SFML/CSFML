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
#include <CSFML/Graphics/ConvexShape.h>
#include <CSFML/Graphics/ConvexShapeStruct.hpp>
#include <SFML/Graphics/Color.hpp>
#include <CSFML/Graphics/ConvertTransform.hpp>
#include <CSFML/Graphics/ConvertColor.hpp>
#include <CSFML/Graphics/ConvertRect.hpp>
#include <CSFML/System/ConvertVector2.hpp>
#include <CSFML/Internal.hpp>


////////////////////////////////////////////////////////////
sfConvexShape* sfConvexShape_create()
{
    return new sfConvexShape;
}


////////////////////////////////////////////////////////////
sfConvexShape* sfConvexShape_copy(const sfConvexShape* shape)
{
    CSFML_CHECK_RETURN(shape, nullptr);

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
    CSFML_CALL(shape, setPosition(convertVector2(position)));
}


////////////////////////////////////////////////////////////
void sfConvexShape_setRotation(sfConvexShape* shape, float angle)
{
    CSFML_CALL(shape, setRotation(sf::degrees(angle)));
}


////////////////////////////////////////////////////////////
void sfConvexShape_setScale(sfConvexShape* shape, sfVector2f scale)
{
    CSFML_CALL(shape, setScale(convertVector2(scale)));
}


////////////////////////////////////////////////////////////
void sfConvexShape_setOrigin(sfConvexShape* shape, sfVector2f origin)
{
    CSFML_CALL(shape, setOrigin(convertVector2(origin)));
}


////////////////////////////////////////////////////////////
sfVector2f sfConvexShape_getPosition(const sfConvexShape* shape)
{
    CSFML_CHECK_RETURN(shape, {});

    return convertVector2(shape->This.getPosition());
}


////////////////////////////////////////////////////////////
float sfConvexShape_getRotation(const sfConvexShape* shape)
{
    CSFML_CALL_RETURN(shape, getRotation().asDegrees(), 0.f);
}


////////////////////////////////////////////////////////////
sfVector2f sfConvexShape_getScale(const sfConvexShape* shape)
{
    CSFML_CHECK_RETURN(shape, {});

    return convertVector2(shape->This.getScale());
}


////////////////////////////////////////////////////////////
sfVector2f sfConvexShape_getOrigin(const sfConvexShape* shape)
{
    CSFML_CHECK_RETURN(shape, {});

    return convertVector2(shape->This.getOrigin());
}


////////////////////////////////////////////////////////////
void sfConvexShape_move(sfConvexShape* shape, sfVector2f offset)
{
    CSFML_CALL(shape, move(convertVector2(offset)));
}


////////////////////////////////////////////////////////////
void sfConvexShape_rotate(sfConvexShape* shape, float angle)
{
    CSFML_CALL(shape, rotate(sf::degrees(angle)));
}


////////////////////////////////////////////////////////////
void sfConvexShape_scale(sfConvexShape* shape, sfVector2f factors)
{
    CSFML_CALL(shape, scale(convertVector2(factors)));
}


////////////////////////////////////////////////////////////
sfTransform sfConvexShape_getTransform(const sfConvexShape* shape)
{
    CSFML_CHECK_RETURN(shape, sfTransform_Identity);

    shape->Transform = convertTransform(shape->This.getTransform());
    return shape->Transform;
}


////////////////////////////////////////////////////////////
sfTransform sfConvexShape_getInverseTransform(const sfConvexShape* shape)
{
    CSFML_CHECK_RETURN(shape, sfTransform_Identity);

    shape->InverseTransform = convertTransform(shape->This.getInverseTransform());
    return shape->InverseTransform;
}


////////////////////////////////////////////////////////////
void sfConvexShape_setTexture(sfConvexShape* shape, const sfTexture* texture, bool resetRect)
{
    CSFML_CALL(shape, setTexture(texture ? texture->This : nullptr, resetRect));
    shape->Texture = texture;
}


////////////////////////////////////////////////////////////
void sfConvexShape_setTextureRect(sfConvexShape* shape, sfIntRect rect)
{
    CSFML_CALL(shape, setTextureRect(convertRect(rect)));
}


////////////////////////////////////////////////////////////
void sfConvexShape_setFillColor(sfConvexShape* shape, sfColor color)
{
    CSFML_CALL(shape, setFillColor(convertColor(color)));
}


////////////////////////////////////////////////////////////
void sfConvexShape_setOutlineColor(sfConvexShape* shape, sfColor color)
{
    CSFML_CALL(shape, setOutlineColor(convertColor(color)));
}


////////////////////////////////////////////////////////////
void sfConvexShape_setOutlineThickness(sfConvexShape* shape, float thickness)
{
    CSFML_CALL(shape, setOutlineThickness(thickness));
}


////////////////////////////////////////////////////////////
const sfTexture* sfConvexShape_getTexture(const sfConvexShape* shape)
{
    CSFML_CHECK_RETURN(shape, nullptr);

    return shape->Texture;
}


////////////////////////////////////////////////////////////
sfIntRect sfConvexShape_getTextureRect(const sfConvexShape* shape)
{
    CSFML_CHECK_RETURN(shape, {});

    return convertRect(shape->This.getTextureRect());
}


////////////////////////////////////////////////////////////
sfColor sfConvexShape_getFillColor(const sfConvexShape* shape)
{
    CSFML_CHECK_RETURN(shape, {});

    return convertColor(shape->This.getFillColor());
}


////////////////////////////////////////////////////////////
sfColor sfConvexShape_getOutlineColor(const sfConvexShape* shape)
{
    CSFML_CHECK_RETURN(shape, {});

    return convertColor(shape->This.getOutlineColor());
}


////////////////////////////////////////////////////////////
float sfConvexShape_getOutlineThickness(const sfConvexShape* shape)
{
    CSFML_CALL_RETURN(shape, getOutlineThickness(), 0.f);
}


////////////////////////////////////////////////////////////
size_t sfConvexShape_getPointCount(const sfConvexShape* shape)
{
    CSFML_CALL_RETURN(shape, getPointCount(), 0);
}


////////////////////////////////////////////////////////////
sfVector2f sfConvexShape_getPoint(const sfConvexShape* shape, size_t index)
{
    CSFML_CHECK_RETURN(shape, {});

    return convertVector2(shape->This.getPoint(index));
}


////////////////////////////////////////////////////////////
void sfConvexShape_setPointCount(sfConvexShape* shape, size_t count)
{
    CSFML_CALL(shape, setPointCount(count));
}


////////////////////////////////////////////////////////////
void sfConvexShape_setPoint(sfConvexShape* shape, size_t index, sfVector2f point)
{
    CSFML_CALL(shape, setPoint(index, convertVector2(point)));
}


////////////////////////////////////////////////////////////
sfFloatRect sfConvexShape_getLocalBounds(const sfConvexShape* shape)
{
    CSFML_CHECK_RETURN(shape, {});

    return convertRect(shape->This.getLocalBounds());
}


////////////////////////////////////////////////////////////
sfFloatRect sfConvexShape_getGlobalBounds(const sfConvexShape* shape)
{
    CSFML_CHECK_RETURN(shape, {});

    return convertRect(shape->This.getGlobalBounds());
}
