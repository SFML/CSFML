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
#include <CSFML/Graphics/Font.h>
#include <CSFML/Graphics/Text.h>
#include <CSFML/Graphics/TextStruct.hpp>
#include <CSFML/System/ConvertVector2.hpp>

#include <SFML/Graphics/Color.hpp>


////////////////////////////////////////////////////////////
sfText* sfText_create(const sfFont* font)
{
    assert(font);
    auto text  = new sfText(*font);
    text->Font = font;
    return text;
}


////////////////////////////////////////////////////////////
sfText* sfText_copy(const sfText* text)
{
    assert(text);
    return new sfText(*text);
}


////////////////////////////////////////////////////////////
void sfText_destroy(const sfText* text)
{
    delete text;
}


////////////////////////////////////////////////////////////
void sfText_setPosition(sfText* text, sfVector2f position)
{
    assert(text);
    text->setPosition(convertVector2(position));
}


////////////////////////////////////////////////////////////
void sfText_setRotation(sfText* text, float angle)
{
    assert(text);
    text->setRotation(sf::degrees(angle));
}


////////////////////////////////////////////////////////////
void sfText_setScale(sfText* text, sfVector2f scale)
{
    assert(text);
    text->setScale(convertVector2(scale));
}


////////////////////////////////////////////////////////////
void sfText_setOrigin(sfText* text, sfVector2f origin)
{
    assert(text);
    text->setOrigin(convertVector2(origin));
}


////////////////////////////////////////////////////////////
sfVector2f sfText_getPosition(const sfText* text)
{
    assert(text);
    return convertVector2(text->getPosition());
}


////////////////////////////////////////////////////////////
float sfText_getRotation(const sfText* text)
{
    assert(text);
    return text->getRotation().asDegrees();
}


////////////////////////////////////////////////////////////
sfVector2f sfText_getScale(const sfText* text)
{
    assert(text);
    return convertVector2(text->getScale());
}


////////////////////////////////////////////////////////////
sfVector2f sfText_getOrigin(const sfText* text)
{
    assert(text);
    return convertVector2(text->getOrigin());
}


////////////////////////////////////////////////////////////
void sfText_move(sfText* text, sfVector2f offset)
{
    assert(text);
    text->move(convertVector2(offset));
}


////////////////////////////////////////////////////////////
void sfText_rotate(sfText* text, float angle)
{
    assert(text);
    text->rotate(sf::degrees(angle));
}


////////////////////////////////////////////////////////////
void sfText_scale(sfText* text, sfVector2f factors)
{
    assert(text);
    text->scale(convertVector2(factors));
}


////////////////////////////////////////////////////////////
sfTransform sfText_getTransform(const sfText* text)
{
    assert(text);
    text->Transform = convertTransform(text->getTransform());
    return text->Transform;
}


////////////////////////////////////////////////////////////
sfTransform sfText_getInverseTransform(const sfText* text)
{
    assert(text);
    text->InverseTransform = convertTransform(text->getInverseTransform());
    return text->InverseTransform;
}


////////////////////////////////////////////////////////////
void sfText_setString(sfText* text, const char* string)
{
    assert(text);
    text->setString(string);
}


////////////////////////////////////////////////////////////
void sfText_setUnicodeString(sfText* text, const sfChar32* string)
{
    assert(text);
    sf::String utf32Text = reinterpret_cast<const char32_t*>(string);
    text->setString(utf32Text);
}


////////////////////////////////////////////////////////////
void sfText_setFont(sfText* text, const sfFont* font)
{
    assert(text);
    assert(font);
    text->setFont(*font);
    text->Font = font;
}


////////////////////////////////////////////////////////////
void sfText_setCharacterSize(sfText* text, unsigned int size)
{
    assert(text);
    text->setCharacterSize(size);
}


////////////////////////////////////////////////////////////
void sfText_setLineSpacing(sfText* text, float spacingFactor)
{
    assert(text);
    text->setLineSpacing(spacingFactor);
}


////////////////////////////////////////////////////////////
void sfText_setLetterSpacing(sfText* text, float spacingFactor)
{
    assert(text);
    text->setLetterSpacing(spacingFactor);
}


////////////////////////////////////////////////////////////
void sfText_setStyle(sfText* text, uint32_t style)
{
    assert(text);
    text->setStyle(style);
}


////////////////////////////////////////////////////////////
void sfText_setFillColor(sfText* text, sfColor color)
{
    assert(text);
    text->setFillColor(convertColor(color));
}


////////////////////////////////////////////////////////////
void sfText_setOutlineColor(sfText* text, sfColor color)
{
    assert(text);
    text->setOutlineColor(convertColor(color));
}


////////////////////////////////////////////////////////////
void sfText_setOutlineThickness(sfText* text, float thickness)
{
    assert(text);
    text->setOutlineThickness(thickness);
}


////////////////////////////////////////////////////////////
const char* sfText_getString(const sfText* text)
{
    assert(text);

    text->String = text->getString().toAnsiString();

    return text->String.c_str();
}


////////////////////////////////////////////////////////////
const sfChar32* sfText_getUnicodeString(const sfText* text)
{
    assert(text);
    return reinterpret_cast<const sfChar32*>(text->getString().getData());
}


////////////////////////////////////////////////////////////
const sfFont* sfText_getFont(const sfText* text)
{
    assert(text);
    return text->Font;
}


////////////////////////////////////////////////////////////
unsigned int sfText_getCharacterSize(const sfText* text)
{
    assert(text);
    return text->getCharacterSize();
}


////////////////////////////////////////////////////////////
float sfText_getLetterSpacing(const sfText* text)
{
    assert(text);
    return text->getLetterSpacing();
}


////////////////////////////////////////////////////////////
float sfText_getLineSpacing(const sfText* text)
{
    assert(text);
    return text->getLineSpacing();
}


////////////////////////////////////////////////////////////
uint32_t sfText_getStyle(const sfText* text)
{
    assert(text);
    return text->getStyle();
}


////////////////////////////////////////////////////////////
sfColor sfText_getFillColor(const sfText* text)
{
    assert(text);
    return convertColor(text->getFillColor());
}


////////////////////////////////////////////////////////////
sfColor sfText_getOutlineColor(const sfText* text)
{
    assert(text);
    return convertColor(text->getOutlineColor());
}


////////////////////////////////////////////////////////////
float sfText_getOutlineThickness(const sfText* text)
{
    assert(text);
    return text->getOutlineThickness();
}


////////////////////////////////////////////////////////////
sfVector2f sfText_findCharacterPos(const sfText* text, size_t index)
{
    assert(text);
    return convertVector2(text->findCharacterPos(index));
}


////////////////////////////////////////////////////////////
sfFloatRect sfText_getLocalBounds(const sfText* text)
{
    assert(text);
    return convertRect(text->getLocalBounds());
}


////////////////////////////////////////////////////////////
sfFloatRect sfText_getGlobalBounds(const sfText* text)
{
    assert(text);
    return convertRect(text->getGlobalBounds());
}
