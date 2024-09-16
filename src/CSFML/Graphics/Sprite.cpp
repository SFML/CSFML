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
    auto sprite     = new sfSprite(*texture->This);
    sprite->Texture = texture;
    return sprite;
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
    sprite->setPosition(convertVector2(position));
}


////////////////////////////////////////////////////////////
void sfSprite_setRotation(sfSprite* sprite, float angle)
{
    assert(sprite);
    sprite->setRotation(sf::degrees(angle));
}


////////////////////////////////////////////////////////////
void sfSprite_setScale(sfSprite* sprite, sfVector2f scale)
{
    assert(sprite);
    sprite->setScale(convertVector2(scale));
}


////////////////////////////////////////////////////////////
void sfSprite_setOrigin(sfSprite* sprite, sfVector2f origin)
{
    assert(sprite);
    sprite->setOrigin(convertVector2(origin));
}


////////////////////////////////////////////////////////////
sfVector2f sfSprite_getPosition(const sfSprite* sprite)
{
    assert(sprite);
    return convertVector2(sprite->getPosition());
}


////////////////////////////////////////////////////////////
float sfSprite_getRotation(const sfSprite* sprite)
{
    assert(sprite);
    return sprite->getRotation().asDegrees();
}


////////////////////////////////////////////////////////////
sfVector2f sfSprite_getScale(const sfSprite* sprite)
{
    assert(sprite);
    return convertVector2(sprite->getScale());
}


////////////////////////////////////////////////////////////
sfVector2f sfSprite_getOrigin(const sfSprite* sprite)
{
    assert(sprite);
    return convertVector2(sprite->getOrigin());
}


////////////////////////////////////////////////////////////
void sfSprite_move(sfSprite* sprite, sfVector2f offset)
{
    assert(sprite);
    sprite->move(convertVector2(offset));
}


////////////////////////////////////////////////////////////
void sfSprite_rotate(sfSprite* sprite, float angle)
{
    assert(sprite);
    sprite->rotate(sf::degrees(angle));
}


////////////////////////////////////////////////////////////
void sfSprite_scale(sfSprite* sprite, sfVector2f factors)
{
    assert(sprite);
    sprite->scale(convertVector2(factors));
}


////////////////////////////////////////////////////////////
sfTransform sfSprite_getTransform(const sfSprite* sprite)
{
    assert(sprite);
    sprite->Transform = convertTransform(sprite->getTransform());
    return sprite->Transform;
}


////////////////////////////////////////////////////////////
sfTransform sfSprite_getInverseTransform(const sfSprite* sprite)
{
    assert(sprite);
    sprite->InverseTransform = convertTransform(sprite->getInverseTransform());
    return sprite->InverseTransform;
}


////////////////////////////////////////////////////////////
void sfSprite_setTexture(sfSprite* sprite, const sfTexture* texture, bool resetRect)
{
    if (texture && texture->This)
    {
        assert(sprite);
        sprite->setTexture(*texture->This, resetRect);
        sprite->Texture = texture;
    }
}


////////////////////////////////////////////////////////////
void sfSprite_setTextureRect(sfSprite* sprite, sfIntRect rectangle)
{
    assert(sprite);
    sprite->setTextureRect(convertRect(rectangle));
}


////////////////////////////////////////////////////////////
void sfSprite_setColor(sfSprite* sprite, sfColor color)
{
    assert(sprite);
    sprite->setColor(convertColor(color));
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
    return convertRect(sprite->getTextureRect());
}


////////////////////////////////////////////////////////////
sfColor sfSprite_getColor(const sfSprite* sprite)
{
    assert(sprite);
    return convertColor(sprite->getColor());
}


////////////////////////////////////////////////////////////
sfFloatRect sfSprite_getLocalBounds(const sfSprite* sprite)
{
    assert(sprite);
    return convertRect(sprite->getLocalBounds());
}


////////////////////////////////////////////////////////////
sfFloatRect sfSprite_getGlobalBounds(const sfSprite* sprite)
{
    assert(sprite);
    return convertRect(sprite->getGlobalBounds());
}
