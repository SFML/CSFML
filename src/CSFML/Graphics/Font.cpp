////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2026 Laurent Gomila (laurent@sfml-dev.org)
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
#include <CSFML/CallbackStream.hpp>
#include <CSFML/Graphics/ConvertGlyph.hpp>
#include <CSFML/Graphics/Font.h>
#include <CSFML/Graphics/FontStruct.hpp>


////////////////////////////////////////////////////////////
sfFont* sfFont_createFromFile(const char* filename)
{
    assert(filename);

    auto font = std::make_unique<sfFont>();
    if (!font->openFromFile(filename))
        return nullptr;

    return font.release();
}


////////////////////////////////////////////////////////////
sfFont* sfFont_createFromMemory(const void* data, size_t sizeInBytes)
{
    auto font = std::make_unique<sfFont>();
    if (!font->openFromMemory(data, sizeInBytes))
        return nullptr;

    return font.release();
}


////////////////////////////////////////////////////////////
sfFont* sfFont_createFromStream(sfInputStream* stream)
{
    assert(stream);

    auto font = std::make_unique<sfFont>(sfFont{{}, {}, {stream}});
    if (!font->openFromStream(font->Stream))
        return nullptr;

    return font.release();
}


////////////////////////////////////////////////////////////
sfFont* sfFont_copy(const sfFont* font)
{
    assert(font);
    return new sfFont(*font);
}


////////////////////////////////////////////////////////////
void sfFont_destroy(const sfFont* font)
{
    delete font;
}


////////////////////////////////////////////////////////////
sfGlyph sfFont_getGlyph(const sfFont* font, uint32_t codePoint, unsigned int characterSize, bool bold, float outlineThickness)
{
    assert(font);

    return convertGlyph(font->getGlyph(codePoint, characterSize, bold, outlineThickness));
}


////////////////////////////////////////////////////////////
sfGlyph sfFont_getGlyphById(const sfFont* font, uint32_t id, unsigned int characterSize, bool bold, float outlineThickness)
{
    assert(font);
    return convertGlyph(font->getGlyphById(id, characterSize, bold, outlineThickness));
}


////////////////////////////////////////////////////////////
bool sfFont_hasGlyph(const sfFont* font, uint32_t codePoint)
{
    assert(font);
    return font->hasGlyph(codePoint);
}


////////////////////////////////////////////////////////////
float sfFont_getKerning(const sfFont* font, uint32_t first, uint32_t second, unsigned int characterSize)
{
    assert(font);
    return font->getKerning(char32_t{first}, char32_t{second}, characterSize);
}


////////////////////////////////////////////////////////////
float sfFont_getBoldKerning(const sfFont* font, uint32_t first, uint32_t second, unsigned int characterSize)
{
    assert(font);
    return font->getKerning(char32_t{first}, char32_t{second}, characterSize, true);
}


////////////////////////////////////////////////////////////
float sfFont_getLineSpacing(const sfFont* font, unsigned int characterSize)
{
    assert(font);
    return font->getLineSpacing(characterSize);
}


////////////////////////////////////////////////////////////
float sfFont_getAscent(const sfFont* font, unsigned int characterSize)
{
    assert(font);
    return font->getAscent(characterSize);
}


////////////////////////////////////////////////////////////
float sfFont_getDescent(const sfFont* font, unsigned int characterSize)
{
    assert(font);
    return font->getDescent(characterSize);
}


////////////////////////////////////////////////////////////
float sfFont_getUnderlinePosition(const sfFont* font, unsigned int characterSize)
{
    assert(font);
    return font->getUnderlinePosition(characterSize);
}


////////////////////////////////////////////////////////////
float sfFont_getUnderlineThickness(const sfFont* font, unsigned int characterSize)
{
    assert(font);
    return font->getUnderlineThickness(characterSize);
}


////////////////////////////////////////////////////////////
const sfTexture* sfFont_getTexture(sfFont* font, unsigned int characterSize)
{
    assert(font);

    *font->Textures[characterSize].This = font->getTexture(characterSize);

    return &font->Textures[characterSize];
}


////////////////////////////////////////////////////////////
void sfFont_setSmooth(sfFont* font, bool smooth)
{
    assert(font);
    font->setSmooth(smooth);
}


////////////////////////////////////////////////////////////
bool sfFont_isSmooth(const sfFont* font)
{
    assert(font);
    return font->isSmooth();
}


////////////////////////////////////////////////////////////
sfFontInfo sfFont_getInfo(const sfFont* font)
{
    assert(font);
    const sf::Font::Info& info = font->getInfo();
    return {info.id, info.family.c_str(), info.hasKerning, info.hasVerticalMetrics};
}
