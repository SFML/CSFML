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
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/CircleShapeStruct.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfCircleShape* sfCircleShape_Create(void)
{
    sfCircleShape* shape = new sfCircleShape;
    shape->Texture = NULL;

    return shape;
}


////////////////////////////////////////////////////////////
sfCircleShape* sfCircleShape_Copy(sfCircleShape* shape)
{
    CSFML_CHECK_RETURN(shape, NULL);

    return new sfCircleShape(*shape);
}


////////////////////////////////////////////////////////////
void sfCircleShape_Destroy(sfCircleShape* shape)
{
    delete shape;
}


////////////////////////////////////////////////////////////
void sfCircleShape_SetPosition(sfCircleShape* shape, sfVector2f position)
{
    CSFML_CALL(shape, SetPosition(position.x, position.y));
}


////////////////////////////////////////////////////////////
void sfCircleShape_SetRotation(sfCircleShape* shape, float angle)
{
    CSFML_CALL(shape, SetRotation(angle));
}


////////////////////////////////////////////////////////////
void sfCircleShape_SetScale(sfCircleShape* shape, sfVector2f scale)
{
    CSFML_CALL(shape, SetScale(scale.x, scale.y));
}


////////////////////////////////////////////////////////////
void sfCircleShape_SetOrigin(sfCircleShape* shape, sfVector2f origin)
{
    CSFML_CALL(shape, SetOrigin(origin.x, origin.y));
}


////////////////////////////////////////////////////////////
sfVector2f sfCircleShape_GetPosition(const sfCircleShape* shape)
{
    sfVector2f position = {0, 0};
    CSFML_CHECK_RETURN(shape, position);

    sf::Vector2f sfmlPos = shape->This.GetPosition();
    position.x = sfmlPos.x;
    position.y = sfmlPos.y;

    return position;
}


////////////////////////////////////////////////////////////
float sfCircleShape_GetRotation(const sfCircleShape* shape)
{
    CSFML_CALL_RETURN(shape, GetRotation(), 0.f);
}


////////////////////////////////////////////////////////////
sfVector2f sfCircleShape_GetScale(const sfCircleShape* shape)
{
    sfVector2f scale = {0, 0};
    CSFML_CHECK_RETURN(shape, scale);

    sf::Vector2f sfmlScale = shape->This.GetScale();
    scale.x = sfmlScale.x;
    scale.y = sfmlScale.y;

    return scale;
}


////////////////////////////////////////////////////////////
sfVector2f sfCircleShape_GetOrigin(const sfCircleShape* shape)
{
    sfVector2f origin = {0, 0};
    CSFML_CHECK_RETURN(shape, origin);

    sf::Vector2f sfmlOrigin = shape->This.GetOrigin();
    origin.x = sfmlOrigin.x;
    origin.y = sfmlOrigin.y;

    return origin;
}


////////////////////////////////////////////////////////////
void sfCircleShape_Move(sfCircleShape* shape, sfVector2f offset)
{
    CSFML_CALL(shape, Move(offset.x, offset.y));
}


////////////////////////////////////////////////////////////
void sfCircleShape_Rotate(sfCircleShape* shape, float angle)
{
    CSFML_CALL(shape, Rotate(angle));
}


////////////////////////////////////////////////////////////
void sfCircleShape_Scale(sfCircleShape* shape, sfVector2f factors)
{
    CSFML_CALL(shape, Scale(factors.x, factors.y));
}


////////////////////////////////////////////////////////////
const sfTransform* sfCircleShape_GetTransform(const sfCircleShape* shape)
{
    CSFML_CHECK_RETURN(shape, NULL);

    shape->Transform.This = shape->This.GetTransform();
    return &shape->Transform;
}


////////////////////////////////////////////////////////////
const sfTransform* sfCircleShape_GetInverseTransform(const sfCircleShape* shape)
{
    CSFML_CHECK_RETURN(shape, NULL);

    shape->InverseTransform.This = shape->This.GetInverseTransform();
    return &shape->InverseTransform;
}


////////////////////////////////////////////////////////////
void sfCircleShape_SetTexture(sfCircleShape* shape, const sfTexture* texture, sfBool resetRect)
{
    CSFML_CALL(shape, SetTexture(texture ? texture->This : NULL, resetRect == sfTrue));
    shape->Texture = texture;
}


////////////////////////////////////////////////////////////
void sfCircleShape_SetTextureRect(sfCircleShape* shape, sfIntRect rect)
{
    CSFML_CALL(shape, SetTextureRect(sf::IntRect(rect.Left, rect.Top, rect.Width, rect.Height)));
}


////////////////////////////////////////////////////////////
void sfCircleShape_SetFillColor(sfCircleShape* shape, sfColor color)
{
    CSFML_CALL(shape, SetFillColor(sf::Color(color.r, color.g, color.b, color.a)));
}


////////////////////////////////////////////////////////////
void sfCircleShape_SetOutlineColor(sfCircleShape* shape, sfColor color)
{
    CSFML_CALL(shape, SetOutlineColor(sf::Color(color.r, color.g, color.b, color.a)));
}


////////////////////////////////////////////////////////////
void sfCircleShape_SetOutlineThickness(sfCircleShape* shape, float thickness)
{
    CSFML_CALL(shape, SetOutlineThickness(thickness));
}


////////////////////////////////////////////////////////////
const sfTexture* sfCircleShape_GetTexture(const sfCircleShape* shape)
{
    CSFML_CHECK_RETURN(shape, NULL);

    return shape->Texture;
}


////////////////////////////////////////////////////////////
sfIntRect sfCircleShape_GetTextureRect(const sfCircleShape* shape)
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
sfColor sfCircleShape_GetFillColor(const sfCircleShape* shape)
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
sfColor sfCircleShape_GetOutlineColor(const sfCircleShape* shape)
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
float sfCircleShape_GetOutlineThickness(const sfCircleShape* shape)
{
    CSFML_CALL_RETURN(shape, GetOutlineThickness(), 0.f);
}


////////////////////////////////////////////////////////////
unsigned int sfCircleShape_GetPointCount(const sfCircleShape* shape)
{
    CSFML_CALL_RETURN(shape, GetPointCount(), 0);
}


////////////////////////////////////////////////////////////
sfVector2f sfCircleShape_GetPoint(const sfCircleShape* shape, unsigned int index)
{
    sfVector2f point = {0, 0};
    CSFML_CHECK_RETURN(shape, point);

    sf::Vector2f sfmlPoint = shape->This.GetPoint(index);
    point.x = sfmlPoint.x;
    point.y = sfmlPoint.y;

    return point;
}


////////////////////////////////////////////////////////////
void sfCircleShape_SetRadius(sfCircleShape* shape, float radius)
{
    CSFML_CALL(shape, SetRadius(radius));
}


////////////////////////////////////////////////////////////
float sfCircleShape_GetRadius(const sfCircleShape* shape)
{
    CSFML_CALL_RETURN(shape, GetRadius(), 0.f);
}


////////////////////////////////////////////////////////////
void sfCircleShape_SetPointCount(sfCircleShape* shape, unsigned int count)
{
    CSFML_CALL(shape, SetPointCount(count));
}


////////////////////////////////////////////////////////////
sfFloatRect sfCircleShape_GetLocalBounds(const sfCircleShape* shape)
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
sfFloatRect sfCircleShape_GetGlobalBounds(const sfCircleShape* shape)
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
