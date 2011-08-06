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

#ifndef SFML_TEXTURE_H
#define SFML_TEXTURE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Config.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Types.h>
#include <SFML/System/InputStream.h>
#include <stddef.h>


////////////////////////////////////////////////////////////
/// Create a new texture
///
/// \param width :  Texture width
/// \param height : Texture height
///
/// \return A new sfTexture object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_API sfTexture* sfTexture_Create(unsigned int width, unsigned int height);

////////////////////////////////////////////////////////////
/// Create a new texture from a file
///
/// \param filename : Path of the image file to load
/// \param area : Area of the source image to load (NULL to load the entire image)
///
/// \return A new sfTexture object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_API sfTexture* sfTexture_CreateFromFile(const char* filename, const sfIntRect* area);

////////////////////////////////////////////////////////////
/// Create a new texture from a file in memory
///
/// \param data :        Pointer to the file data in memory
/// \param sizeInBytes : Size of the data to load, in bytes
/// \param area : Area of the source image to load (NULL to load the entire image)
///
/// \return A new sfTexture object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_API sfTexture* sfTexture_CreateFromMemory(const void* data, size_t sizeInBytes, const sfIntRect* area);

////////////////////////////////////////////////////////////
/// Create a new texture from a custom stream
///
/// \param stream : Source stream to read from
/// \param area : Area of the source image to load (NULL to load the entire image)
///
/// \return A new sfTexture object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_API sfTexture* sfTexture_CreateFromStream(sfInputStream* stream, const sfIntRect* area);

////////////////////////////////////////////////////////////
/// Create a new texture from an image
///
/// \param image : Image to upload to the texture
/// \param area : Area of the source image to load (NULL to load the entire image)
///
/// \return A new sfTexture object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_API sfTexture* sfTexture_CreateFromImage(const sfImage* image, const sfIntRect* area);

////////////////////////////////////////////////////////////
/// Copy an existing texture
///
/// \param texture : Texture to copy
///
/// \return Copied object
///
////////////////////////////////////////////////////////////
CSFML_API sfTexture* sfTexture_Copy(sfTexture* texture);

////////////////////////////////////////////////////////////
/// Destroy an existing texture
///
/// \param texture : Texture to delete
///
////////////////////////////////////////////////////////////
CSFML_API void sfTexture_Destroy(sfTexture* texture);

////////////////////////////////////////////////////////////
/// Return the width of the texture
///
/// \param texture : Texture to read
///
/// \return Width in pixels
///
////////////////////////////////////////////////////////////
CSFML_API unsigned int sfTexture_GetWidth(const sfTexture* texture);

////////////////////////////////////////////////////////////
/// Return the height of the texture
///
/// \param texture : Texture to read
///
/// \return Height in pixels
///
////////////////////////////////////////////////////////////
CSFML_API unsigned int sfTexture_GetHeight(const sfTexture* texture);

////////////////////////////////////////////////////////////
/// Copy a texture's pixels to an image
///
/// \param texture : Texture to copy
///
/// \return Image containing the texture's pixels
///
////////////////////////////////////////////////////////////
CSFML_API sfImage* sfTexture_CopyToImage(const sfTexture* texture);

////////////////////////////////////////////////////////////
/// Update a texture from an array of pixels
///
/// \param texture : Texture to update
/// \param pixels : Array of pixels to copy to the texture
/// \param width : Width of the pixel region contained in \a pixels
/// \param height : Height of the pixel region contained in \a pixels
/// \param x : X offset in the texture where to copy the source pixels
/// \param y : Y offset in the texture where to copy the source pixels
///
////////////////////////////////////////////////////////////
CSFML_API void sfTexture_UpdateFromPixels(sfTexture* texture, const sfUint8* pixels, unsigned int width, unsigned int height, unsigned int x, unsigned int y);

////////////////////////////////////////////////////////////
/// Update a texture from an image
///
/// \param texture : Texture to update
/// \param image : Image to copy to the texture
/// \param x : X offset in the texture where to copy the source pixels
/// \param y : Y offset in the texture where to copy the source pixels
///
////////////////////////////////////////////////////////////
CSFML_API void sfTexture_UpdateFromImage(sfTexture* texture, const sfImage* image, unsigned int x, unsigned int y);

////////////////////////////////////////////////////////////
/// Update a texture from the contents of a window
///
/// \param texture : Texture to update
/// \param window : Window to copy to the texture
/// \param x : X offset in the texture where to copy the source pixels
/// \param y : Y offset in the texture where to copy the source pixels
///
////////////////////////////////////////////////////////////
CSFML_API void sfTexture_UpdateFromWindow(sfTexture* texture, const sfWindow* window, unsigned int x, unsigned int y);

////////////////////////////////////////////////////////////
/// Update a texture from the contents of a render-window
///
/// \param texture : Texture to update
/// \param renderWindow : Render-window to copy to the texture
/// \param x : X offset in the texture where to copy the source pixels
/// \param y : Y offset in the texture where to copy the source pixels
///
////////////////////////////////////////////////////////////
CSFML_API void sfTexture_UpdateFromRenderWindow(sfTexture* texture, const sfRenderWindow* renderWindow, unsigned int x, unsigned int y);

////////////////////////////////////////////////////////////
/// Activate a texture for rendering
///
/// \param texture : Texture to bind
///
////////////////////////////////////////////////////////////
CSFML_API void sfTexture_Bind(const sfTexture* texture);

////////////////////////////////////////////////////////////
/// Enable or disable the smooth filter on a texture
///
/// \param texture : The texture object
/// \param smooth : sfTrue to enable smoothing, sfFalse to disable it
///
////////////////////////////////////////////////////////////
CSFML_API void sfTexture_SetSmooth(sfTexture* texture, sfBool smooth);

////////////////////////////////////////////////////////////
/// Tell whether the smooth filter is enabled or not for a texture
///
/// \param texture : The texture object
///
/// \return sfTrue if smoothing is enabled, sfFalse if it is disabled
///
////////////////////////////////////////////////////////////
CSFML_API sfBool sfTexture_IsSmooth(const sfTexture* texture);

////////////////////////////////////////////////////////////
/// Convert a rectangle of pixels into texture coordinates
///
/// \param texture : Texture to use for conversion
/// \param rectangle : Rectangle to convert
///
/// \return Texture coordinates corresponding to \a rectangle
///
////////////////////////////////////////////////////////////
CSFML_API sfFloatRect sfTexture_GetTexCoords(const sfTexture* texture, sfIntRect rectangle);

////////////////////////////////////////////////////////////
/// Get the maximum texture size allowed
///
/// \return Maximum size allowed for textures, in pixels
///
////////////////////////////////////////////////////////////
CSFML_API unsigned int sfTexture_GetMaximumSize();


#endif // SFML_TEXTURE_H
