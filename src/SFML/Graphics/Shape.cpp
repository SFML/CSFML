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
#include <SFML/Graphics/Shape.h>
#include <SFML/Graphics/ShapeStruct.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfShape* sfShape_Create(sfShapeGetPointCountCallback getPointCount,
                        sfShapeGetPointCallback getPoint,
                        void* userData)
{
    return new sfShape(getPointCount, getPoint, userData);
}


////////////////////////////////////////////////////////////
void sfShape_Destroy(sfShape* shape)
{
    delete shape;
}


////////////////////////////////////////////////////////////
void sfShape_SetPosition(sfShape* shape, float x, float y)
{
    CSFML_CALL(shape, SetPosition(x, y));
}


////////////////////////////////////////////////////////////
void sfShape_SetRotation(sfShape* shape, float angle)
{
    CSFML_CALL(shape, SetRotation(angle));
}


////////////////////////////////////////////////////////////
void sfShape_SetScale(sfShape* shape, float factorX, float factorY)
{
    CSFML_CALL(shape, SetScale(factorX, factorY));
}


////////////////////////////////////////////////////////////
void sfShape_SetOrigin(sfShape* shape, float x, float y)
{
    CSFML_CALL(shape, SetOrigin(x, y));
}


////////////////////////////////////////////////////////////
void sfShape_GetPosition(const sfShape* shape, float* x, float* y)
{
    CSFML_CHECK(shape);

    sf::Vector2f point = shape->This.GetPosition();

    if (x)
        *x = point.x;
    if (y)
        *y = point.y;
}


////////////////////////////////////////////////////////////
float sfShape_GetRotation(const sfShape* shape)
{
    CSFML_CALL_RETURN(shape, GetRotation(), 0.f);
}


////////////////////////////////////////////////////////////
void sfShape_GetScale(const sfShape* shape, float* x, float* y)
{
    CSFML_CHECK(shape);

    sf::Vector2f point = shape->This.GetScale();

    if (x)
        *x = point.x;
    if (y)
        *y = point.y;
}


////////////////////////////////////////////////////////////
void sfShape_GetOrigin(const sfShape* shape, float* x, float* y)
{
    CSFML_CHECK(shape);

    sf::Vector2f point = shape->This.GetOrigin();

    if (x)
        *x = point.x;
    if (y)
        *y = point.y;
}


////////////////////////////////////////////////////////////
void sfShape_Move(sfShape* shape, float offsetX, float offsetY)
{
    CSFML_CALL(shape, Move(offsetX, offsetY));
}


////////////////////////////////////////////////////////////
void sfShape_Rotate(sfShape* shape, float angle)
{
    CSFML_CALL(shape, Rotate(angle));
}


////////////////////////////////////////////////////////////
void sfShape_Scale(sfShape* shape, float factorX, float factorY)
{
    CSFML_CALL(shape, Scale(factorX, factorY));
}


////////////////////////////////////////////////////////////
const sfTransform* sfShape_GetTransform(const sfShape* shape)
{
    CSFML_CHECK_RETURN(shape, NULL);

    shape->Transform.This = shape->This.GetTransform();
    return &shape->Transform;
}


////////////////////////////////////////////////////////////
const sfTransform* sfShape_GetInverseTransform(const sfShape* shape)
{
    CSFML_CHECK_RETURN(shape, NULL);

    shape->InverseTransform.This = shape->This.GetInverseTransform();
    return &shape->InverseTransform;
}


////////////////////////////////////////////////////////////
void sfShape_SetTexture(sfShape* shape, const sfTexture* texture, sfBool resetRect)
{
    CSFML_CALL(shape, SetTexture(texture ? texture->This : NULL, resetRect == sfTrue));
    shape->Texture = texture;
}


////////////////////////////////////////////////////////////
void sfShape_SetTextureRect(sfShape* shape, sfIntRect rect)
{
    CSFML_CALL(shape, SetTextureRect(sf::IntRect(rect.Left, rect.Top, rect.Width, rect.Height)));
}


////////////////////////////////////////////////////////////
void sfShape_SetFillColor(sfShape* shape, sfColor color)
{
    CSFML_CALL(shape, SetFillColor(sf::Color(color.r, color.g, color.b, color.a)));
}


////////////////////////////////////////////////////////////
void sfShape_SetOutlineColor(sfShape* shape, sfColor color)
{
    CSFML_CALL(shape, SetOutlineColor(sf::Color(color.r, color.g, color.b, color.a)));
}


////////////////////////////////////////////////////////////
void sfShape_SetOutlineThickness(sfShape* shape, float thickness)
{
    CSFML_CALL(shape, SetOutlineThickness(thickness));
}


////////////////////////////////////////////////////////////
const sfTexture* sfShape_GetTexture(const sfShape* shape)
{
    CSFML_CHECK_RETURN(shape, NULL);

    return shape->Texture;
}


////////////////////////////////////////////////////////////
sfIntRect sfShape_GetTextureRect(const sfShape* shape)
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
sfColor sfShape_GetFillColor(const sfShape* shape)
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
sfColor sfShape_GetOutlineColor(const sfShape* shape)
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
float sfShape_GetOutlineThickness(const sfShape* shape)
{
    CSFML_CALL_RETURN(shape, GetOutlineThickness(), 0.f);
}


////////////////////////////////////////////////////////////
unsigned int sfShape_GetPointCount(const sfShape* shape)
{
    CSFML_CALL_RETURN(shape, GetPointCount(), 0);
}


////////////////////////////////////////////////////////////
void sfShape_GetPoint(const sfShape* shape, unsigned int index, float* x, float* y)
{
    CSFML_CHECK(shape);

    sf::Vector2f point = shape->This.GetPoint(index);
    if (x)
        *x = point.x;
    if (y)
        *y = point.y;
}


////////////////////////////////////////////////////////////
sfFloatRect sfShape_GetLocalBounds(const sfShape* shape)
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
sfFloatRect sfShape_GetGlobalBounds(const sfShape* shape)
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


////////////////////////////////////////////////////////////
void sfShape_Update(sfShape* shape)
{
    CSFML_CALL(shape, Update());
}
