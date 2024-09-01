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
#include <CSFML/Graphics/ConvertColor.hpp>
#include <CSFML/Graphics/ConvertRect.hpp>
#include <CSFML/Graphics/ConvertTransform.hpp>
#include <CSFML/Graphics/Sprite.h>
#include <CSFML/Graphics/SpriteStruct.hpp>
#include <CSFML/Internal.hpp>
#include <CSFML/System/ConvertVector2.hpp>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>


////////////////////////////////////////////////////////////
sfSprite* sfSprite_create(const sfTexture* texture)
{
    CSFML_CHECK_RETURN(texture, nullptr);
    CSFML_CHECK_RETURN(texture->This, nullptr);

    return new sfSprite{sf::Sprite{*texture->This}, texture, {}, {}};
}


////////////////////////////////////////////////////////////
sfSprite* sfSprite_copy(const sfSprite* sprite)
{
    CSFML_CHECK_RETURN(sprite, nullptr);

    return new sfSprite(*sprite);
}


////////////////////////////////////////////////////////////
void sfSprite_destroy(sfSprite* sprite)
{
    delete sprite;
}


////////////////////////////////////////////////////////////
void sfSprite_setPosition(sfSprite* sprite, sfVector2f position)
{
    CSFML_CALL(sprite, setPosition(convertVector2(position)));
}


////////////////////////////////////////////////////////////
void sfSprite_setRotation(sfSprite* sprite, float angle)
{
    CSFML_CALL(sprite, setRotation(sf::degrees(angle)));
}


////////////////////////////////////////////////////////////
void sfSprite_setScale(sfSprite* sprite, sfVector2f scale)
{
    CSFML_CALL(sprite, setScale(convertVector2(scale)));
}


////////////////////////////////////////////////////////////
void sfSprite_setOrigin(sfSprite* sprite, sfVector2f origin)
{
    CSFML_CALL(sprite, setOrigin(convertVector2(origin)));
}


////////////////////////////////////////////////////////////
sfVector2f sfSprite_getPosition(const sfSprite* sprite)
{
    CSFML_CHECK_RETURN(sprite, {});

    return convertVector2(sprite->This.getPosition());
}


////////////////////////////////////////////////////////////
float sfSprite_getRotation(const sfSprite* sprite)
{
    CSFML_CALL_RETURN(sprite, getRotation().asDegrees(), 0.f);
}


////////////////////////////////////////////////////////////
sfVector2f sfSprite_getScale(const sfSprite* sprite)
{
    CSFML_CHECK_RETURN(sprite, {});

    return convertVector2(sprite->This.getScale());
}


////////////////////////////////////////////////////////////
sfVector2f sfSprite_getOrigin(const sfSprite* sprite)
{
    CSFML_CHECK_RETURN(sprite, {});

    return convertVector2(sprite->This.getOrigin());
}


////////////////////////////////////////////////////////////
void sfSprite_move(sfSprite* sprite, sfVector2f offset)
{
    CSFML_CALL(sprite, move(convertVector2(offset)));
}


////////////////////////////////////////////////////////////
void sfSprite_rotate(sfSprite* sprite, float angle)
{
    CSFML_CALL(sprite, rotate(sf::degrees(angle)));
}


////////////////////////////////////////////////////////////
void sfSprite_scale(sfSprite* sprite, sfVector2f factors)
{
    CSFML_CALL(sprite, scale(convertVector2(factors)));
}


////////////////////////////////////////////////////////////
sfTransform sfSprite_getTransform(const sfSprite* sprite)
{
    CSFML_CHECK_RETURN(sprite, sfTransform_Identity);

    sprite->Transform = convertTransform(sprite->This.getTransform());
    return sprite->Transform;
}


////////////////////////////////////////////////////////////
sfTransform sfSprite_getInverseTransform(const sfSprite* sprite)
{
    CSFML_CHECK_RETURN(sprite, sfTransform_Identity);

    sprite->InverseTransform = convertTransform(sprite->This.getInverseTransform());
    return sprite->InverseTransform;
}


////////////////////////////////////////////////////////////
void sfSprite_setTexture(sfSprite* sprite, const sfTexture* texture, bool resetRect)
{
    if (texture && texture->This)
    {
        CSFML_CALL(sprite, setTexture(*texture->This, resetRect));
        sprite->Texture = texture;
    }
}


////////////////////////////////////////////////////////////
void sfSprite_setTextureRect(sfSprite* sprite, sfIntRect rectangle)
{
    CSFML_CALL(sprite, setTextureRect(convertRect(rectangle)));
}


////////////////////////////////////////////////////////////
void sfSprite_setColor(sfSprite* sprite, sfColor color)
{
    CSFML_CALL(sprite, setColor(convertColor(color)));
}


////////////////////////////////////////////////////////////
const sfTexture* sfSprite_getTexture(const sfSprite* sprite)
{
    CSFML_CHECK_RETURN(sprite, nullptr);

    return sprite->Texture;
}


////////////////////////////////////////////////////////////
sfIntRect sfSprite_getTextureRect(const sfSprite* sprite)
{
    CSFML_CHECK_RETURN(sprite, {});

    return convertRect(sprite->This.getTextureRect());
}


////////////////////////////////////////////////////////////
sfColor sfSprite_getColor(const sfSprite* sprite)
{
    CSFML_CHECK_RETURN(sprite, {});

    return convertColor(sprite->This.getColor());
}


////////////////////////////////////////////////////////////
sfFloatRect sfSprite_getLocalBounds(const sfSprite* sprite)
{
    CSFML_CHECK_RETURN(sprite, {});

    return convertRect(sprite->This.getLocalBounds());
}


////////////////////////////////////////////////////////////
sfFloatRect sfSprite_getGlobalBounds(const sfSprite* sprite)
{
    CSFML_CHECK_RETURN(sprite, {});

    return convertRect(sprite->This.getGlobalBounds());
}
