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
#include <SFML/Config.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>


////////////////////////////////////////////////////////////
/// Construct a new rendertexture
///
/// \param width :       Width of the rendertexture
/// \param height :      Height of the rendertexture
/// \param depthBuffer : Do you want a depth-buffer attached? (useful only if you're doing 3D OpenGL on the rendertexture)
///
////////////////////////////////////////////////////////////
CSFML_API sfRenderTexture* sfRenderTexture_Create(unsigned int width, unsigned int height, sfBool depthBuffer);

////////////////////////////////////////////////////////////
/// Destroy an existing rendertexture
///
/// \param renderTexture : rendertexture to destroy
///
////////////////////////////////////////////////////////////
CSFML_API void sfRenderTexture_Destroy(sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// Get the width of the rendering region of a rendertexture
///
/// \param renderTexture : Rendertexture object
///
/// \return Width in pixels
///
////////////////////////////////////////////////////////////
CSFML_API unsigned int sfRenderTexture_GetWidth(const sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// Get the height of the rendering region of a rendertexture
///
/// \param renderTexture : Rendertexture object
///
/// \return Height in pixels
///
////////////////////////////////////////////////////////////
CSFML_API unsigned int sfRenderTexture_GetHeight(const sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// Activate or deactivate a rendertexture as the current target for rendering
///
/// \param renderTexture : Rendertexture object
/// \param active :      sfTrue to activate, sfFalse to deactivate
///
/// \return True if operation was successful, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_API sfBool sfRenderTexture_SetActive(sfRenderTexture* renderTexture, sfBool active);

////////////////////////////////////////////////////////////
/// Save the current OpenGL render states and matrices
///
/// \param renderWindow : Renderwindow object
///
////////////////////////////////////////////////////////////
CSFML_API void sfRenderTexture_SaveGLStates(sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// Restore the previously saved OpenGL render states and matrices
///
/// \param renderWindow : Renderwindow object
///
////////////////////////////////////////////////////////////
CSFML_API void sfRenderTexture_RestoreGLStates(sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// Update the contents of the target texture
///
/// \param renderTexture : Rendertexture object
///
////////////////////////////////////////////////////////////
CSFML_API void sfRenderTexture_Display(sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// Draw something on a rendertexture
///
/// \param renderTexture :           Rendertexture to draw in
/// \param sprite / text / shape : Object to draw
///
////////////////////////////////////////////////////////////
CSFML_API void sfRenderTexture_DrawSprite(sfRenderTexture* renderTexture, const sfSprite* sprite);
CSFML_API void sfRenderTexture_DrawShape (sfRenderTexture* renderTexture, const sfShape*  shape);
CSFML_API void sfRenderTexture_DrawText  (sfRenderTexture* renderTexture, const sfText*   text);

////////////////////////////////////////////////////////////
/// Draw something on a rendertexture with a shader
///
/// \param renderTexture :           Rendertexture to draw in
/// \param sprite / text / shape : Object to draw
/// \param shader :                Shader to use
///
////////////////////////////////////////////////////////////
CSFML_API void sfRenderTexture_DrawSpriteWithShader(sfRenderTexture* renderTexture, const sfSprite* sprite, const sfShader* shader);
CSFML_API void sfRenderTexture_DrawShapeWithShader (sfRenderTexture* renderTexture, const sfShape*  shape,  const sfShader* shader);
CSFML_API void sfRenderTexture_DrawTextWithShader  (sfRenderTexture* renderTexture, const sfText*   text,   const sfShader* shader);

////////////////////////////////////////////////////////////
/// Clear the rendertexture with the given color
///
/// \param renderTexture : Rendertexture to modify
/// \param color :       Fill color
///
////////////////////////////////////////////////////////////
CSFML_API void sfRenderTexture_Clear(sfRenderTexture* renderTexture, sfColor color);

////////////////////////////////////////////////////////////
/// Change the current active view of a rendertexture
///
/// \param renderTexture : Rendertexture to modify
/// \param view :        Pointer to the new view
///
////////////////////////////////////////////////////////////
CSFML_API void sfRenderTexture_SetView(sfRenderTexture* renderTexture, const sfView* view);

////////////////////////////////////////////////////////////
/// Get the current active view of a rendertexture
///
/// \param renderTexture : Rendertexture
///
/// \return Current active view
///
////////////////////////////////////////////////////////////
CSFML_API const sfView* sfRenderTexture_GetView(const sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// Get the default view of a rendertexture
///
/// \param renderTexture : Rendertexture
///
/// \return Default view of the rendertexture
///
////////////////////////////////////////////////////////////
CSFML_API const sfView* sfRenderTexture_GetDefaultView(const sfRenderTexture* renderTexture);

////////////////////////////////////////////////////////////
/// Get the viewport of a view applied to this target
///
/// \param renderTexture : Rendertexture object
/// \param view :        Target view
///
/// \return Viewport rectangle, expressed in pixels in the current target
///
////////////////////////////////////////////////////////////
CSFML_API sfIntRect sfRenderTexture_GetViewport(const sfRenderTexture* renderTexture, const sfView* view);

////////////////////////////////////////////////////////////
/// Convert a point in texture coordinates into view coordinates
///
/// \param renderTexture : Rendertexture object
/// \param windowX :     X coordinate of the point to convert, relative to the texture
/// \param windowY :     Y coordinate of the point to convert, relative to the texture
/// \param viewX :       Pointer to fill with the X coordinate of the converted point
/// \param viewY :       Pointer to fill with the Y coordinate of the converted point
/// \param targetView :  Target view to convert the point to (pass NULL to use the current view)
///
////////////////////////////////////////////////////////////
CSFML_API void sfRenderTexture_ConvertCoords(const sfRenderTexture* renderTexture, unsigned int windowX, unsigned int windowY, float* viewX, float* viewY, const sfView* targetView);

////////////////////////////////////////////////////////////
/// Get the target texture
///
/// \param renderTexture : Render-texture object
///
/// \return Pointer to the target texture
///
////////////////////////////////////////////////////////////
CSFML_API const sfTexture* sfRenderTexture_GetTexture(const sfRenderTexture* renderTexture);


#endif // SFML_RENDERTEXTURE_H
