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
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/TextureStruct.h>
#include <SFML/Graphics/ImageStruct.h>
#include <SFML/Graphics/RenderWindowStruct.h>
#include <SFML/Window/WindowStruct.h>
#include <SFML/Internal.h>
#include <SFML/CallbackStream.h>


////////////////////////////////////////////////////////////
sfTexture* sfTexture_create(unsigned int width, unsigned int height)
{
    auto texture = sf::Texture::create({width, height});
    if (!texture)
        return nullptr;

    return new sfTexture(new sf::Texture(std::move(*texture)));
}


////////////////////////////////////////////////////////////
sfTexture* sfTexture_createFromFile(const char* filename, const sfIntRect* area)
{
    sf::IntRect rect;
    if (area)
        rect = sf::IntRect({ area->position.x, area->position.y }, { area->size.x, area->size.y });

    auto texture = sf::Texture::loadFromFile(filename, false, rect);
    if (!texture)
        return nullptr;

    return new sfTexture(new sf::Texture(std::move(*texture)));
}

////////////////////////////////////////////////////////////
sfTexture* sfTexture_createSrgbFromFile(const char* filename, const sfIntRect* area)
{
    sf::IntRect rect;
    if (area)
        rect = sf::IntRect({ area->position.x, area->position.y }, { area->size.x, area->size.y });

    auto texture = sf::Texture::loadFromFile(filename, true, rect);
    if (!texture)
        return nullptr;

    return new sfTexture(new sf::Texture(std::move(*texture)));
}

////////////////////////////////////////////////////////////
sfTexture* sfTexture_createFromMemory(const void* data, size_t sizeInBytes, const sfIntRect* area)
{
    sf::IntRect rect;
    if (area)
        rect = sf::IntRect({ area->position.x, area->position.y }, { area->size.x, area->size.y });

    auto texture = sf::Texture::loadFromMemory(data, sizeInBytes, false, rect);
    if (!texture)
        return nullptr;

    return new sfTexture(new sf::Texture(std::move(*texture)));
}

////////////////////////////////////////////////////////////
sfTexture* sfTexture_createSrgbFromMemory(const void* data, size_t sizeInBytes, const sfIntRect* area)
{
    sf::IntRect rect;
    if (area)
        rect = sf::IntRect({ area->position.x, area->position.y }, { area->size.x, area->size.y });

    auto texture = sf::Texture::loadFromMemory(data, sizeInBytes, false, rect);
    if (!texture)
        return nullptr;

    return new sfTexture(new sf::Texture(std::move(*texture)));
}


////////////////////////////////////////////////////////////
sfTexture* sfTexture_createFromStream(sfInputStream* stream, const sfIntRect* area)
{
    CSFML_CHECK_RETURN(stream, nullptr);

    sf::IntRect rect;
    if (area)
        rect = sf::IntRect({ area->position.x, area->position.y }, { area->size.x, area->size.y });

    CallbackStream sfmlStream(stream);
    auto texture = sf::Texture::loadFromStream(sfmlStream, false, rect);
    if (!texture)
        return nullptr;

    return new sfTexture(new sf::Texture(std::move(*texture)));
}

////////////////////////////////////////////////////////////
sfTexture* sfTexture_createSrgbFromStream(sfInputStream* stream, const sfIntRect* area)
{
    CSFML_CHECK_RETURN(stream, nullptr);

    sf::IntRect rect;
    if (area)
        rect = sf::IntRect({ area->position.x, area->position.y }, { area->size.x, area->size.y });

    CallbackStream sfmlStream(stream);
    auto texture = sf::Texture::loadFromStream(sfmlStream, true, rect);
    if (!texture)
        return nullptr;

    return new sfTexture(new sf::Texture(std::move(*texture)));
}


////////////////////////////////////////////////////////////
sfTexture* sfTexture_createFromImage(const sfImage* image, const sfIntRect* area)
{
    CSFML_CHECK_RETURN(image, nullptr);

    sf::IntRect rect;
    if (area)
        rect = sf::IntRect({ area->position.x, area->position.y }, { area->size.x, area->size.y });

    auto texture = sf::Texture::loadFromImage(image->This, false, rect);
    if (!texture)
        return nullptr;

    return new sfTexture(new sf::Texture(std::move(*texture)));
}

////////////////////////////////////////////////////////////
sfTexture* sfTexture_createSrgbFromImage(const sfImage* image, const sfIntRect* area)
{
    CSFML_CHECK_RETURN(image, nullptr);

    sf::IntRect rect;
    if (area)
        rect = sf::IntRect({ area->position.x, area->position.y }, { area->size.x, area->size.y });

    auto texture = sf::Texture::loadFromImage(image->This, true, rect);
    if (!texture)
        return nullptr;

    return new sfTexture(new sf::Texture(std::move(*texture)));
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
    sfVector2u size = {0, 0};
    CSFML_CHECK_RETURN(texture, size);

    sf::Vector2u sfmlSize = texture->This->getSize();

    size.x = sfmlSize.x;
    size.y = sfmlSize.y;

    return size;
}


////////////////////////////////////////////////////////////
sfImage* sfTexture_copyToImage(const sfTexture* texture)
{
    CSFML_CHECK_RETURN(texture, nullptr);
    CSFML_CHECK_RETURN(texture->This, nullptr);

    return new sfImage{texture->This->copyToImage()};
}


////////////////////////////////////////////////////////////
void sfTexture_updateFromPixels(sfTexture* texture, const uint8_t* pixels, unsigned int width, unsigned int height, unsigned int x, unsigned int y)
{
    CSFML_CALL_PTR(texture, update(pixels, { width, height }, { x, y }));
}


////////////////////////////////////////////////////////////
void sfTexture_updateFromTexture(sfTexture* destination, const sfTexture* texture, unsigned int x, unsigned int y)
{
    CSFML_CHECK(texture);
    CSFML_CHECK(texture->This);

    CSFML_CALL_PTR(destination, update(*texture->This, { x, y }));
}


////////////////////////////////////////////////////////////
void sfTexture_updateFromImage(sfTexture* texture, const sfImage* image, unsigned int x, unsigned int y)
{
    CSFML_CHECK(image);

    CSFML_CALL_PTR(texture, update(image->This, { x, y }));
}


////////////////////////////////////////////////////////////
void sfTexture_updateFromWindow(sfTexture* texture, const sfWindow* window, unsigned int x, unsigned int y)
{
    CSFML_CHECK(window);

    CSFML_CALL_PTR(texture, update(window->This, { x, y }));
}


////////////////////////////////////////////////////////////
void sfTexture_updateFromRenderWindow(sfTexture* texture, const sfRenderWindow* renderWindow, unsigned int x, unsigned int y)
{
    CSFML_CHECK(renderWindow);

    CSFML_CALL_PTR(texture, update(renderWindow->This, { x, y }));
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
