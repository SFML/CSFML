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
#include <CSFML/Graphics/Sprite.h>
#include <CSFML/Graphics/SpriteStruct.hpp>
#include <CSFML/System/ConvertVector2.hpp>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>


////////////////////////////////////////////////////////////
sfSprite* sfSprite_create(const sfTexture* texture)
{
    assert(texture);
    assert(texture->This);
    return new sfSprite{sf::Sprite{*texture->This}, texture, {}, {}};
}


////////////////////////////////////////////////////////////
sfSprite* sfSprite_copy(const sfSprite* sprite)
{
    assert(sprite);
    return new sfSprite(*sprite);
}


////////////////////////////////////////////////////////////
void sfSprite_destroy(const sfSprite* sprite)
{
    delete sprite;
}


////////////////////////////////////////////////////////////
void sfSprite_setPosition(sfSprite* sprite, sfVector2f position)
{
    assert(sprite);
    sprite->This.setPosition(convertVector2(position));
}


////////////////////////////////////////////////////////////
void sfSprite_setRotation(sfSprite* sprite, float angle)
{
    assert(sprite);
    sprite->This.setRotation(sf::degrees(angle));
}


////////////////////////////////////////////////////////////
void sfSprite_setScale(sfSprite* sprite, sfVector2f scale)
{
    assert(sprite);
    sprite->This.setScale(convertVector2(scale));
}


////////////////////////////////////////////////////////////
void sfSprite_setOrigin(sfSprite* sprite, sfVector2f origin)
{
    assert(sprite);
    sprite->This.setOrigin(convertVector2(origin));
}


////////////////////////////////////////////////////////////
sfVector2f sfSprite_getPosition(const sfSprite* sprite)
{
    assert(sprite);
    return convertVector2(sprite->This.getPosition());
}


////////////////////////////////////////////////////////////
float sfSprite_getRotation(const sfSprite* sprite)
{
    assert(sprite);
    return sprite->This.getRotation().asDegrees();
}


////////////////////////////////////////////////////////////
sfVector2f sfSprite_getScale(const sfSprite* sprite)
{
    assert(sprite);
    return convertVector2(sprite->This.getScale());
}


////////////////////////////////////////////////////////////
sfVector2f sfSprite_getOrigin(const sfSprite* sprite)
{
    assert(sprite);
    return convertVector2(sprite->This.getOrigin());
}


////////////////////////////////////////////////////////////
void sfSprite_move(sfSprite* sprite, sfVector2f offset)
{
    assert(sprite);
    sprite->This.move(convertVector2(offset));
}


////////////////////////////////////////////////////////////
void sfSprite_rotate(sfSprite* sprite, float angle)
{
    assert(sprite);
    sprite->This.rotate(sf::degrees(angle));
}


////////////////////////////////////////////////////////////
void sfSprite_scale(sfSprite* sprite, sfVector2f factors)
{
    assert(sprite);
    sprite->This.scale(convertVector2(factors));
}


////////////////////////////////////////////////////////////
sfTransform sfSprite_getTransform(const sfSprite* sprite)
{
    assert(sprite);
    sprite->Transform = convertTransform(sprite->This.getTransform());
    return sprite->Transform;
}


////////////////////////////////////////////////////////////
sfTransform sfSprite_getInverseTransform(const sfSprite* sprite)
{
    assert(sprite);
    sprite->InverseTransform = convertTransform(sprite->This.getInverseTransform());
    return sprite->InverseTransform;
}


////////////////////////////////////////////////////////////
void sfSprite_setTexture(sfSprite* sprite, const sfTexture* texture, bool resetRect)
{
    if (texture && texture->This)
    {
        assert(sprite);
        sprite->This.setTexture(*texture->This, resetRect);
        sprite->Texture = texture;
    }
}


////////////////////////////////////////////////////////////
void sfSprite_setTextureRect(sfSprite* sprite, sfIntRect rectangle)
{
    assert(sprite);
    sprite->This.setTextureRect(convertRect(rectangle));
}


////////////////////////////////////////////////////////////
void sfSprite_setColor(sfSprite* sprite, sfColor color)
{
    assert(sprite);
    sprite->This.setColor(convertColor(color));
}


////////////////////////////////////////////////////////////
const sfTexture* sfSprite_getTexture(const sfSprite* sprite)
{
    assert(sprite);
    return sprite->Texture;
}


////////////////////////////////////////////////////////////
sfIntRect sfSprite_getTextureRect(const sfSprite* sprite)
{
    assert(sprite);
    return convertRect(sprite->This.getTextureRect());
}


////////////////////////////////////////////////////////////
sfColor sfSprite_getColor(const sfSprite* sprite)
{
    assert(sprite);
    return convertColor(sprite->This.getColor());
}


////////////////////////////////////////////////////////////
sfFloatRect sfSprite_getLocalBounds(const sfSprite* sprite)
{
    assert(sprite);
    return convertRect(sprite->This.getLocalBounds());
}


////////////////////////////////////////////////////////////
sfFloatRect sfSprite_getGlobalBounds(const sfSprite* sprite)
{
    assert(sprite);
    return convertRect(sprite->This.getGlobalBounds());
}
