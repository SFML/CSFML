////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2013 Laurent Gomila (laurent.gom@gmail.com)
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
/// Create a new font from a file
////////////////////////////////////////////////////////////
sfFont* sfFont_createFromFile(const char* filename)
{
    sfFont* font = new sfFont;
    if (!font->This.loadFromFile(filename))
    {
        delete font;
        font = NULL;
    }

    return font;
}


////////////////////////////////////////////////////////////
/// Create a new font from a file in memory
////////////////////////////////////////////////////////////
sfFont* sfFont_createFromMemory(const void* data, size_t sizeInBytes)
{
    sfFont* font = new sfFont;
    if (!font->This.loadFromMemory(data, sizeInBytes))
    {
        delete font;
        font = NULL;
    }

    return font;
}


////////////////////////////////////////////////////////////
/// Create a new font from a custom stream
////////////////////////////////////////////////////////////
sfFont* sfFont_createFromStream(sfInputStream* stream)
{
    CSFML_CHECK_RETURN(stream, NULL);

    sfFont* font = new sfFont;
    font->Stream = CallbackStream(stream);
    if (!font->This.loadFromStream(font->Stream))
    {
        delete font;
        font = NULL;
    }

    return font;
}


////////////////////////////////////////////////////////////
/// Copy an existing font
////////////////////////////////////////////////////////////
sfFont* sfFont_copy(const sfFont* font)
{
    CSFML_CHECK_RETURN(font, NULL);

    return new sfFont(*font);
}


////////////////////////////////////////////////////////////
/// Destroy an existing font
////////////////////////////////////////////////////////////
void sfFont_destroy(sfFont* font)
{
    delete font;
}


////////////////////////////////////////////////////////////
/// Get a glyph in a font
////////////////////////////////////////////////////////////
sfGlyph sfFont_getGlyph(sfFont* font, sfUint32 codePoint, unsigned int characterSize, sfBool bold)
{
    sfGlyph glyph = {0, {0, 0, 0, 0}, {0, 0, 0, 0}};
    CSFML_CHECK_RETURN(font, glyph);

    sf::Glyph SFMLGlyph = font->This.getGlyph(codePoint, characterSize, bold == sfTrue);

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
/// Get the kerning value corresponding to a given pair of characters in a font
////////////////////////////////////////////////////////////
float sfFont_getKerning(sfFont* font, sfUint32 first, sfUint32 second, unsigned int characterSize)
{
    CSFML_CALL_RETURN(font, getKerning(first, second, characterSize), 0);
}


////////////////////////////////////////////////////////////
/// Get the line spacing value
////////////////////////////////////////////////////////////
float sfFont_getLineSpacing(sfFont* font, unsigned int characterSize)
{
    CSFML_CALL_RETURN(font, getLineSpacing(characterSize), 0);
}


////////////////////////////////////////////////////////////
/// Get the texture containing the glyphs of a given size in a font
////////////////////////////////////////////////////////////
const sfTexture* sfFont_getTexture(sfFont* font, unsigned int characterSize)
{
    CSFML_CHECK_RETURN(font, NULL);

    *font->Textures[characterSize].This = font->This.getTexture(characterSize);

    return &font->Textures[characterSize];
}
