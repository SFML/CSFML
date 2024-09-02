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
#include <CSFML/CallbackStream.hpp>
#include <CSFML/Graphics/ConvertColor.hpp>
#include <CSFML/Graphics/ConvertRect.hpp>
#include <CSFML/Graphics/Image.h>
#include <CSFML/Graphics/ImageStruct.hpp>
#include <CSFML/System/BufferStruct.hpp>
#include <CSFML/System/ConvertVector2.hpp>


////////////////////////////////////////////////////////////
sfImage* sfImage_create(sfVector2u size)
{
    return new sfImage{sf::Image(convertVector2(size))};
}


////////////////////////////////////////////////////////////
sfImage* sfImage_createFromColor(sfVector2u size, sfColor color)
{
    return new sfImage{sf::Image(convertVector2(size), convertColor(color))};
}


////////////////////////////////////////////////////////////
sfImage* sfImage_createFromPixels(sfVector2u size, const uint8_t* data)
{
    return new sfImage{sf::Image(convertVector2(size), data)};
}


////////////////////////////////////////////////////////////
sfImage* sfImage_createFromFile(const char* filename)
{
    sf::Image image;
    if (!image.loadFromFile(filename))
        return nullptr;

    return new sfImage{std::move(image)};
}


////////////////////////////////////////////////////////////
sfImage* sfImage_createFromMemory(const void* data, size_t sizeInBytes)
{
    sf::Image image;
    if (!image.loadFromMemory(data, sizeInBytes))
        return nullptr;

    return new sfImage{std::move(image)};
}


////////////////////////////////////////////////////////////
sfImage* sfImage_createFromStream(sfInputStream* stream)
{
    assert(stream);

    CallbackStream sfmlStream(stream);
    sf::Image      image;
    if (!image.loadFromStream(sfmlStream))
        return nullptr;

    return new sfImage{std::move(image)};
}


////////////////////////////////////////////////////////////
sfImage* sfImage_copy(const sfImage* image)
{
    assert(image);
    return new sfImage(*image);
}


////////////////////////////////////////////////////////////
void sfImage_destroy(sfImage* image)
{
    delete image;
}


////////////////////////////////////////////////////////////
bool sfImage_saveToFile(const sfImage* image, const char* filename)
{
    assert(image);
    return image->This.saveToFile(filename);
}


////////////////////////////////////////////////////////////
bool sfImage_saveToMemory(const sfImage* image, sfBuffer* output, const char* format)
{
    assert(image);
    assert(output);

    auto data = image->This.saveToMemory(format);

    if (data)
    {
        output->buffer = std::move(*data);
        return true;
    }

    return false;
}


////////////////////////////////////////////////////////////
void sfImage_createMaskFromColor(sfImage* image, sfColor colorKey, uint8_t alpha)
{
    assert(image);
    image->This.createMaskFromColor(convertColor(colorKey), alpha);
}


////////////////////////////////////////////////////////////
bool sfImage_copyImage(sfImage* image, const sfImage* source, sfVector2u dest, sfIntRect sourceRect, bool applyAlpha)
{
    assert(image);
    assert(source);
    return image->This.copy(source->This, convertVector2(dest), convertRect(sourceRect), applyAlpha);
}


////////////////////////////////////////////////////////////
void sfImage_setPixel(sfImage* image, sfVector2u coords, sfColor color)
{
    assert(image);
    image->This.setPixel(convertVector2(coords), convertColor(color));
}


////////////////////////////////////////////////////////////
sfColor sfImage_getPixel(const sfImage* image, sfVector2u coords)
{
    assert(image);
    return convertColor(image->This.getPixel(convertVector2(coords)));
}


////////////////////////////////////////////////////////////
const uint8_t* sfImage_getPixelsPtr(const sfImage* image)
{
    assert(image);
    return image->This.getPixelsPtr();
}


////////////////////////////////////////////////////////////
sfVector2u sfImage_getSize(const sfImage* image)
{
    assert(image);
    return convertVector2(image->This.getSize());
}


////////////////////////////////////////////////////////////
void sfImage_flipHorizontally(sfImage* image)
{
    assert(image);
    image->This.flipHorizontally();
}


////////////////////////////////////////////////////////////
void sfImage_flipVertically(sfImage* image)
{
    assert(image);
    image->This.flipVertically();
}
