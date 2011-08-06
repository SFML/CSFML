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
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/RenderTextureStruct.h>
#include <SFML/Graphics/ShapeStruct.h>
#include <SFML/Graphics/ShaderStruct.h>
#include <SFML/Graphics/SpriteStruct.h>
#include <SFML/Graphics/TextStruct.h>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
/// Construct a new rendertexture
////////////////////////////////////////////////////////////
sfRenderTexture* sfRenderTexture_Create(unsigned int width, unsigned int height, sfBool depthBuffer)
{
    sfRenderTexture* renderTexture = new sfRenderTexture;
    renderTexture->This.Create(width, height, depthBuffer == sfTrue);
    renderTexture->Target = new sfTexture(const_cast<sf::Texture*>(&renderTexture->This.GetTexture()));
    renderTexture->DefaultView.This = renderTexture->This.GetDefaultView();
    renderTexture->CurrentView.This = renderTexture->This.GetView();

    return renderTexture;
}


////////////////////////////////////////////////////////////
/// Destroy an existing rendertexture
////////////////////////////////////////////////////////////
void sfRenderTexture_Destroy(sfRenderTexture* renderTexture)
{
    delete renderTexture->Target;
    delete renderTexture;
}


////////////////////////////////////////////////////////////
/// Get the width of the rendering region of a rendertexture
////////////////////////////////////////////////////////////
unsigned int sfRenderTexture_GetWidth(const sfRenderTexture* renderTexture)
{
    CSFML_CALL_RETURN(renderTexture, GetWidth(), 0);
}


////////////////////////////////////////////////////////////
/// Get the height of the rendering region of a rendertexture
////////////////////////////////////////////////////////////
unsigned int sfRenderTexture_GetHeight(const sfRenderTexture* renderTexture)
{
    CSFML_CALL_RETURN(renderTexture, GetHeight(), 0);
}


////////////////////////////////////////////////////////////
/// Set a rendertexture as the current target for rendering
////////////////////////////////////////////////////////////
sfBool sfRenderTexture_SetActive(sfRenderTexture* renderTexture, sfBool active)
{
    CSFML_CALL_RETURN(renderTexture, SetActive(active == sfTrue), sfFalse)
}


////////////////////////////////////////////////////////////
/// Save the current OpenGL render states and matrices
////////////////////////////////////////////////////////////
void sfRenderTexture_SaveGLStates(sfRenderTexture* renderTexture)
{
    CSFML_CALL(renderTexture, SaveGLStates());
}


////////////////////////////////////////////////////////////
/// Restore the previously saved OpenGL render states and matrices
////////////////////////////////////////////////////////////
void sfRenderTexture_RestoreGLStates(sfRenderTexture* renderTexture)
{
    CSFML_CALL(renderTexture, RestoreGLStates());
}


////////////////////////////////////////////////////////////
/// Update the contents of the target texture
////////////////////////////////////////////////////////////
void sfRenderTexture_Display(sfRenderTexture* renderTexture)
{
    CSFML_CALL(renderTexture, Display())
}


////////////////////////////////////////////////////////////
/// Draw something on a rendertexture
////////////////////////////////////////////////////////////
void sfRenderTexture_DrawSprite(sfRenderTexture* renderTexture, const sfSprite* sprite)
{
    CSFML_CHECK(sprite);
    CSFML_CALL(renderTexture, Draw(sprite->This));
}
void sfRenderTexture_DrawShape(sfRenderTexture* renderTexture, const sfShape* shape)
{
    CSFML_CHECK(shape);
    CSFML_CALL(renderTexture, Draw(shape->This));
}
void sfRenderTexture_DrawText(sfRenderTexture* renderTexture, const sfText* text)
{
    CSFML_CHECK(text);
    CSFML_CALL(renderTexture, Draw(text->This));
}


////////////////////////////////////////////////////////////
/// Draw something on a rendertexture with a shader
////////////////////////////////////////////////////////////
void sfRenderTexture_DrawSpriteWithShader(sfRenderTexture* renderTexture, const sfSprite* sprite, const sfShader* shader)
{
    CSFML_CHECK(sprite);
    CSFML_CHECK(shader);
    CSFML_CALL(renderTexture, Draw(sprite->This, shader->This));
}
void sfRenderTexture_DrawShapeWithShader(sfRenderTexture* renderTexture, const sfShape* shape, const sfShader* shader)
{
    CSFML_CHECK(shape);
    CSFML_CHECK(shader);
    CSFML_CALL(renderTexture, Draw(shape->This, shader->This));
}
void sfRenderTexture_DrawTextWithShader(sfRenderTexture* renderTexture, const sfText* text, const sfShader* shader)
{
    CSFML_CHECK(text);
    CSFML_CHECK(shader);
    CSFML_CALL(renderTexture, Draw(text->This, shader->This));
}


////////////////////////////////////////////////////////////
/// Clear the rendertexture with the given color
////////////////////////////////////////////////////////////
void sfRenderTexture_Clear(sfRenderTexture* renderTexture, sfColor color)
{
    sf::Color SFMLColor(color.r, color.g, color.b, color.a);

    CSFML_CALL(renderTexture, Clear(SFMLColor));
}


////////////////////////////////////////////////////////////
/// Change the current active view of a rendertexture
////////////////////////////////////////////////////////////
void sfRenderTexture_SetView(sfRenderTexture* renderTexture, const sfView* view)
{
    CSFML_CHECK(view);
    CSFML_CALL(renderTexture, SetView(view->This));
    renderTexture->CurrentView.This = view->This;
}


////////////////////////////////////////////////////////////
/// Get the current active view of a rendertexture
////////////////////////////////////////////////////////////
const sfView* sfRenderTexture_GetView(const sfRenderTexture* renderTexture)
{
    CSFML_CHECK_RETURN(renderTexture, NULL);

    return &renderTexture->CurrentView;
}


////////////////////////////////////////////////////////////
/// Get the default view of a rendertexture
////////////////////////////////////////////////////////////
const sfView* sfRenderTexture_GetDefaultView(const sfRenderTexture* renderTexture)
{
    CSFML_CHECK_RETURN(renderTexture, NULL);

    return &renderTexture->DefaultView;
}


////////////////////////////////////////////////////////////
/// Get the viewport of a view applied to this target
////////////////////////////////////////////////////////////
sfIntRect sfRenderTexture_GetViewport(const sfRenderTexture* renderTexture, const sfView* view)
{
    sfIntRect rect = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(view, rect);
    CSFML_CHECK_RETURN(renderTexture, rect);

    sf::IntRect SFMLrect = renderTexture->This.GetViewport(view->This);
    rect.Left   = SFMLrect.Left;
    rect.Top    = SFMLrect.Top;
    rect.Width  = SFMLrect.Width;
    rect.Height = SFMLrect.Height;

    return rect;
}


////////////////////////////////////////////////////////////
/// Convert a point in texture coordinates into view coordinates
////////////////////////////////////////////////////////////
void sfRenderTexture_ConvertCoords(const sfRenderTexture* renderTexture, unsigned int textureX, unsigned int textureY, float* viewX, float* viewY, const sfView* targetView)
{
    CSFML_CHECK(renderTexture);

    sf::Vector2f point;
    if (targetView)
        point = renderTexture->This.ConvertCoords(textureX, textureY, targetView->This);
    else
        point = renderTexture->This.ConvertCoords(textureX, textureY);

    if (viewX) *viewX = point.x;
    if (viewY) *viewY = point.y;
}


////////////////////////////////////////////////////////////
/// Get the target texture
////////////////////////////////////////////////////////////
const sfTexture* sfRenderTexture_GetTexture(const sfRenderTexture* renderTexture)
{
    CSFML_CHECK_RETURN(renderTexture, NULL);

    return renderTexture->Target;
}
