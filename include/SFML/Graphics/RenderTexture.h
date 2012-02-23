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

#ifndef SFML_RENDERTEXTURE_H
#define SFML_RENDERTEXTURE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/Vertex.h>


////////////////////////////////////////////////////////////
/// \brief Construct a new render texture
///
/// \param width       Width of the render texture
/// \param height      Height of the render texture
/// \param depthBuffer Do you want a depth-buffer attached? (useful only if you're doing 3D OpenGL on the rendertexture)
///
/// \return A new sfRenderTexture object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfRenderTexture* sfRenderTexture_Create(unsigned int width, unsigned int height, sfBool depthBuffer);

////////////////////////////////////////////////////////////
/// \brief Destroy an existing render texture
///
/// \param renderTexture Render texture to destroy
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_Destroy(sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Get the width of the rendering region of a render texture
///
/// \param renderTexture Render texture object
///
/// \return Width in pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API unsigned int sfRenderTexture_GetWidth(const sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Get the height of the rendering region of a render texture
///
/// \param renderTexture Render texture object
///
/// \return Height in pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API unsigned int sfRenderTexture_GetHeight(const sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Activate or deactivate a render texture as the current target for rendering
///
/// \param renderTexture Render texture object
/// \param active        sfTrue to activate, sfFalse to deactivate
///
/// \return True if operation was successful, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfBool sfRenderTexture_SetActive(sfRenderTexture* renderTexture, sfBool active);

////////////////////////////////////////////////////////////
/// \brief Update the contents of the target texture
///
/// \param renderTexture Render texture object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_Display(sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Clear the rendertexture with the given color
///
/// \param renderTexture Render texture object
/// \param color         Fill color
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_Clear(sfRenderTexture* renderTexture, sfColor color);

////////////////////////////////////////////////////////////
/// \brief Change the current active view of a render texture
///
/// \param renderTexture Render texture object
/// \param view          Pointer to the new view
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_SetView(sfRenderTexture* renderTexture, const sfView* view);

////////////////////////////////////////////////////////////
/// \brief Get the current active view of a render texture
///
/// \param renderTexture Render texture object
///
/// \return Current active view
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const sfView* sfRenderTexture_GetView(const sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Get the default view of a render texture
///
/// \param renderTexture Render texture object
///
/// \return Default view of the rendertexture
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const sfView* sfRenderTexture_GetDefaultView(const sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Get the viewport of a view applied to this target
///
/// \param renderTexture Render texture object
/// \param view          Target view
///
/// \return Viewport rectangle, expressed in pixels in the current target
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfIntRect sfRenderTexture_GetViewport(const sfRenderTexture* renderTexture, const sfView* view);

////////////////////////////////////////////////////////////
/// \brief Convert a point in texture coordinates into view coordinates
///
/// \param renderTexture Render texture object
/// \param windowX       X coordinate of the point to convert, relative to the texture
/// \param windowY       Y coordinate of the point to convert, relative to the texture
/// \param viewX         Pointer to fill with the X coordinate of the converted point
/// \param viewY         Pointer to fill with the Y coordinate of the converted point
/// \param targetView    Target view to convert the point to (pass NULL to use the current view)
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_ConvertCoords(const sfRenderTexture* renderTexture, unsigned int windowX, unsigned int windowY, float* viewX, float* viewY, const sfView* targetView);

////////////////////////////////////////////////////////////
/// \brief Draw a drawable object to the render-target
///
/// \param renderTexture Render texture object
/// \param object        Object to draw
/// \param states        Render states to use for drawing (NULL to use the default states)
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_DrawSprite(sfRenderTexture* renderTexture, const sfSprite* object, const sfRenderStates* states);
CSFML_GRAPHICS_API void sfRenderTexture_DrawText(sfRenderTexture* renderTexture, const sfText* object, const sfRenderStates* states);
CSFML_GRAPHICS_API void sfRenderTexture_DrawCircleShape(sfRenderTexture* renderTexture, const sfCircleShape* object, const sfRenderStates* states);
CSFML_GRAPHICS_API void sfRenderTexture_DrawConvexShape(sfRenderTexture* renderTexture, const sfConvexShape* object, const sfRenderStates* states);
CSFML_GRAPHICS_API void sfRenderTexture_DrawRectangleShape(sfRenderTexture* renderTexture, const sfRectangleShape* object, const sfRenderStates* states);
CSFML_GRAPHICS_API void sfRenderTexture_DrawVertexArray(sfRenderTexture* renderTexture, const sfVertexArray* object, const sfRenderStates* states);

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
CSFML_GRAPHICS_API void sfRenderTexture_DrawPrimitives(sfRenderTexture* renderTexture,
                                              const sfVertex* vertices, unsigned int vertexCount,
                                              sfPrimitiveType type, const sfRenderStates* states);

////////////////////////////////////////////////////////////
/// \brief Save the current OpenGL render states and matrices
///
/// This function can be used when you mix SFML drawing
/// and direct OpenGL rendering. Combined with PopGLStates,
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
/// saved and restored). Take a look at the ResetGLStates
/// function if you do so.
///
/// \param renderTexture Render texture object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_PushGLStates(sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Restore the previously saved OpenGL render states and matrices
///
/// See the description of PushGLStates to get a detailed
/// description of these functions.
///
/// \param renderTexture Render texture object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_PopGLStates(sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Reset the internal OpenGL states so that the target is ready for drawing
///
/// This function can be used when you mix SFML drawing
/// and direct OpenGL rendering, if you choose not to use
/// PushGLStates/PopGLStates. It makes sure that all OpenGL
/// states needed by SFML are set, so that subsequent sfRenderTexture_Draw*()
/// calls will work as expected.
///
/// \param renderTexture Render texture object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_ResetGLStates(sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Get the target texture of a render texture
///
/// \param renderTexture Render texture object
///
/// \return Pointer to the target texture
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const sfTexture* sfRenderTexture_GetTexture(const sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// \brief Enable or disable the smooth filter on a render texture
///
/// \param renderTexture Render texture object
/// \param smooth        sfTrue to enable smoothing, sfFalse to disable it
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderTexture_SetSmooth(sfRenderTexture* renderTexture, sfBool smooth);

////////////////////////////////////////////////////////////
/// \brief Tell whether the smooth filter is enabled or not for a render texture
///
/// \param renderTexture Render texture object
///
/// \return sfTrue if smoothing is enabled, sfFalse if it is disabled
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfBool sfRenderTexture_IsSmooth(const sfRenderTexture* renderTexture);


#endif // SFML_RENDERTEXTURE_H
