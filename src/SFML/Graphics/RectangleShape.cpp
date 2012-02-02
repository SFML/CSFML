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
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RectangleShapeStruct.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfRectangleShape* sfRectangleShape_Create(void)
{
    return new sfRectangleShape;
}


////////////////////////////////////////////////////////////
sfRectangleShape* sfRectangleShape_Copy(sfRectangleShape* shape)
{
    CSFML_CHECK_RETURN(shape, NULL);

    return new sfRectangleShape(*shape);
}


////////////////////////////////////////////////////////////
void sfRectangleShape_Destroy(sfRectangleShape* shape)
{
    delete shape;
}


////////////////////////////////////////////////////////////
void sfRectangleShape_SetPosition(sfRectangleShape* shape, float x, float y)
{
    CSFML_CALL(shape, SetPosition(x, y));
}


////////////////////////////////////////////////////////////
void sfRectangleShape_SetRotation(sfRectangleShape* shape, float angle)
{
    CSFML_CALL(shape, SetRotation(angle));
}


////////////////////////////////////////////////////////////
void sfRectangleShape_SetScale(sfRectangleShape* shape, float factorX, float factorY)
{
    CSFML_CALL(shape, SetScale(factorX, factorY));
}


////////////////////////////////////////////////////////////
void sfRectangleShape_SetOrigin(sfRectangleShape* shape, float x, float y)
{
    CSFML_CALL(shape, SetOrigin(x, y));
}


////////////////////////////////////////////////////////////
void sfRectangleShape_GetPosition(const sfRectangleShape* shape, float* x, float* y)
{
    CSFML_CHECK(shape);

    sf::Vector2f point = shape->This.GetPosition();

    if (x)
        *x = point.x;
    if (y)
        *y = point.y;
}


////////////////////////////////////////////////////////////
float sfRectangleShape_GetRotation(const sfRectangleShape* shape)
{
    CSFML_CALL_RETURN(shape, GetRotation(), 0.f);
}


////////////////////////////////////////////////////////////
void sfRectangleShape_GetScale(const sfRectangleShape* shape, float* x, float* y)
{
    CSFML_CHECK(shape);

    sf::Vector2f point = shape->This.GetScale();

    if (x)
        *x = point.x;
    if (y)
        *y = point.y;
}


////////////////////////////////////////////////////////////
void sfRectangleShape_GetOrigin(const sfRectangleShape* shape, float* x, float* y)
{
    CSFML_CHECK(shape);

    sf::Vector2f point = shape->This.GetOrigin();

    if (x)
        *x = point.x;
    if (y)
        *y = point.y;
}


////////////////////////////////////////////////////////////
void sfRectangleShape_Move(sfRectangleShape* shape, float offsetX, float offsetY)
{
    CSFML_CALL(shape, Move(offsetX, offsetY));
}


////////////////////////////////////////////////////////////
void sfRectangleShape_Rotate(sfRectangleShape* shape, float angle)
{
    CSFML_CALL(shape, Rotate(angle));
}


////////////////////////////////////////////////////////////
void sfRectangleShape_Scale(sfRectangleShape* shape, float factorX, float factorY)
{
    CSFML_CALL(shape, Scale(factorX, factorY));
}


////////////////////////////////////////////////////////////
const sfTransform* sfRectangleShape_GetTransform(const sfRectangleShape* shape)
{
    CSFML_CHECK_RETURN(shape, NULL);

    shape->Transform.This = shape->This.GetTransform();
    return &shape->Transform;
}


////////////////////////////////////////////////////////////
const sfTransform* sfRectangleShape_GetInverseTransform(const sfRectangleShape* shape)
{
    CSFML_CHECK_RETURN(shape, NULL);

    shape->InverseTransform.This = shape->This.GetInverseTransform();
    return &shape->InverseTransform;
}


////////////////////////////////////////////////////////////
void sfRectangleShape_SetTexture(sfRectangleShape* shape, const sfTexture* texture, sfBool resetRect)
{
    CSFML_CALL(shape, SetTexture(texture ? texture->This : NULL, resetRect == sfTrue));
    shape->Texture = texture;
}


////////////////////////////////////////////////////////////
void sfRectangleShape_SetTextureRect(sfRectangleShape* shape, sfIntRect rect)
{
    CSFML_CALL(shape, SetTextureRect(sf::IntRect(rect.Left, rect.Top, rect.Width, rect.Height)));
}


////////////////////////////////////////////////////////////
void sfRectangleShape_SetFillColor(sfRectangleShape* shape, sfColor color)
{
    CSFML_CALL(shape, SetFillColor(sf::Color(color.r, color.g, color.b, color.a)));
}


////////////////////////////////////////////////////////////
void sfRectangleShape_SetOutlineColor(sfRectangleShape* shape, sfColor color)
{
    CSFML_CALL(shape, SetOutlineColor(sf::Color(color.r, color.g, color.b, color.a)));
}


////////////////////////////////////////////////////////////
void sfRectangleShape_SetOutlineThickness(sfRectangleShape* shape, float thickness)
{
    CSFML_CALL(shape, SetOutlineThickness(thickness));
}


////////////////////////////////////////////////////////////
const sfTexture* sfRectangleShape_GetTexture(const sfRectangleShape* shape)
{
    CSFML_CHECK_RETURN(shape, NULL);

    return shape->Texture;
}


////////////////////////////////////////////////////////////
sfIntRect sfRectangleShape_GetTextureRect(const sfRectangleShape* shape)
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
sfColor sfRectangleShape_GetFillColor(const sfRectangleShape* shape)
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
sfColor sfRectangleShape_GetOutlineColor(const sfRectangleShape* shape)
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
float sfRectangleShape_GetOutlineThickness(const sfRectangleShape* shape)
{
    CSFML_CALL_RETURN(shape, GetOutlineThickness(), 0.f);
}


////////////////////////////////////////////////////////////
unsigned int sfRectangleShape_GetPointCount(const sfRectangleShape* shape)
{
    CSFML_CALL_RETURN(shape, GetPointCount(), 0);
}


////////////////////////////////////////////////////////////
void sfRectangleShape_GetPoint(const sfRectangleShape* shape, unsigned int index, float* x, float* y)
{
    CSFML_CHECK(shape);

    sf::Vector2f point = shape->This.GetPoint(index);
    if (x)
        *x = point.x;
    if (y)
        *y = point.y;
}


////////////////////////////////////////////////////////////
void sfRectangleShape_SetSize(sfRectangleShape* shape, float width, float height)
{
    CSFML_CALL(shape, SetSize(sf::Vector2f(width, height)));
}


////////////////////////////////////////////////////////////
void sfRectangleShape_GetSize(const sfRectangleShape* shape, float* width, float* height)
{
    CSFML_CHECK(shape);

    sf::Vector2f size = shape->This.GetSize();
    if (width)
        *width = size.x;
    if (height)
        *height = size.y;
}
