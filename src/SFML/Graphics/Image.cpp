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
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/ImageStruct.h>
#include <SFML/Internal.h>
#include <SFML/CallbackStream.h>

////////////////////////////////////////////////////////////
sfImage* sfImage_Create(unsigned int width, unsigned int height)
{
    sfImage* image = new sfImage;
    image->This.Create(width, height);

    return image;
}


////////////////////////////////////////////////////////////
sfImage* sfImage_CreateFromColor(unsigned int width, unsigned int height, sfColor color)
{
    sfImage* image = new sfImage;
    image->This.Create(width, height, sf::Color(color.r, color.g, color.b, color.a));

    return image;
}


////////////////////////////////////////////////////////////
sfImage* sfImage_CreateFromPixels(unsigned int width, unsigned int height, const sfUint8* data)
{
    sfImage* image = new sfImage;
    image->This.Create(width, height, data);

    return image;
}


////////////////////////////////////////////////////////////
sfImage* sfImage_CreateFromFile(const char* filename)
{
    sfImage* image = new sfImage;

    if (!image->This.LoadFromFile(filename))
    {
        delete image;
        image = NULL;
    }

    return image;
}


////////////////////////////////////////////////////////////
sfImage* sfImage_CreateFromMemory(const void* data, size_t sizeInBytes)
{
    sfImage* image = new sfImage;

    if (!image->This.LoadFromMemory(data, sizeInBytes))
    {
        delete image;
        image = NULL;
    }

    return image;
}


////////////////////////////////////////////////////////////
sfImage* sfImage_CreateFromStream(sfInputStream* stream)
{
    CSFML_CHECK_RETURN(stream, NULL);

    sfImage* image = new sfImage;

    CallbackStream sfmlStream(stream);
    if (!image->This.LoadFromStream(sfmlStream))
    {
        delete image;
        image = NULL;
    }

    return image;
}


////////////////////////////////////////////////////////////
sfImage* sfImage_Copy(sfImage* image)
{
    CSFML_CHECK_RETURN(image, NULL);

    return new sfImage(*image);
}


////////////////////////////////////////////////////////////
void sfImage_Destroy(sfImage* image)
{
    delete image;
}


////////////////////////////////////////////////////////////
sfBool sfImage_SaveToFile(const sfImage* image, const char* filename)
{
    CSFML_CALL_RETURN(image, SaveToFile(filename), sfFalse);
}


////////////////////////////////////////////////////////////
void sfImage_CreateMaskFromColor(sfImage* image, sfColor colorKey, sfUint8 alpha)
{
    CSFML_CALL(image, CreateMaskFromColor(sf::Color(colorKey.r, colorKey.g, colorKey.b, colorKey.a), alpha));
}


////////////////////////////////////////////////////////////
void sfImage_CopyImage(sfImage* image, const sfImage* source, unsigned int destX, unsigned int destY, sfIntRect sourceRect, sfBool applyAlpha)
{
    CSFML_CHECK(source);
    sf::IntRect sfmlRect(sourceRect.Left, sourceRect.Top, sourceRect.Width, sourceRect.Height);
    CSFML_CALL(image, Copy(source->This, destX, destY, sfmlRect, applyAlpha == sfTrue));
}


////////////////////////////////////////////////////////////
void sfImage_SetPixel(sfImage* image, unsigned int x, unsigned int y, sfColor color)
{
    CSFML_CALL(image, SetPixel(x, y, sf::Color(color.r, color.g, color.b, color.a)));
}


////////////////////////////////////////////////////////////
sfColor sfImage_GetPixel(const sfImage* image, unsigned int x, unsigned int y)
{
    sfColor color = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(image, color);

    sf::Color sfmlColor = image->This.GetPixel(x, y);

    return sfColor_FromRGBA(sfmlColor.r, sfmlColor.g, sfmlColor.b, sfmlColor.a);
}


////////////////////////////////////////////////////////////
const sfUint8* sfImage_GetPixelsPtr(const sfImage* image)
{
    CSFML_CALL_RETURN(image, GetPixelsPtr(), NULL);
}


////////////////////////////////////////////////////////////
unsigned int sfImage_GetWidth(const sfImage* image)
{
    CSFML_CALL_RETURN(image, GetWidth(), 0);
}


////////////////////////////////////////////////////////////
unsigned int sfImage_GetHeight(const sfImage* image)
{
    CSFML_CALL_RETURN(image, GetHeight(), 0);
}


////////////////////////////////////////////////////////////
void sfImage_FlipHorizontally(sfImage* image)
{
    CSFML_CALL(image, FlipHorizontally());
}


////////////////////////////////////////////////////////////
void sfImage_FlipVertically(sfImage* image)
{
    CSFML_CALL(image, FlipVertically());
}
