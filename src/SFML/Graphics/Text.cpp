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
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/TextStruct.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfText* sfText_Create(void)
{
    sfText* text = new sfText;
    text->Font = sfFont_GetDefaultFont();

    return text;
}


////////////////////////////////////////////////////////////
sfText* sfText_Copy(sfText* text)
{
    CSFML_CHECK_RETURN(text, NULL);

    return new sfText(*text);
}


////////////////////////////////////////////////////////////
void sfText_Destroy(sfText* text)
{
    delete text;
}


////////////////////////////////////////////////////////////
void sfText_SetPosition(sfText* text, float x, float y)
{
    CSFML_CALL(text, SetPosition(x, y));
}


////////////////////////////////////////////////////////////
void sfText_SetRotation(sfText* text, float angle)
{
    CSFML_CALL(text, SetRotation(angle));
}


////////////////////////////////////////////////////////////
void sfText_SetScale(sfText* text, float factorX, float factorY)
{
    CSFML_CALL(text, SetScale(factorX, factorY));
}


////////////////////////////////////////////////////////////
void sfText_SetOrigin(sfText* text, float x, float y)
{
    CSFML_CALL(text, SetOrigin(x, y));
}


////////////////////////////////////////////////////////////
void sfText_GetPosition(const sfText* text, float* x, float* y)
{
    CSFML_CHECK(text);

    sf::Vector2f point = text->This.GetPosition();

    if (x)
        *x = point.x;
    if (y)
        *y = point.y;
}


////////////////////////////////////////////////////////////
float sfText_GetRotation(const sfText* text)
{
    CSFML_CALL_RETURN(text, GetRotation(), 0.f);
}


////////////////////////////////////////////////////////////
void sfText_GetScale(const sfText* text, float* x, float* y)
{
    CSFML_CHECK(text);

    sf::Vector2f point = text->This.GetScale();

    if (x)
        *x = point.x;
    if (y)
        *y = point.y;
}


////////////////////////////////////////////////////////////
void sfText_GetOrigin(const sfText* text, float* x, float* y)
{
    CSFML_CHECK(text);

    sf::Vector2f point = text->This.GetOrigin();

    if (x)
        *x = point.x;
    if (y)
        *y = point.y;
}


////////////////////////////////////////////////////////////
void sfText_Move(sfText* text, float offsetX, float offsetY)
{
    CSFML_CALL(text, Move(offsetX, offsetY));
}


////////////////////////////////////////////////////////////
void sfText_Rotate(sfText* text, float angle)
{
    CSFML_CALL(text, Rotate(angle));
}


////////////////////////////////////////////////////////////
void sfText_Scale(sfText* text, float factorX, float factorY)
{
    CSFML_CALL(text, Scale(factorX, factorY));
}


////////////////////////////////////////////////////////////
const sfTransform* sfText_GetTransform(const sfText* text)
{
    CSFML_CHECK_RETURN(text, NULL);

    text->Transform.This = text->This.GetTransform();
    return &text->Transform;
}


////////////////////////////////////////////////////////////
const sfTransform* sfText_GetInverseTransform(const sfText* text)
{
    CSFML_CHECK_RETURN(text, NULL);

    text->InverseTransform.This = text->This.GetInverseTransform();
    return &text->InverseTransform;
}


////////////////////////////////////////////////////////////
void sfText_SetString(sfText* text, const char* string)
{
    CSFML_CALL(text, SetString(string));
}


////////////////////////////////////////////////////////////
void sfText_SetUnicodeString(sfText* text, const sfUint32* string)
{
    sf::String UTF32Text = string;
    CSFML_CALL(text, SetString(UTF32Text));
}


////////////////////////////////////////////////////////////
void sfText_SetFont(sfText* text, const sfFont* font)
{
    CSFML_CHECK(font);

    CSFML_CALL(text, SetFont(font->This));
    text->Font = font;
}


////////////////////////////////////////////////////////////
void sfText_SetCharacterSize(sfText* text, unsigned int size)
{
    CSFML_CALL(text, SetCharacterSize(size));
}


////////////////////////////////////////////////////////////
void sfText_SetStyle(sfText* text, sfUint32 style)
{
    CSFML_CALL(text, SetStyle(style));
}


////////////////////////////////////////////////////////////
const char* sfText_GetString(const sfText* text)
{
    CSFML_CHECK_RETURN(text, NULL);

    text->String = text->This.GetString().ToAnsiString();

    return text->String.c_str();
}


////////////////////////////////////////////////////////////
const sfUint32* sfText_GetUnicodeString(const sfText* text)
{
    CSFML_CHECK_RETURN(text, NULL);

    return text->This.GetString().GetData();
}


////////////////////////////////////////////////////////////
const sfFont* sfText_GetFont(const sfText* text)
{
    CSFML_CHECK_RETURN(text, NULL);

    return text->Font;
}


////////////////////////////////////////////////////////////
unsigned int sfText_GetCharacterSize(const sfText* text)
{
    CSFML_CALL_RETURN(text, GetCharacterSize(), 0);
}


////////////////////////////////////////////////////////////
sfUint32 sfText_GetStyle(const sfText* text)
{
    CSFML_CALL_RETURN(text, GetStyle(), 0);
}


////////////////////////////////////////////////////////////
void sfText_FindCharacterPos(const sfText* text, size_t index, float* x, float* y)
{
    CSFML_CHECK(text);

    sf::Vector2f pos = text->This.FindCharacterPos(index);
    if (x)
        *x = pos.x;
    if (y)
        *y = pos.y;
}


////////////////////////////////////////////////////////////
sfFloatRect sfText_GetLocalBounds(const sfText* text)
{
    sfFloatRect rect = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(text, rect);

    sf::FloatRect sfmlRect = text->This.GetLocalBounds();
    rect.Left = sfmlRect.Left;
    rect.Top = sfmlRect.Top;
    rect.Width = sfmlRect.Width;
    rect.Height = sfmlRect.Height;

    return rect;
}


////////////////////////////////////////////////////////////
sfFloatRect sfText_GetGlobalBounds(const sfText* text)
{
    sfFloatRect rect = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(text, rect);

    sf::FloatRect sfmlRect = text->This.GetGlobalBounds();
    rect.Left = sfmlRect.Left;
    rect.Top = sfmlRect.Top;
    rect.Width = sfmlRect.Width;
    rect.Height = sfmlRect.Height;

    return rect;
}
