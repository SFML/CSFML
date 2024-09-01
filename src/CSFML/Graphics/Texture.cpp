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
#include <CSFML/Graphics/ConvertRect.hpp>
#include <CSFML/Graphics/ImageStruct.hpp>
#include <CSFML/Graphics/RenderWindowStruct.hpp>
#include <CSFML/Graphics/Texture.h>
#include <CSFML/Graphics/TextureStruct.hpp>
#include <CSFML/Internal.hpp>
#include <CSFML/System/ConvertVector2.hpp>
#include <CSFML/Window/WindowStruct.hpp>


////////////////////////////////////////////////////////////
sfTexture* sfTexture_create(sfVector2u size)
{
    sfTexture* texture = new sfTexture;

    if (!texture->This->resize(convertVector2(size)))
    {
        delete texture;
        texture = nullptr;
    }

    return texture;
}


////////////////////////////////////////////////////////////
sfTexture* sfTexture_createFromFile(const char* filename, const sfIntRect* area)
{
    sfTexture* texture = new sfTexture;

    const sf::IntRect rect = area ? convertRect(*area) : sf::IntRect();

    if (!texture->This->loadFromFile(filename, false, rect))
    {
        delete texture;
        texture = nullptr;
    }

    return texture;
}

////////////////////////////////////////////////////////////
sfTexture* sfTexture_createSrgbFromFile(const char* filename, const sfIntRect* area)
{
    sfTexture* texture = new sfTexture;

    const sf::IntRect rect = area ? convertRect(*area) : sf::IntRect();

    if (!texture->This->loadFromFile(filename, true, rect))
    {
        delete texture;
        texture = nullptr;
    }

    return texture;
}

////////////////////////////////////////////////////////////
sfTexture* sfTexture_createFromMemory(const void* data, size_t sizeInBytes, const sfIntRect* area)
{
    sfTexture* texture = new sfTexture;

    const sf::IntRect rect = area ? convertRect(*area) : sf::IntRect();

    if (!texture->This->loadFromMemory(data, sizeInBytes, false, rect))
    {
        delete texture;
        texture = nullptr;
    }

    return texture;
}

////////////////////////////////////////////////////////////
sfTexture* sfTexture_createSrgbFromMemory(const void* data, size_t sizeInBytes, const sfIntRect* area)
{
    sfTexture* texture = new sfTexture;

    const sf::IntRect rect = area ? convertRect(*area) : sf::IntRect();

    if (!texture->This->loadFromMemory(data, sizeInBytes, true, rect))
    {
        delete texture;
        texture = nullptr;
    }

    return texture;
}


////////////////////////////////////////////////////////////
sfTexture* sfTexture_createFromStream(sfInputStream* stream, const sfIntRect* area)
{
    CSFML_CHECK_RETURN(stream, nullptr);

    sfTexture* texture = new sfTexture;

    const sf::IntRect rect = area ? convertRect(*area) : sf::IntRect();

    CallbackStream sfmlStream(stream);
    if (!texture->This->loadFromStream(sfmlStream, false, rect))
    {
        delete texture;
        texture = nullptr;
    }

    return texture;
}

////////////////////////////////////////////////////////////
sfTexture* sfTexture_createSrgbFromStream(sfInputStream* stream, const sfIntRect* area)
{
    CSFML_CHECK_RETURN(stream, nullptr);

    sfTexture* texture = new sfTexture;

    const sf::IntRect rect = area ? convertRect(*area) : sf::IntRect();

    CallbackStream sfmlStream(stream);
    if (!texture->This->loadFromStream(sfmlStream, true, rect))
    {
        delete texture;
        texture = nullptr;
    }

    return texture;
}


////////////////////////////////////////////////////////////
sfTexture* sfTexture_createFromImage(const sfImage* image, const sfIntRect* area)
{
    CSFML_CHECK_RETURN(image, nullptr);

    sfTexture* texture = new sfTexture;

    const sf::IntRect rect = area ? convertRect(*area) : sf::IntRect();

    if (!texture->This->loadFromImage(image->This, false, rect))
    {
        delete texture;
        texture = nullptr;
    }

    return texture;
}

////////////////////////////////////////////////////////////
sfTexture* sfTexture_createSrgbFromImage(const sfImage* image, const sfIntRect* area)
{
    CSFML_CHECK_RETURN(image, nullptr);

    sfTexture* texture = new sfTexture;

    const sf::IntRect rect = area ? convertRect(*area) : sf::IntRect();

    if (!texture->This->loadFromImage(image->This, true, rect))
    {
        delete texture;
        texture = nullptr;
    }

    return texture;
}

////////////////////////////////////////////////////////////
sfTexture* sfTexture_copy(const sfTexture* texture)
{
    CSFML_CHECK_RETURN(texture, nullptr);

    return new sfTexture(*texture);
}


////////////////////////////////////////////////////////////
void sfTexture_destroy(sfTexture* texture)
{
    delete texture;
}


////////////////////////////////////////////////////////////
sfVector2u sfTexture_getSize(const sfTexture* texture)
{
    CSFML_CHECK_RETURN(texture, {});

    return convertVector2(texture->This->getSize());
}


////////////////////////////////////////////////////////////
sfImage* sfTexture_copyToImage(const sfTexture* texture)
{
    CSFML_CHECK_RETURN(texture, nullptr);
    CSFML_CHECK_RETURN(texture->This, nullptr);

    return new sfImage{texture->This->copyToImage()};
}


////////////////////////////////////////////////////////////
void sfTexture_updateFromPixels(sfTexture* texture, const uint8_t* pixels, sfVector2u size, sfVector2u offset)
{
    CSFML_CALL_PTR(texture, update(pixels, convertVector2(size), convertVector2(offset)));
}


////////////////////////////////////////////////////////////
void sfTexture_updateFromTexture(sfTexture* destination, const sfTexture* texture, sfVector2u offset)
{
    CSFML_CHECK(texture);
    CSFML_CHECK(texture->This);

    CSFML_CALL_PTR(destination, update(*texture->This, convertVector2(offset)));
}


////////////////////////////////////////////////////////////
void sfTexture_updateFromImage(sfTexture* texture, const sfImage* image, sfVector2u offset)
{
    CSFML_CHECK(image);

    CSFML_CALL_PTR(texture, update(image->This, convertVector2(offset)));
}


////////////////////////////////////////////////////////////
void sfTexture_updateFromWindow(sfTexture* texture, const sfWindow* window, sfVector2u offset)
{
    CSFML_CHECK(window);

    CSFML_CALL_PTR(texture, update(window->This, convertVector2(offset)));
}


////////////////////////////////////////////////////////////
void sfTexture_updateFromRenderWindow(sfTexture* texture, const sfRenderWindow* renderWindow, sfVector2u offset)
{
    CSFML_CHECK(renderWindow);

    CSFML_CALL_PTR(texture, update(renderWindow->This, convertVector2(offset)));
}


////////////////////////////////////////////////////////////
void sfTexture_setSmooth(sfTexture* texture, bool smooth)
{
    CSFML_CALL_PTR(texture, setSmooth(smooth));
}


////////////////////////////////////////////////////////////
bool sfTexture_isSmooth(const sfTexture* texture)
{
    CSFML_CHECK_RETURN(texture, false);
    CSFML_CHECK_RETURN(texture->This, false);

    return texture->This->isSmooth();
}

////////////////////////////////////////////////////////////
bool sfTexture_isSrgb(const sfTexture* texture)
{
    CSFML_CALL_PTR_RETURN(texture, isSrgb(), false);
}


////////////////////////////////////////////////////////////
void sfTexture_setRepeated(sfTexture* texture, bool repeated)
{
    CSFML_CALL_PTR(texture, setRepeated(repeated));
}


////////////////////////////////////////////////////////////
bool sfTexture_isRepeated(const sfTexture* texture)
{
    CSFML_CHECK_RETURN(texture, false);
    CSFML_CHECK_RETURN(texture->This, false);

    return texture->This->isRepeated();
}


////////////////////////////////////////////////////////////
bool sfTexture_generateMipmap(sfTexture* texture)
{
    CSFML_CALL_PTR_RETURN(texture, generateMipmap(), false);
}


////////////////////////////////////////////////////////////
void sfTexture_swap(sfTexture* left, sfTexture* right)
{
    CSFML_CHECK(right);

    CSFML_CALL_PTR(left, swap(*right->This));
}


////////////////////////////////////////////////////////////
unsigned int sfTexture_getNativeHandle(const sfTexture* texture)
{
    CSFML_CALL_PTR_RETURN(texture, getNativeHandle(), 0);
}


////////////////////////////////////////////////////////////
void sfTexture_bind(const sfTexture* texture, sfTextureCoordinateType type)
{
    sf::Texture::bind(texture ? texture->This : nullptr, static_cast<sf::CoordinateType>(type));
}


////////////////////////////////////////////////////////////
unsigned int sfTexture_getMaximumSize()
{
    return sf::Texture::getMaximumSize();
}
