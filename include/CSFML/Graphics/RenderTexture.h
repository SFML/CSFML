////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2025 Laurent Gomila (laurent@sfml-dev.org)
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

#include <CSFML/Graphics/Color.h>
#include <CSFML/Graphics/PrimitiveType.h>
#include <CSFML/Graphics/Rect.h>
#include <CSFML/Graphics/RenderStates.h>
#include <CSFML/Graphics/StencilMode.h>
#include <CSFML/Graphics/Types.h>
#include <CSFML/Graphics/Vertex.h>
#include <CSFML/System/Vector2.h>
#include <CSFML/Window/Window.h>

#include <stddef.h>


////////////////////////////////////////////////////////////
/// \brief Construct a new render texture
///
/// \param size     Size of the render texture
/// \param settings Settings of the render texture
///
/// \return A new sfRenderTexture object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfRenderTexture* sfRenderTexture_create(sfVector2u size, const sfContextSettings* settings);

////////////////////////////////////////////////////////////
/// \brief Destroy an existing render texture
///
/// \param renderTexture Render texture to destroy
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_destroy(const sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Get the size of the rendering region of a render texture
///
/// \param renderTexture Render texture object
///
/// \return Size in pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfVector2u sfRenderTexture_getSize(const sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Tell if the render texture will use sRGB encoding when drawing on it
///
/// \param renderTexture Render texture object
///
/// \return true if the render texture use sRGB encoding, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfRenderTexture_isSrgb(const sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Activate or deactivate a render texture as the current target for rendering
///
/// \param renderTexture Render texture object
/// \param active        true to activate, false to deactivate
///
/// \return True if operation was successful, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfRenderTexture_setActive(sfRenderTexture* renderTexture, bool active);

////////////////////////////////////////////////////////////
/// \brief Update the contents of the target texture
///
/// \param renderTexture Render texture object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_display(sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Clear the rendertexture with the given color
///
/// \param renderTexture Render texture object
/// \param color         Fill color
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_clear(sfRenderTexture* renderTexture, sfColor color);

////////////////////////////////////////////////////////////
/// \brief Clear the stencil buffer to a specific value
///
/// The specified value is truncated to the bit width of
/// the current stencil buffer.
///
/// \param renderTexture Render texture object
/// \param stencilValue  Stencil value to clear to
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_clearStencil(sfRenderTexture* renderTexture, sfStencilValue stencilValue);

////////////////////////////////////////////////////////////
/// \brief Clear the entire target with a single color and stencil value
///
/// The specified stencil value is truncated to the bit
/// width of the current stencil buffer.
///
/// \param renderTexture Render texture object
/// \param color         Fill color to use to clear the render target
/// \param stencilValue  Stencil value to clear to
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_clearColorAndStencil(sfRenderTexture* renderTexture,
                                                             sfColor          color,
                                                             sfStencilValue   stencilValue);

////////////////////////////////////////////////////////////
/// \brief Change the current active view of a render texture
///
/// \param renderTexture Render texture object
/// \param view          Pointer to the new view
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_setView(sfRenderTexture* renderTexture, const sfView* view);

////////////////////////////////////////////////////////////
/// \brief Get the current active view of a render texture
///
/// \param renderTexture Render texture object
///
/// \return Current active view
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const sfView* sfRenderTexture_getView(const sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Get the default view of a render texture
///
/// \param renderTexture Render texture object
///
/// \return Default view of the rendertexture
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const sfView* sfRenderTexture_getDefaultView(const sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Get the viewport of a view applied to this target
///
/// \param renderTexture Render texture object
/// \param view          Target view
///
/// \return Viewport rectangle, expressed in pixels in the current target
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfIntRect sfRenderTexture_getViewport(const sfRenderTexture* renderTexture, const sfView* view);

////////////////////////////////////////////////////////////
/// \brief Get the scissor rectangle of a view, applied to this render target
///
/// The scissor rectangle is defined in the view as a ratio. This
/// function simply applies this ratio to the current dimensions
/// of the render target to calculate the pixels rectangle
/// that the scissor rectangle actually covers in the target.
///
/// \param renderTexture Render texture object
/// \param view          The view for which we want to compute the scissor rectangle
///
/// \return Scissor rectangle, expressed in pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfIntRect sfRenderTexture_getScissor(const sfRenderTexture* renderTexture, const sfView* view);

////////////////////////////////////////////////////////////
/// \brief Convert a point from texture coordinates to world coordinates
///
/// This function finds the 2D position that matches the
/// given pixel of the render-texture. In other words, it does
/// the inverse of what the graphics card does, to find the
/// initial position of a rendered pixel.
///
/// Initially, both coordinate systems (world units and target pixels)
/// match perfectly. But if you define a custom view or resize your
/// render-texture, this assertion is not true anymore, ie. a point
/// located at (10, 50) in your render-texture may map to the point
/// (150, 75) in your 2D world -- if the view is translated by (140, 25).
///
/// This version uses a custom view for calculations, see the other
/// overload of the function if you want to use the current view of the
/// render-texture.
///
/// \param renderTexture Render texture object
/// \param point Pixel to convert
/// \param view The view to use for converting the point
///
/// \return The converted point, in "world" units
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfVector2f
    sfRenderTexture_mapPixelToCoords(const sfRenderTexture* renderTexture, sfVector2i point, const sfView* view);

////////////////////////////////////////////////////////////
/// \brief Convert a point from world coordinates to texture coordinates
///
/// This function finds the pixel of the render-texture that matches
/// the given 2D point. In other words, it goes through the same process
/// as the graphics card, to compute the final position of a rendered point.
///
/// Initially, both coordinate systems (world units and target pixels)
/// match perfectly. But if you define a custom view or resize your
/// render-texture, this assertion is not true anymore, ie. a point
/// located at (150, 75) in your 2D world may map to the pixel
/// (10, 50) of your render-texture -- if the view is translated by (140, 25).
///
/// This version uses a custom view for calculations, see the other
/// overload of the function if you want to use the current view of the
/// render-texture.
///
/// \param renderTexture Render texture object
/// \param point Point to convert
/// \param view The view to use for converting the point
///
/// \return The converted point, in target coordinates (pixels)
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfVector2i
    sfRenderTexture_mapCoordsToPixel(const sfRenderTexture* renderTexture, sfVector2f point, const sfView* view);

////////////////////////////////////////////////////////////
/// \brief Draw a drawable object to the render-target
///
/// \param renderTexture Render texture object
/// \param object        Object to draw
/// \param states        Render states to use for drawing (NULL to use the default states)
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_drawSprite(sfRenderTexture*      renderTexture,
                                                   const sfSprite*       object,
                                                   const sfRenderStates* states);
CSFML_GRAPHICS_API void sfRenderTexture_drawText(sfRenderTexture*      renderTexture,
                                                 const sfText*         object,
                                                 const sfRenderStates* states);
CSFML_GRAPHICS_API void sfRenderTexture_drawShape(sfRenderTexture*      renderTexture,
                                                  const sfShape*        object,
                                                  const sfRenderStates* states);
CSFML_GRAPHICS_API void sfRenderTexture_drawCircleShape(sfRenderTexture*      renderTexture,
                                                        const sfCircleShape*  object,
                                                        const sfRenderStates* states);
CSFML_GRAPHICS_API void sfRenderTexture_drawConvexShape(sfRenderTexture*      renderTexture,
                                                        const sfConvexShape*  object,
                                                        const sfRenderStates* states);
CSFML_GRAPHICS_API void sfRenderTexture_drawRectangleShape(sfRenderTexture*        renderTexture,
                                                           const sfRectangleShape* object,
                                                           const sfRenderStates*   states);
CSFML_GRAPHICS_API void sfRenderTexture_drawVertexArray(sfRenderTexture*      renderTexture,
                                                        const sfVertexArray*  object,
                                                        const sfRenderStates* states);
CSFML_GRAPHICS_API void sfRenderTexture_drawVertexBuffer(sfRenderTexture*      renderTexture,
                                                         const sfVertexBuffer* object,
                                                         const sfRenderStates* states);

////////////////////////////////////////////////////////////
/// \brief Draw primitives defined by a vertex buffer.
///
/// \param renderTexture render texture object
/// \param object        Vertex buffer object to draw
/// \param firstVertex   Index of the first vertex to render
/// \param vertexCount   Number of vertices to render
/// \param states        Render states to use for drawing
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_drawVertexBufferRange(
    sfRenderTexture*      renderTexture,
    const sfVertexBuffer* object,
    size_t                firstVertex,
    size_t                vertexCount,
    const sfRenderStates* states);

////////////////////////////////////////////////////////////
/// \brief Draw primitives defined by an array of vertices to a render texture
///
/// \param renderTexture Render texture object
/// \param vertices      Pointer to the vertices
/// \param vertexCount   Number of vertices in the array
/// \param type          Type of primitives to draw
/// \param states        Render states to use for drawing (NULL to use the default states)
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_drawPrimitives(
    sfRenderTexture*      renderTexture,
    const sfVertex*       vertices,
    size_t                vertexCount,
    sfPrimitiveType       type,
    const sfRenderStates* states);

////////////////////////////////////////////////////////////
/// \brief Save the current OpenGL render states and matrices
///
/// This function can be used when you mix SFML drawing
/// and direct OpenGL rendering. Combined with popGLStates,
/// it ensures that:
/// \li SFML's internal states are not messed up by your OpenGL code
/// \li your OpenGL states are not modified by a call to a SFML function
///
/// Note that this function is quite expensive: it saves all the
/// possible OpenGL states and matrices, even the ones you
/// don't care about. Therefore it should be used wisely.
/// It is provided for convenience, but the best results will
/// be achieved if you handle OpenGL states yourself (because
/// you know which states have really changed, and need to be
/// saved and restored). Take a look at the resetGLStates
/// function if you do so.
///
/// \param renderTexture Render texture object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_pushGLStates(sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Restore the previously saved OpenGL render states and matrices
///
/// See the description of pushGLStates to get a detailed
/// description of these functions.
///
/// \param renderTexture Render texture object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_popGLStates(sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Reset the internal OpenGL states so that the target is ready for drawing
///
/// This function can be used when you mix SFML drawing
/// and direct OpenGL rendering, if you choose not to use
/// pushGLStates/popGLStates. It makes sure that all OpenGL
/// states needed by SFML are set, so that subsequent sfRenderTexture_draw*()
/// calls will work as expected.
///
/// \param renderTexture Render texture object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_resetGLStates(sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Get the target texture of a render texture
///
/// \param renderTexture Render texture object
///
/// \return Pointer to the target texture
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const sfTexture* sfRenderTexture_getTexture(const sfRenderTexture* renderTexture);


////////////////////////////////////////////////////////////
/// \brief Get the maximum anti-aliasing level supported by the system
///
/// \return The maximum anti-aliasing level supported by the system
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API unsigned int sfRenderTexture_getMaximumAntiAliasingLevel(void);

////////////////////////////////////////////////////////////
/// \brief Enable or disable the smooth filter on a render texture
///
/// \param renderTexture Render texture object
/// \param smooth        true to enable smoothing, false to disable it
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_setSmooth(sfRenderTexture* renderTexture, bool smooth);

////////////////////////////////////////////////////////////
/// \brief Tell whether the smooth filter is enabled or not for a render texture
///
/// \param renderTexture Render texture object
///
/// \return true if smoothing is enabled, false if it is disabled
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfRenderTexture_isSmooth(const sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Enable or disable texture repeating
///
/// \param renderTexture Render texture object
/// \param repeated      true to enable repeating, false to disable it
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_setRepeated(sfRenderTexture* renderTexture, bool repeated);

////////////////////////////////////////////////////////////
/// \brief Tell whether the texture is repeated or not
///
/// \param renderTexture Render texture object
///
/// \return true if repeat mode is enabled, false if it is disabled
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfRenderTexture_isRepeated(const sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Generate a mipmap using the current texture data
///
/// This function is similar to sfTexture_generateMipmap and operates
/// on the texture used as the target for drawing.
/// Be aware that any draw operation may modify the base level image data.
/// For this reason, calling this function only makes sense after all
/// drawing is completed and display has been called. Not calling display
/// after subsequent drawing will lead to undefined behavior if a mipmap
/// had been previously generated.
///
/// \return true if mipmap generation was successful, false if unsuccessful
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfRenderTexture_generateMipmap(sfRenderTexture* renderTexture);
