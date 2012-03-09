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
void sfText_SetPosition(sfText* text, sfVector2f position)
{
    CSFML_CALL(text, SetPosition(position.x, position.y));
}


////////////////////////////////////////////////////////////
void sfText_SetRotation(sfText* text, float angle)
{
    CSFML_CALL(text, SetRotation(angle));
}


////////////////////////////////////////////////////////////
void sfText_SetScale(sfText* text, sfVector2f scale)
{
    CSFML_CALL(text, SetScale(scale.x, scale.y));
}


////////////////////////////////////////////////////////////
void sfText_SetOrigin(sfText* text, sfVector2f origin)
{
    CSFML_CALL(text, SetOrigin(origin.x, origin.y));
}


////////////////////////////////////////////////////////////
sfVector2f sfText_GetPosition(const sfText* text)
{
    sfVector2f position = {0, 0};
    CSFML_CHECK_RETURN(text, position);

    sf::Vector2f sfmlPos = text->This.GetPosition();
    position.x = sfmlPos.x;
    position.y = sfmlPos.y;

    return position;
}


////////////////////////////////////////////////////////////
float sfText_GetRotation(const sfText* text)
{
    CSFML_CALL_RETURN(text, GetRotation(), 0.f);
}


////////////////////////////////////////////////////////////
sfVector2f sfText_GetScale(const sfText* text)
{
    sfVector2f scale = {0, 0};
    CSFML_CHECK_RETURN(text, scale);

    sf::Vector2f sfmlScale = text->This.GetScale();
    scale.x = sfmlScale.x;
    scale.y = sfmlScale.y;

    return scale;
}


////////////////////////////////////////////////////////////
sfVector2f sfText_GetOrigin(const sfText* text)
{
    sfVector2f origin = {0, 0};
    CSFML_CHECK_RETURN(text, origin);

    sf::Vector2f sfmlOrigin = text->This.GetOrigin();
    origin.x = sfmlOrigin.x;
    origin.y = sfmlOrigin.y;

    return origin;
}


////////////////////////////////////////////////////////////
void sfText_Move(sfText* text, sfVector2f offset)
{
    CSFML_CALL(text, Move(offset.x, offset.y));
}


////////////////////////////////////////////////////////////
void sfText_Rotate(sfText* text, float angle)
{
    CSFML_CALL(text, Rotate(angle));
}


////////////////////////////////////////////////////////////
void sfText_Scale(sfText* text, sfVector2f factors)
{
    CSFML_CALL(text, Scale(factors.x, factors.y));
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
void sfText_SetColor(sfText* text, sfColor color)
{
    CSFML_CALL(text, SetColor(sf::Color(color.r, color.g, color.b, color.a)));
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
sfColor sfText_GetColor(const sfText* text)
{
    sfColor color = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(text, color);

    sf::Color sfmlColor = text->This.GetColor();
    color.r = sfmlColor.r;
    color.g = sfmlColor.g;
    color.b = sfmlColor.b;
    color.a = sfmlColor.a;

    return color;
}


////////////////////////////////////////////////////////////
sfVector2f sfText_FindCharacterPos(const sfText* text, size_t index)
{
    sfVector2f position = {0, 0};
    CSFML_CHECK_RETURN(text, position);

    sf::Vector2f sfmlPos = text->This.FindCharacterPos(index);
    position.x = sfmlPos.x;
    position.y = sfmlPos.y;

    return position;
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
