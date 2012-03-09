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
#include <SFML/Graphics/ConvexShape.h>
#include <SFML/Graphics/ConvexShapeStruct.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfConvexShape* sfConvexShape_Create(void)
{
    return new sfConvexShape;
}


////////////////////////////////////////////////////////////
sfConvexShape* sfConvexShape_Copy(sfConvexShape* shape)
{
    CSFML_CHECK_RETURN(shape, NULL);

    return new sfConvexShape(*shape);
}


////////////////////////////////////////////////////////////
void sfConvexShape_Destroy(sfConvexShape* shape)
{
    delete shape;
}


////////////////////////////////////////////////////////////
void sfConvexShape_SetPosition(sfConvexShape* shape, sfVector2f position)
{
    CSFML_CALL(shape, SetPosition(position.x, position.y));
}


////////////////////////////////////////////////////////////
void sfConvexShape_SetRotation(sfConvexShape* shape, float angle)
{
    CSFML_CALL(shape, SetRotation(angle));
}


////////////////////////////////////////////////////////////
void sfConvexShape_SetScale(sfConvexShape* shape, sfVector2f scale)
{
    CSFML_CALL(shape, SetScale(scale.x, scale.y));
}


////////////////////////////////////////////////////////////
void sfConvexShape_SetOrigin(sfConvexShape* shape, sfVector2f origin)
{
    CSFML_CALL(shape, SetOrigin(origin.x, origin.y));
}


////////////////////////////////////////////////////////////
sfVector2f sfConvexShape_GetPosition(const sfConvexShape* shape)
{
    sfVector2f position = {0, 0};
    CSFML_CHECK_RETURN(shape, position);

    sf::Vector2f sfmlPos = shape->This.GetPosition();
    position.x = sfmlPos.x;
    position.y = sfmlPos.y;

    return position;
}


////////////////////////////////////////////////////////////
float sfConvexShape_GetRotation(const sfConvexShape* shape)
{
    CSFML_CALL_RETURN(shape, GetRotation(), 0.f);
}


////////////////////////////////////////////////////////////
sfVector2f sfConvexShape_GetScale(const sfConvexShape* shape)
{
    sfVector2f scale = {0, 0};
    CSFML_CHECK_RETURN(shape, scale);

    sf::Vector2f sfmlScale = shape->This.GetScale();
    scale.x = sfmlScale.x;
    scale.y = sfmlScale.y;

    return scale;
}


////////////////////////////////////////////////////////////
sfVector2f sfConvexShape_GetOrigin(const sfConvexShape* shape)
{
    sfVector2f origin = {0, 0};
    CSFML_CHECK_RETURN(shape, origin);

    sf::Vector2f sfmlOrigin = shape->This.GetOrigin();
    origin.x = sfmlOrigin.x;
    origin.y = sfmlOrigin.y;

    return origin;
}


////////////////////////////////////////////////////////////
void sfConvexShape_Move(sfConvexShape* shape, sfVector2f offset)
{
    CSFML_CALL(shape, Move(offset.x, offset.y));
}


////////////////////////////////////////////////////////////
void sfConvexShape_Rotate(sfConvexShape* shape, float angle)
{
    CSFML_CALL(shape, Rotate(angle));
}


////////////////////////////////////////////////////////////
void sfConvexShape_Scale(sfConvexShape* shape, sfVector2f factors)
{
    CSFML_CALL(shape, Scale(factors.x, factors.y));
}


////////////////////////////////////////////////////////////
const sfTransform* sfConvexShape_GetTransform(const sfConvexShape* shape)
{
    CSFML_CHECK_RETURN(shape, NULL);

    shape->Transform.This = shape->This.GetTransform();
    return &shape->Transform;
}


////////////////////////////////////////////////////////////
const sfTransform* sfConvexShape_GetInverseTransform(const sfConvexShape* shape)
{
    CSFML_CHECK_RETURN(shape, NULL);

    shape->InverseTransform.This = shape->This.GetInverseTransform();
    return &shape->InverseTransform;
}


////////////////////////////////////////////////////////////
void sfConvexShape_SetTexture(sfConvexShape* shape, const sfTexture* texture, sfBool resetRect)
{
    CSFML_CALL(shape, SetTexture(texture ? texture->This : NULL, resetRect == sfTrue));
    shape->Texture = texture;
}


////////////////////////////////////////////////////////////
void sfConvexShape_SetTextureRect(sfConvexShape* shape, sfIntRect rect)
{
    CSFML_CALL(shape, SetTextureRect(sf::IntRect(rect.Left, rect.Top, rect.Width, rect.Height)));
}


////////////////////////////////////////////////////////////
void sfConvexShape_SetFillColor(sfConvexShape* shape, sfColor color)
{
    CSFML_CALL(shape, SetFillColor(sf::Color(color.r, color.g, color.b, color.a)));
}


////////////////////////////////////////////////////////////
void sfConvexShape_SetOutlineColor(sfConvexShape* shape, sfColor color)
{
    CSFML_CALL(shape, SetOutlineColor(sf::Color(color.r, color.g, color.b, color.a)));
}


////////////////////////////////////////////////////////////
void sfConvexShape_SetOutlineThickness(sfConvexShape* shape, float thickness)
{
    CSFML_CALL(shape, SetOutlineThickness(thickness));
}


////////////////////////////////////////////////////////////
const sfTexture* sfConvexShape_GetTexture(const sfConvexShape* shape)
{
    CSFML_CHECK_RETURN(shape, NULL);

    return shape->Texture;
}


////////////////////////////////////////////////////////////
sfIntRect sfConvexShape_GetTextureRect(const sfConvexShape* shape)
{
    sfIntRect rect = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(shape, rect);

    sf::IntRect sfmlRect = shape->This.GetTextureRect();
    rect.Left = sfmlRect.Left;
    rect.Top = sfmlRect.Top;
    rect.Width = sfmlRect.Width;
    rect.Height = sfmlRect.Height;

    return rect;
}


////////////////////////////////////////////////////////////
sfColor sfConvexShape_GetFillColor(const sfConvexShape* shape)
{
    sfColor color = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(shape, color);

    sf::Color sfmlColor = shape->This.GetFillColor();
    color.r = sfmlColor.r;
    color.g = sfmlColor.g;
    color.b = sfmlColor.b;
    color.a = sfmlColor.a;

    return color;
}


////////////////////////////////////////////////////////////
sfColor sfConvexShape_GetOutlineColor(const sfConvexShape* shape)
{
    sfColor color = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(shape, color);

    sf::Color sfmlColor = shape->This.GetOutlineColor();
    color.r = sfmlColor.r;
    color.g = sfmlColor.g;
    color.b = sfmlColor.b;
    color.a = sfmlColor.a;

    return color;
}


////////////////////////////////////////////////////////////
float sfConvexShape_GetOutlineThickness(const sfConvexShape* shape)
{
    CSFML_CALL_RETURN(shape, GetOutlineThickness(), 0.f);
}


////////////////////////////////////////////////////////////
unsigned int sfConvexShape_GetPointCount(const sfConvexShape* shape)
{
    CSFML_CALL_RETURN(shape, GetPointCount(), 0);
}


////////////////////////////////////////////////////////////
sfVector2f sfConvexShape_GetPoint(const sfConvexShape* shape, unsigned int index)
{
    sfVector2f point = {0, 0};
    CSFML_CHECK_RETURN(shape, point);

    sf::Vector2f sfmlPoint = shape->This.GetPoint(index);
    point.x = sfmlPoint.x;
    point.y = sfmlPoint.y;

    return point;
}


////////////////////////////////////////////////////////////
void sfConvexShape_SetPointCount(sfConvexShape* shape, unsigned int count)
{
    CSFML_CALL(shape, SetPointCount(count));
}


////////////////////////////////////////////////////////////
void sfConvexShape_SetPoint(sfConvexShape* shape, unsigned int index, sfVector2f point)
{
    CSFML_CALL(shape, SetPoint(index, sf::Vector2f(point.x, point.y)));
}


////////////////////////////////////////////////////////////
sfFloatRect sfConvexShape_GetLocalBounds(const sfConvexShape* shape)
{
    sfFloatRect rect = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(shape, rect);

    sf::FloatRect sfmlRect = shape->This.GetLocalBounds();
    rect.Left = sfmlRect.Left;
    rect.Top = sfmlRect.Top;
    rect.Width = sfmlRect.Width;
    rect.Height = sfmlRect.Height;

    return rect;
}


////////////////////////////////////////////////////////////
sfFloatRect sfConvexShape_GetGlobalBounds(const sfConvexShape* shape)
{
    sfFloatRect rect = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(shape, rect);

    sf::FloatRect sfmlRect = shape->This.GetGlobalBounds();
    rect.Left = sfmlRect.Left;
    rect.Top = sfmlRect.Top;
    rect.Width = sfmlRect.Width;
    rect.Height = sfmlRect.Height;

    return rect;
}
