////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2024 Laurent Gomila (laurent@sfml-dev.org)
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

#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Graphics/Export.h>

#include <CSFML/Graphics/CoordinateType.h>
#include <CSFML/Graphics/Rect.h>
#include <CSFML/Graphics/Types.h>
#include <CSFML/System/InputStream.h>
#include <CSFML/System/Vector2.h>
#include <CSFML/Window/Types.h>

#include <stddef.h>

////////////////////////////////////////////////////////////
/// \brief Create a new texture
///
/// \param size Texture size
///
/// \return A new sfTexture object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTexture* sfTexture_create(sfVector2u size);

////////////////////////////////////////////////////////////
/// \brief Create a new sRGB-enabled texture
///
/// \param size Texture size
///
/// \return A new sfTexture object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTexture* sfTexture_createSrgb(sfVector2u size);

////////////////////////////////////////////////////////////
/// \brief Create a new texture from a file
///
/// \param filename Path of the image file to load
/// \param area     Area of the source image to load (NULL to load the entire image)
///
/// \return A new sfTexture object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTexture* sfTexture_createFromFile(const char* filename, const sfIntRect* area);

////////////////////////////////////////////////////////////
/// \brief Create a new sRGB-enabled texture from a file
///
/// When providing texture data from an image file or memory, it can
/// either be stored in a linear color space or an sRGB color space.
/// Most digital images account for gamma correction already, so they
/// would need to be "uncorrected" back to linear color space before
/// being processed by the hardware. The hardware can automatically
/// convert it from the sRGB color space to a linear color space when
/// it gets sampled. When the rendered image gets output to the final
/// framebuffer, it gets converted back to sRGB.
///
/// This load option is only useful in conjunction with an sRGB capable
/// framebuffer. This can be requested during window creation.
///
/// \param filename Path of the image file to load
/// \param area     Area of the source image to load (NULL to load the entire image)
///
/// \return A new sfTexture object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTexture* sfTexture_createSrgbFromFile(const char* filename, const sfIntRect* area);

////////////////////////////////////////////////////////////
/// \brief Create a new texture from a file in memory
///
/// \param data        Pointer to the file data in memory
/// \param sizeInBytes Size of the data to load, in bytes
/// \param area        Area of the source image to load (NULL to load the entire image)
///
/// \return A new sfTexture object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTexture* sfTexture_createFromMemory(const void* data, size_t sizeInBytes, const sfIntRect* area);

////////////////////////////////////////////////////////////
/// \brief Create a new sRGB-enabled texture from a file in memory
///
/// \param data        Pointer to the file data in memory
/// \param sizeInBytes Size of the data to load, in bytes
/// \param area        Area of the source image to load (NULL to load the entire image)
///
/// \return A new sfTexture object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTexture* sfTexture_createSrgbFromMemory(const void* data, size_t sizeInBytes, const sfIntRect* area);

////////////////////////////////////////////////////////////
/// \brief Create a new texture from a custom stream
///
/// \param stream Source stream to read from
/// \param area   Area of the source image to load (NULL to load the entire image)
///
/// \return A new sfTexture object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTexture* sfTexture_createFromStream(sfInputStream* stream, const sfIntRect* area);

////////////////////////////////////////////////////////////
/// \brief Create a new sRGB-enabled texture from a custom stream
///
/// \param stream Source stream to read from
/// \param area   Area of the source image to load (NULL to load the entire image)
///
/// \return A new sfTexture object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTexture* sfTexture_createSrgbFromStream(sfInputStream* stream, const sfIntRect* area);

////////////////////////////////////////////////////////////
/// \brief Create a new texture from an image
///
/// \param image Image to upload to the texture
/// \param area  Area of the source image to load (NULL to load the entire image)
///
/// \return A new sfTexture object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTexture* sfTexture_createFromImage(const sfImage* image, const sfIntRect* area);

////////////////////////////////////////////////////////////
/// \brief Create a new sRGB-enabled texture from an image
///
/// \param image Image to upload to the texture
/// \param area  Area of the source image to load (NULL to load the entire image)
///
/// \return A new sfTexture object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTexture* sfTexture_createSrgbFromImage(const sfImage* image, const sfIntRect* area);

////////////////////////////////////////////////////////////
/// \brief Copy an existing texture
///
/// \param texture Texture to copy
///
/// \return Copied object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTexture* sfTexture_copy(const sfTexture* texture);

////////////////////////////////////////////////////////////
/// \brief Destroy an existing texture
///
/// \param texture Texture to delete
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTexture_destroy(const sfTexture* texture);

////////////////////////////////////////////////////////////
/// \brief Resize the texture
///
/// If this function fails, the texture is left unchanged.
///
/// \param texture Texture to resize
/// \param size Width and height of the texture
/// \param sRgb `true` to enable sRGB conversion, `false` to disable it
///
/// \return `true` if resizing was successful, `false` if it failed
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfTexture_resize(sfTexture* texture, sfVector2u size, bool sRgb);

////////////////////////////////////////////////////////////
/// \brief Return the size of the texture
///
/// \param texture Texture to read
///
/// \return Size in pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfVector2u sfTexture_getSize(const sfTexture* texture);

////////////////////////////////////////////////////////////
/// \brief Copy a texture's pixels to an image
///
/// \param texture Texture to copy
///
/// \return Image containing the texture's pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfImage* sfTexture_copyToImage(const sfTexture* texture);

////////////////////////////////////////////////////////////
/// \brief Update a texture from an array of pixels
///
/// \param texture Texture to update
/// \param pixels  Array of pixels to copy to the texture
/// \param size    size of the pixel region contained in \a pixels
/// \param offset  Offset in the texture where to copy the source pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTexture_updateFromPixels(sfTexture* texture, const uint8_t* pixels, sfVector2u size, sfVector2u offset);

////////////////////////////////////////////////////////////
/// \brief Update a part of this texture from another texture
///
/// No additional check is performed on the size of the texture,
/// passing an invalid combination of texture size and offset
/// will lead to an undefined behavior.
///
/// This function does nothing if either texture was not
/// previously created.
///
/// \param destination Destination texture to copy source texture to
/// \param source      Source texture to copy to destination texture
/// \param offset      Offset in this texture where to copy the source texture
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTexture_updateFromTexture(sfTexture* destination, const sfTexture* source, sfVector2u offset);

////////////////////////////////////////////////////////////
/// \brief Update a texture from an image
///
/// \param texture Texture to update
/// \param image   Image to copy to the texture
/// \param offset  Offset in the texture where to copy the source pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTexture_updateFromImage(sfTexture* texture, const sfImage* image, sfVector2u offset);

////////////////////////////////////////////////////////////
/// \brief Update a texture from the contents of a window
///
/// \param texture Texture to update
/// \param window  Window to copy to the texture
/// \param offset  Offset in the texture where to copy the source pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTexture_updateFromWindow(sfTexture* texture, const sfWindow* window, sfVector2u offset);

////////////////////////////////////////////////////////////
/// \brief Update a texture from the contents of a render-window
///
/// \param texture      Texture to update
/// \param renderWindow Render-window to copy to the texture
/// \param offset       Offset in the texture where to copy the source pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTexture_updateFromRenderWindow(sfTexture* texture, const sfRenderWindow* renderWindow, sfVector2u offset);

////////////////////////////////////////////////////////////
/// \brief Enable or disable the smooth filter on a texture
///
/// \param texture The texture object
/// \param smooth  true to enable smoothing, false to disable it
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTexture_setSmooth(sfTexture* texture, bool smooth);

////////////////////////////////////////////////////////////
/// \brief Tell whether the smooth filter is enabled or not for a texture
///
/// \param texture The texture object
///
/// \return true if smoothing is enabled, false if it is disabled
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfTexture_isSmooth(const sfTexture* texture);

////////////////////////////////////////////////////////////
/// \brief Tell whether the texture source is converted from sRGB or not
///
/// \return True if the texture source is converted from sRGB, false if not
///
/// \see sfTexture_createSrgbFromFile
/// \see sfTexture_createSrgbFromMemory
/// \see sfTexture_createSrgbFromStream
/// \see sfTexture_createSrgbFromImage
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfTexture_isSrgb(const sfTexture* texture);

////////////////////////////////////////////////////////////
/// \brief Enable or disable repeating for a texture
///
/// Repeating is involved when using texture coordinates
/// outside the texture rectangle [0, 0, width, height].
/// In this case, if repeat mode is enabled, the whole texture
/// will be repeated as many times as needed to reach the
/// coordinate (for example, if the X texture coordinate is
/// 3 * width, the texture will be repeated 3 times).
/// If repeat mode is disabled, the "extra space" will instead
/// be filled with border pixels.
/// Warning: on very old graphics cards, white pixels may appear
/// when the texture is repeated. With such cards, repeat mode
/// can be used reliably only if the texture has power-of-two
/// dimensions (such as 256x128).
/// Repeating is disabled by default.
///
/// \param texture  The texture object
/// \param repeated True to repeat the texture, false to disable repeating
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTexture_setRepeated(sfTexture* texture, bool repeated);

////////////////////////////////////////////////////////////
/// \brief Tell whether a texture is repeated or not
///
/// \param texture The texture object
///
/// \return true if repeat mode is enabled, false if it is disabled
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfTexture_isRepeated(const sfTexture* texture);

////////////////////////////////////////////////////////////
/// \brief Generate a mipmap using the current texture data
///
/// Mipmaps are pre-computed chains of optimized textures. Each
/// level of texture in a mipmap is generated by halving each of
/// the previous level's dimensions. This is done until the final
/// level has the size of 1x1. The textures generated in this process may
/// make use of more advanced filters which might improve the visual quality
/// of textures when they are applied to objects much smaller than they are.
/// This is known as minification. Because fewer texels (texture elements)
/// have to be sampled from when heavily minified, usage of mipmaps
/// can also improve rendering performance in certain scenarios.
///
/// Mipmap generation relies on the necessary OpenGL extension being
/// available. If it is unavailable or generation fails due to another
/// reason, this function will return false. Mipmap data is only valid from
/// the time it is generated until the next time the base level image is
/// modified, at which point this function will have to be called again to
/// regenerate it.
///
/// \return true if mipmap generation was successful, false if unsuccessful
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfTexture_generateMipmap(sfTexture* texture);

////////////////////////////////////////////////////////////
/// \brief Swap the contents of a texture with those of another
///
/// \param left  Instance to swap from
/// \param right Instance to swap with
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTexture_swap(sfTexture* left, sfTexture* right);

////////////////////////////////////////////////////////////
/// \brief Get the underlying OpenGL handle of the texture.
///
/// You shouldn't need to use this function, unless you have
/// very specific stuff to implement that SFML doesn't support,
/// or implement a temporary workaround until a bug is fixed.
///
/// \param texture The texture object
///
/// \return OpenGL handle of the texture or 0 if not yet created
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API unsigned int sfTexture_getNativeHandle(const sfTexture* texture);

////////////////////////////////////////////////////////////
/// \brief Bind a texture for rendering
///
/// This function is not part of the graphics API, it mustn't be
/// used when drawing SFML entities. It must be used only if you
/// mix sfTexture with OpenGL code.
///
/// \code
/// sfTexture *t1, *t2;
/// ...
/// sfTexture_bind(t1);
/// // draw OpenGL stuff that use t1...
/// sfTexture_bind(t2);
/// // draw OpenGL stuff that use t2...
/// sfTexture_bind(NULL);
/// // draw OpenGL stuff that use no texture...
/// \endcode
///
/// \param texture Pointer to the texture to bind, can be null to use no texture
/// \param type    Type of texture coordinates to use
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTexture_bind(const sfTexture* texture, sfCoordinateType type);

////////////////////////////////////////////////////////////
/// \brief Get the maximum texture size allowed
///
/// \return Maximum size allowed for textures, in pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API unsigned int sfTexture_getMaximumSize(void);
