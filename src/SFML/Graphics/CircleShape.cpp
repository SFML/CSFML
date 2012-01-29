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
void sfCircleShape_SetPosition(sfCircleShape* shape, float x, float y)
{
    CSFML_CALL(shape, SetPosition(x, y));
}


////////////////////////////////////////////////////////////
void sfCircleShape_SetRotation(sfCircleShape* shape, float angle)
{
    CSFML_CALL(shape, SetRotation(angle));
}


////////////////////////////////////////////////////////////
void sfCircleShape_SetScale(sfCircleShape* shape, float factorX, float factorY)
{
    CSFML_CALL(shape, SetScale(factorX, factorY));
}


////////////////////////////////////////////////////////////
void sfCircleShape_SetOrigin(sfCircleShape* shape, float x, float y)
{
    CSFML_CALL(shape, SetOrigin(x, y));
}


////////////////////////////////////////////////////////////
void sfCircleShape_GetPosition(const sfCircleShape* shape, float* x, float* y)
{
    CSFML_CHECK(shape);

    sf::Vector2f point = shape->This.GetPosition();

    if (x)
        *x = point.x;
    if (y)
        *y = point.y;
}


////////////////////////////////////////////////////////////
float sfCircleShape_GetRotation(const sfCircleShape* shape)
{
    CSFML_CALL_RETURN(shape, GetRotation(), 0.f);
}


////////////////////////////////////////////////////////////
void sfCircleShape_GetScale(const sfCircleShape* shape, float* x, float* y)
{
    CSFML_CHECK(shape);

    sf::Vector2f point = shape->This.GetScale();

    if (x)
        *x = point.x;
    if (y)
        *y = point.y;
}


////////////////////////////////////////////////////////////
void sfCircleShape_GetOrigin(const sfCircleShape* shape, float* x, float* y)
{
    CSFML_CHECK(shape);

    sf::Vector2f point = shape->This.GetOrigin();

    if (x)
        *x = point.x;
    if (y)
        *y = point.y;
}


////////////////////////////////////////////////////////////
void sfCircleShape_Move(sfCircleShape* shape, float offsetX, float offsetY)
{
    CSFML_CALL(shape, Move(offsetX, offsetY));
}


////////////////////////////////////////////////////////////
void sfCircleShape_Rotate(sfCircleShape* shape, float angle)
{
    CSFML_CALL(shape, Rotate(angle));
}


////////////////////////////////////////////////////////////
void sfCircleShape_Scale(sfCircleShape* shape, float factorX, float factorY)
{
    CSFML_CALL(shape, Scale(factorX, factorY));
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
    CSFML_CALL(shape, SetTexture(texture ? texture->This : NULL, resetRect == sfTrue))
    shape->Texture = texture;
}


////////////////////////////////////////////////////////////
void sfCircleShape_SetTextureRect(sfCircleShape* shape, sfIntRect rect)
{
    CSFML_CALL(shape, SetTextureRect(sf::IntRect(rect.Left, rect.Top, rect.Width, rect.Height)))
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
    CSFML_CHECK_RETURN(shape, NULL)

    return shape->Texture;
}


////////////////////////////////////////////////////////////
sfIntRect sfCircleShape_GetTextureRect(const sfCircleShape* shape)
{
    sfIntRect rect = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(sprite, rect)

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
void sfCircleShape_GetPoint(const sfCircleShape* shape, unsigned int index, float* x, float* y)
{
    CSFML_CHECK(shape);

    sf::Vector2f point = shape->This.GetPoint(index);
    if (x)
        *x = point.x;
    if (y)
        *y = point.y;
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
