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
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/TextureStruct.h>
#include <SFML/Graphics/ImageStruct.h>
#include <SFML/Graphics/RenderWindowStruct.h>
#include <SFML/Window/WindowStruct.h>
#include <SFML/Internal.h>
#include <SFML/CallbackStream.h>


////////////////////////////////////////////////////////////
/// Create a new texture
////////////////////////////////////////////////////////////
sfTexture* sfTexture_Create(unsigned int width, unsigned int height)
{
    sfTexture* texture = new sfTexture;
    
    if (!texture->This->Create(width, height))
    {
        delete texture;
        texture = NULL;
    }

    return texture;
}


////////////////////////////////////////////////////////////
/// Create a new texture from a file
////////////////////////////////////////////////////////////
sfTexture* sfTexture_CreateFromFile(const char* filename, const sfIntRect* area)
{
    sfTexture* texture = new sfTexture;

    sf::IntRect rect;
    if (area)
        rect = sf::IntRect(area->Left, area->Top, area->Width, area->Height);

    if (!texture->This->LoadFromFile(filename))
    {
        delete texture;
        texture = NULL;
    }

    return texture;
}


////////////////////////////////////////////////////////////
/// Create a new texture from a file in memory
////////////////////////////////////////////////////////////
sfTexture* sfTexture_CreateFromMemory(const void* data, size_t sizeInBytes, const sfIntRect* area)
{
    sfTexture* texture = new sfTexture;

    sf::IntRect rect;
    if (area)
        rect = sf::IntRect(area->Left, area->Top, area->Width, area->Height);

    if (!texture->This->LoadFromMemory(data, sizeInBytes))
    {
        delete texture;
        texture = NULL;
    }

    return texture;
}


////////////////////////////////////////////////////////////
/// Create a new texture from a custom stream
////////////////////////////////////////////////////////////
sfTexture* sfTexture_CreateFromStream(sfInputStream* stream, const sfIntRect* area)
{
    CSFML_CHECK_RETURN(stream, NULL);

    sfTexture* texture = new sfTexture;

    sf::IntRect rect;
    if (area)
        rect = sf::IntRect(area->Left, area->Top, area->Width, area->Height);

    CallbackStream sfmlStream(stream);
    if (!texture->This->LoadFromStream(sfmlStream))
    {
        delete texture;
        texture = NULL;
    }

    return texture;
}


////////////////////////////////////////////////////////////
/// Create a new texture from an image
////////////////////////////////////////////////////////////
sfTexture* sfTexture_CreateFromImage(const sfImage* image, const sfIntRect* area)
{
    CSFML_CHECK_RETURN(image, NULL);

    sfTexture* texture = new sfTexture;

    sf::IntRect rect;
    if (area)
        rect = sf::IntRect(area->Left, area->Top, area->Width, area->Height);

    if (!texture->This->LoadFromImage(image->This, rect))
    {
        delete texture;
        texture = NULL;
    }

    return texture;
}


////////////////////////////////////////////////////////////
/// Copy an existing texture
////////////////////////////////////////////////////////////
sfTexture* sfTexture_Copy(sfTexture* texture)
{
    CSFML_CHECK_RETURN(texture, NULL);

    return new sfTexture(*texture);
}


////////////////////////////////////////////////////////////
/// Destroy an existing texture
////////////////////////////////////////////////////////////
void sfTexture_Destroy(sfTexture* texture)
{
    delete texture;
}


////////////////////////////////////////////////////////////
/// Return the width of the texture
////////////////////////////////////////////////////////////
unsigned int sfTexture_GetWidth(const sfTexture* texture)
{
    CSFML_CALL_PTR_RETURN(texture, GetWidth(), 0);
}


////////////////////////////////////////////////////////////
/// Return the height of the texture
////////////////////////////////////////////////////////////
unsigned int sfTexture_GetHeight(const sfTexture* texture)
{
    CSFML_CALL_PTR_RETURN(texture, GetHeight(), 0);
}


////////////////////////////////////////////////////////////
/// Copy a texture's pixels to an image
////////////////////////////////////////////////////////////
sfImage* sfTexture_CopyToImage(const sfTexture* texture)
{
    CSFML_CHECK_RETURN(texture, NULL);
    CSFML_CHECK_RETURN(texture->This, NULL);

    sfImage* image = new sfImage;
    image->This = texture->This->CopyToImage();

    return image;
}


////////////////////////////////////////////////////////////
/// Update a texture from an array of pixels
////////////////////////////////////////////////////////////
void sfTexture_UpdateFromPixels(sfTexture* texture, const sfUint8* pixels, unsigned int width, unsigned int height, unsigned int x, unsigned int y)
{
    CSFML_CALL_PTR(texture, Update(pixels, width, height, x, y));
}


////////////////////////////////////////////////////////////
/// Update a texture from an image
////////////////////////////////////////////////////////////
void sfTexture_UpdateFromImage(sfTexture* texture, const sfImage* image, unsigned int x, unsigned int y)
{
    CSFML_CHECK(image);

    CSFML_CALL_PTR(texture, Update(image->This, x, y));
}


////////////////////////////////////////////////////////////
/// Update a texture from the contents of a window
////////////////////////////////////////////////////////////
void sfTexture_UpdateFromWindow(sfTexture* texture, const sfWindow* window, unsigned int x, unsigned int y)
{
    CSFML_CHECK(window);

    CSFML_CALL_PTR(texture, Update(window->This, x, y));
}


////////////////////////////////////////////////////////////
/// Update a texture from the contents of a render-window
////////////////////////////////////////////////////////////
void sfTexture_UpdateFromRenderWindow(sfTexture* texture, const sfRenderWindow* renderWindow, unsigned int x, unsigned int y)
{
    CSFML_CHECK(renderWindow);

    CSFML_CALL_PTR(texture, Update(renderWindow->This, x, y));
}


////////////////////////////////////////////////////////////
/// Activate a texture for rendering
////////////////////////////////////////////////////////////
void sfTexture_Bind(const sfTexture* texture)
{
    CSFML_CALL_PTR(texture, Bind());
}


////////////////////////////////////////////////////////////
/// Enable or disable the smooth filter on a texture
////////////////////////////////////////////////////////////
void sfTexture_SetSmooth(sfTexture* texture, sfBool smooth)
{
    CSFML_CALL_PTR(texture, SetSmooth(smooth == sfTrue));
}


////////////////////////////////////////////////////////////
/// Tell whether the smooth filter is enabled or not for a texture
////////////////////////////////////////////////////////////
sfBool sfTexture_IsSmooth(const sfTexture* texture)
{
    CSFML_CHECK_RETURN(texture, sfFalse);
    CSFML_CHECK_RETURN(texture->This, sfFalse);

    return texture->This->IsSmooth();
}


////////////////////////////////////////////////////////////
/// Convert a rectangle of pixels into texture coordinates
////////////////////////////////////////////////////////////
sfFloatRect sfTexture_GetTexCoords(const sfTexture* texture, sfIntRect rectangle)
{
    sfFloatRect result = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(texture, result);
    CSFML_CHECK_RETURN(texture->This, result);

    sf::IntRect rect(rectangle.Left, rectangle.Top, rectangle.Width, rectangle.Height);
    sf::FloatRect sfmlResult = texture->This->GetTexCoords(rect);

    result.Left = sfmlResult.Left;
    result.Top = sfmlResult.Top;
    result.Width = sfmlResult.Width;
    result.Height = sfmlResult.Height;

    return result;
}


////////////////////////////////////////////////////////////
/// Get the maximum texture size allowed
////////////////////////////////////////////////////////////
unsigned int sfTexture_GetMaximumSize()
{
    return sf::Texture::GetMaximumSize();
}
