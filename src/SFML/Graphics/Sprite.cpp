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
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/SpriteStruct.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfSprite* sfSprite_Create(void)
{
    sfSprite* sprite = new sfSprite;
    sprite->Texture = NULL;

    return sprite;
}


////////////////////////////////////////////////////////////
sfSprite* sfSprite_Copy(sfSprite* sprite)
{
    CSFML_CHECK_RETURN(sprite, NULL);

    return new sfSprite(*sprite);
}


////////////////////////////////////////////////////////////
void sfSprite_Destroy(sfSprite* sprite)
{
    delete sprite;
}


////////////////////////////////////////////////////////////
void sfSprite_SetPosition(sfSprite* sprite, sfVector2f position)
{
    CSFML_CALL(sprite, SetPosition(position.x, position.y));
}


////////////////////////////////////////////////////////////
void sfSprite_SetRotation(sfSprite* sprite, float angle)
{
    CSFML_CALL(sprite, SetRotation(angle));
}


////////////////////////////////////////////////////////////
void sfSprite_SetScale(sfSprite* sprite, sfVector2f scale)
{
    CSFML_CALL(sprite, SetScale(scale.x, scale.y));
}


////////////////////////////////////////////////////////////
void sfSprite_SetOrigin(sfSprite* sprite, sfVector2f origin)
{
    CSFML_CALL(sprite, SetOrigin(origin.x, origin.y));
}


////////////////////////////////////////////////////////////
sfVector2f sfSprite_GetPosition(const sfSprite* sprite)
{
    sfVector2f position = {0, 0};
    CSFML_CHECK_RETURN(sprite, position);

    sf::Vector2f sfmlPos = sprite->This.GetPosition();
    position.x = sfmlPos.x;
    position.y = sfmlPos.y;

    return position;
}


////////////////////////////////////////////////////////////
float sfSprite_GetRotation(const sfSprite* sprite)
{
    CSFML_CALL_RETURN(sprite, GetRotation(), 0.f);
}


////////////////////////////////////////////////////////////
sfVector2f sfSprite_GetScale(const sfSprite* sprite)
{
    sfVector2f scale = {0, 0};
    CSFML_CHECK_RETURN(sprite, scale);

    sf::Vector2f sfmlScale = sprite->This.GetScale();
    scale.x = sfmlScale.x;
    scale.y = sfmlScale.y;

    return scale;
}


////////////////////////////////////////////////////////////
sfVector2f sfSprite_GetOrigin(const sfSprite* sprite)
{
    sfVector2f origin = {0, 0};
    CSFML_CHECK_RETURN(sprite, origin);

    sf::Vector2f sfmlOrigin = sprite->This.GetOrigin();
    origin.x = sfmlOrigin.x;
    origin.y = sfmlOrigin.y;

    return origin;
}


////////////////////////////////////////////////////////////
void sfSprite_Move(sfSprite* sprite, sfVector2f offset)
{
    CSFML_CALL(sprite, Move(offset.x, offset.y));
}


////////////////////////////////////////////////////////////
void sfSprite_Rotate(sfSprite* sprite, float angle)
{
    CSFML_CALL(sprite, Rotate(angle));
}


////////////////////////////////////////////////////////////
void sfSprite_Scale(sfSprite* sprite, sfVector2f factors)
{
    CSFML_CALL(sprite, Scale(factors.x, factors.y));
}


////////////////////////////////////////////////////////////
const sfTransform* sfSprite_GetTransform(const sfSprite* sprite)
{
    CSFML_CHECK_RETURN(sprite, NULL);

    sprite->Transform.This = sprite->This.GetTransform();
    return &sprite->Transform;
}


////////////////////////////////////////////////////////////
const sfTransform* sfSprite_GetInverseTransform(const sfSprite* sprite)
{
    CSFML_CHECK_RETURN(sprite, NULL);

    sprite->InverseTransform.This = sprite->This.GetInverseTransform();
    return &sprite->InverseTransform;
}


////////////////////////////////////////////////////////////
void sfSprite_SetTexture(sfSprite* sprite, const sfTexture* texture, sfBool resetRect)
{
    if (texture && texture->This)
    {
        CSFML_CALL(sprite, SetTexture(*texture->This, resetRect == sfTrue));
        sprite->Texture = texture;
    }
}


////////////////////////////////////////////////////////////
void sfSprite_SetTextureRect(sfSprite* sprite, sfIntRect rectangle)
{
    CSFML_CALL(sprite, SetTextureRect(sf::IntRect(rectangle.Left, rectangle.Top, rectangle.Width, rectangle.Height)));
}


////////////////////////////////////////////////////////////
void sfSprite_SetColor(sfSprite* sprite, sfColor color)
{
    CSFML_CALL(sprite, SetColor(sf::Color(color.r, color.g, color.b, color.a)));
}


////////////////////////////////////////////////////////////
const sfTexture* sfSprite_GetTexture(const sfSprite* sprite)
{
    CSFML_CHECK_RETURN(sprite, NULL);

    return sprite->Texture;
}


////////////////////////////////////////////////////////////
sfIntRect sfSprite_GetTextureRect(const sfSprite* sprite)
{
    sfIntRect rect = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(sprite, rect);

    sf::IntRect sfmlRect = sprite->This.GetTextureRect();
    rect.Left = sfmlRect.Left;
    rect.Top = sfmlRect.Top;
    rect.Width = sfmlRect.Width;
    rect.Height = sfmlRect.Height;

    return rect;
}


////////////////////////////////////////////////////////////
sfColor sfSprite_GetColor(const sfSprite* sprite)
{
    sfColor color = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(sprite, color);

    sf::Color sfmlColor = sprite->This.GetColor();
    color.r = sfmlColor.r;
    color.g = sfmlColor.g;
    color.b = sfmlColor.b;
    color.a = sfmlColor.a;

    return color;
}


////////////////////////////////////////////////////////////
sfFloatRect sfSprite_GetLocalBounds(const sfSprite* sprite)
{
    sfFloatRect rect = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(sprite, rect);

    sf::FloatRect sfmlRect = sprite->This.GetLocalBounds();
    rect.Left = sfmlRect.Left;
    rect.Top = sfmlRect.Top;
    rect.Width = sfmlRect.Width;
    rect.Height = sfmlRect.Height;

    return rect;
}


////////////////////////////////////////////////////////////
sfFloatRect sfSprite_GetGlobalBounds(const sfSprite* sprite)
{
    sfFloatRect rect = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(sprite, rect);

    sf::FloatRect sfmlRect = sprite->This.GetGlobalBounds();
    rect.Left = sfmlRect.Left;
    rect.Top = sfmlRect.Top;
    rect.Width = sfmlRect.Width;
    rect.Height = sfmlRect.Height;

    return rect;
}
