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
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/FontStruct.h>
#include <SFML/Internal.h>
#include <SFML/CallbackStream.h>


////////////////////////////////////////////////////////////
sfFont* sfFont_createFromFile(const char* filename)
{
    sfFont* font = new sfFont;
    if (!font->This.loadFromFile(filename))
    {
        delete font;
        font = nullptr;
    }

    return font;
}


////////////////////////////////////////////////////////////
sfFont* sfFont_createFromMemory(const void* data, size_t sizeInBytes)
{
    sfFont* font = new sfFont;
    if (!font->This.loadFromMemory(data, sizeInBytes))
    {
        delete font;
        font = nullptr;
    }

    return font;
}


////////////////////////////////////////////////////////////
sfFont* sfFont_createFromStream(sfInputStream* stream)
{
    CSFML_CHECK_RETURN(stream, nullptr);

    sfFont* font = new sfFont;
    font->Stream = CallbackStream(stream);
    if (!font->This.loadFromStream(font->Stream))
    {
        delete font;
        font = nullptr;
    }

    return font;
}


////////////////////////////////////////////////////////////
sfFont* sfFont_copy(const sfFont* font)
{
    CSFML_CHECK_RETURN(font, nullptr);

    return new sfFont(*font);
}


////////////////////////////////////////////////////////////
void sfFont_destroy(sfFont* font)
{
    delete font;
}


////////////////////////////////////////////////////////////
sfGlyph sfFont_getGlyph(const sfFont* font, uint32_t codePoint, unsigned int characterSize, bool bold, float outlineThickness)
{
    sfGlyph glyph = {0, {0, 0, 0, 0}, {0, 0, 0, 0}};
    CSFML_CHECK_RETURN(font, glyph);

    sf::Glyph SFMLGlyph = font->This.getGlyph(codePoint, characterSize, bold, outlineThickness);

    glyph.advance            = SFMLGlyph.advance;
    glyph.bounds.left        = SFMLGlyph.bounds.left;
    glyph.bounds.top         = SFMLGlyph.bounds.top;
    glyph.bounds.width       = SFMLGlyph.bounds.width;
    glyph.bounds.height      = SFMLGlyph.bounds.height;
    glyph.textureRect.left   = SFMLGlyph.textureRect.left;
    glyph.textureRect.top    = SFMLGlyph.textureRect.top;
    glyph.textureRect.width  = SFMLGlyph.textureRect.width;
    glyph.textureRect.height = SFMLGlyph.textureRect.height;

    return glyph;
}


////////////////////////////////////////////////////////////
bool sfFont_hasGlyph(const sfFont* font, uint32_t codePoint)
{
    CSFML_CALL_RETURN(font, hasGlyph(codePoint), false);
}


////////////////////////////////////////////////////////////
float sfFont_getKerning(const sfFont* font, uint32_t first, uint32_t second, unsigned int characterSize)
{
    CSFML_CALL_RETURN(font, getKerning(first, second, characterSize), 0);
}


////////////////////////////////////////////////////////////
float sfFont_getBoldKerning(const sfFont* font, uint32_t first, uint32_t second, unsigned int characterSize)
{
    CSFML_CALL_RETURN(font, getKerning(first, second, characterSize, true), 0);
}


////////////////////////////////////////////////////////////
float sfFont_getLineSpacing(const sfFont* font, unsigned int characterSize)
{
    CSFML_CALL_RETURN(font, getLineSpacing(characterSize), 0);
}


////////////////////////////////////////////////////////////
float sfFont_getUnderlinePosition(const sfFont* font, unsigned int characterSize)
{
    CSFML_CALL_RETURN(font, getUnderlinePosition(characterSize), 0)
}


////////////////////////////////////////////////////////////
float sfFont_getUnderlineThickness(const sfFont* font, unsigned int characterSize)
{
    CSFML_CALL_RETURN(font, getUnderlineThickness(characterSize), 0)
}


////////////////////////////////////////////////////////////
const sfTexture* sfFont_getTexture(sfFont* font, unsigned int characterSize)
{
    CSFML_CHECK_RETURN(font, nullptr);

    *font->Textures[characterSize].This = font->This.getTexture(characterSize);

    return &font->Textures[characterSize];
}


////////////////////////////////////////////////////////////
void sfFont_setSmooth(sfFont* font, bool smooth)
{
    font->This.setSmooth(smooth);
}


////////////////////////////////////////////////////////////
bool sfFont_isSmooth(const sfFont *font)
{
    return font->This.isSmooth();
}


////////////////////////////////////////////////////////////
sfFontInfo sfFont_getInfo(const sfFont* font)
{
    sfFontInfo info = {nullptr};
    CSFML_CHECK_RETURN(font, info);

    info.family = font->This.getInfo().family.c_str();

    return info;
}
