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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Graphics/CircleShapeStruct.hpp>
#include <CSFML/Graphics/ConvertColor.hpp>
#include <CSFML/Graphics/ConvertRect.hpp>
#include <CSFML/Graphics/ConvertRenderStates.hpp>
#include <CSFML/Graphics/ConvertStencil.hpp>
#include <CSFML/Graphics/ConvexShapeStruct.hpp>
#include <CSFML/Graphics/RectangleShapeStruct.hpp>
#include <CSFML/Graphics/RenderTexture.h>
#include <CSFML/Graphics/RenderTextureStruct.hpp>
#include <CSFML/Graphics/ShapeStruct.hpp>
#include <CSFML/Graphics/SpriteStruct.hpp>
#include <CSFML/Graphics/TextStruct.hpp>
#include <CSFML/Graphics/VertexArrayStruct.hpp>
#include <CSFML/Graphics/VertexBufferStruct.hpp>
#include <CSFML/System/ConvertVector2.hpp>
#include <CSFML/Window/ConvertContextSettings.hpp>


////////////////////////////////////////////////////////////
sfRenderTexture* sfRenderTexture_create(sfVector2u size, const sfContextSettings* settings)
{
    // Convert context settings
    const sf::ContextSettings params = settings ? convertContextSettings(*settings) : sf::ContextSettings();

    // Create the render texture
    auto renderTexture = std::make_unique<sfRenderTexture>();
    if (!renderTexture->resize(convertVector2(size), params))
        return nullptr;

    renderTexture->Target      = std::make_unique<sfTexture>(const_cast<sf::Texture*>(&renderTexture->getTexture()));
    renderTexture->DefaultView = sfView{renderTexture->getDefaultView()};
    renderTexture->CurrentView = sfView{renderTexture->getView()};

    return renderTexture.release();
}


////////////////////////////////////////////////////////////
void sfRenderTexture_destroy(const sfRenderTexture* renderTexture)
{
    delete renderTexture;
}


////////////////////////////////////////////////////////////
sfVector2u sfRenderTexture_getSize(const sfRenderTexture* renderTexture)
{
    assert(renderTexture);
    return convertVector2(renderTexture->getSize());
}


////////////////////////////////////////////////////////////
bool sfRenderTexture_isSrgb(const sfRenderTexture* renderTexture)
{
    assert(renderTexture);
    return renderTexture->isSrgb();
}


////////////////////////////////////////////////////////////
bool sfRenderTexture_setActive(sfRenderTexture* renderTexture, bool active)
{
    assert(renderTexture);
    return renderTexture->setActive(active);
}


////////////////////////////////////////////////////////////
void sfRenderTexture_display(sfRenderTexture* renderTexture)
{
    assert(renderTexture);
    renderTexture->display();
}


////////////////////////////////////////////////////////////
void sfRenderTexture_clear(sfRenderTexture* renderTexture, sfColor color)
{
    assert(renderTexture);
    renderTexture->clear(convertColor(color));
}


////////////////////////////////////////////////////////////
void sfRenderTexture_clearStencil(sfRenderTexture* renderTexture, sfStencilValue stencilValue)
{
    assert(renderTexture);
    renderTexture->clearStencil(convertStencilValue(stencilValue));
}


////////////////////////////////////////////////////////////
void sfRenderTexture_clearColorAndStencil(sfRenderTexture* renderTexture, sfColor color, sfStencilValue stencilValue)
{
    assert(renderTexture);
    renderTexture->clear(convertColor(color), convertStencilValue(stencilValue));
}


////////////////////////////////////////////////////////////
void sfRenderTexture_setView(sfRenderTexture* renderTexture, const sfView* view)
{
    assert(renderTexture);
    assert(view);
    renderTexture->setView(*view);
    renderTexture->CurrentView = *view;
}


////////////////////////////////////////////////////////////
const sfView* sfRenderTexture_getView(const sfRenderTexture* renderTexture)
{
    assert(renderTexture);
    return &renderTexture->CurrentView;
}


////////////////////////////////////////////////////////////
const sfView* sfRenderTexture_getDefaultView(const sfRenderTexture* renderTexture)
{
    assert(renderTexture);
    return &renderTexture->DefaultView;
}


////////////////////////////////////////////////////////////
sfIntRect sfRenderTexture_getViewport(const sfRenderTexture* renderTexture, const sfView* view)
{
    assert(renderTexture);
    assert(view);
    return convertRect(renderTexture->getViewport(*view));
}


////////////////////////////////////////////////////////////
sfIntRect sfRenderTexture_getScissor(const sfRenderTexture* renderTexture, const sfView* view)
{
    assert(renderTexture);
    assert(view);
    return convertRect(renderTexture->getScissor(*view));
}


////////////////////////////////////////////////////////////
sfVector2f sfRenderTexture_mapPixelToCoords(const sfRenderTexture* renderTexture, sfVector2i point, const sfView* targetView)
{
    assert(renderTexture);

    if (targetView)
        return convertVector2(renderTexture->mapPixelToCoords(convertVector2(point), *targetView));

    return convertVector2(renderTexture->mapPixelToCoords(convertVector2(point)));
}


////////////////////////////////////////////////////////////
sfVector2i sfRenderTexture_mapCoordsToPixel(const sfRenderTexture* renderTexture, sfVector2f point, const sfView* targetView)
{
    assert(renderTexture);

    if (targetView)
        return convertVector2(renderTexture->mapCoordsToPixel(convertVector2(point), *targetView));

    return convertVector2(renderTexture->mapCoordsToPixel(convertVector2(point)));
}


////////////////////////////////////////////////////////////
void sfRenderTexture_drawSprite(sfRenderTexture* renderTexture, const sfSprite* object, const sfRenderStates* states)
{
    assert(renderTexture);
    assert(object);
    renderTexture->draw(*object, convertRenderStates(states));
}
void sfRenderTexture_drawText(sfRenderTexture* renderTexture, const sfText* object, const sfRenderStates* states)
{
    assert(renderTexture);
    assert(object);
    renderTexture->draw(*object, convertRenderStates(states));
}
void sfRenderTexture_drawShape(sfRenderTexture* renderTexture, const sfShape* object, const sfRenderStates* states)
{
    assert(renderTexture);
    assert(object);
    renderTexture->draw(*object, convertRenderStates(states));
}
void sfRenderTexture_drawCircleShape(sfRenderTexture* renderTexture, const sfCircleShape* object, const sfRenderStates* states)
{
    assert(renderTexture);
    assert(object);
    renderTexture->draw(*object, convertRenderStates(states));
}
void sfRenderTexture_drawConvexShape(sfRenderTexture* renderTexture, const sfConvexShape* object, const sfRenderStates* states)
{
    assert(renderTexture);
    assert(object);
    renderTexture->draw(*object, convertRenderStates(states));
}
void sfRenderTexture_drawRectangleShape(sfRenderTexture* renderTexture, const sfRectangleShape* object, const sfRenderStates* states)
{
    assert(renderTexture);
    assert(object);
    renderTexture->draw(*object, convertRenderStates(states));
}
void sfRenderTexture_drawVertexArray(sfRenderTexture* renderTexture, const sfVertexArray* object, const sfRenderStates* states)
{
    assert(renderTexture);
    assert(object);
    renderTexture->draw(*object, convertRenderStates(states));
}
void sfRenderTexture_drawVertexBuffer(sfRenderTexture* renderTexture, const sfVertexBuffer* object, const sfRenderStates* states)
{
    assert(renderTexture);
    assert(object);
    renderTexture->draw(*object, convertRenderStates(states));
}


////////////////////////////////////////////////////////////
void sfRenderTexture_drawVertexBufferRange(sfRenderTexture*      renderTexture,
                                           const sfVertexBuffer* object,
                                           size_t                firstVertex,
                                           size_t                vertexCount,
                                           const sfRenderStates* states)
{
    assert(renderTexture);
    assert(object);
    renderTexture->draw(*object, firstVertex, vertexCount, convertRenderStates(states));
}


////////////////////////////////////////////////////////////
void sfRenderTexture_drawPrimitives(sfRenderTexture*      renderTexture,
                                    const sfVertex*       vertices,
                                    size_t                vertexCount,
                                    sfPrimitiveType       type,
                                    const sfRenderStates* states)
{
    assert(renderTexture);
    renderTexture->draw(reinterpret_cast<const sf::Vertex*>(vertices),
                        vertexCount,
                        static_cast<sf::PrimitiveType>(type),
                        convertRenderStates(states));
}


////////////////////////////////////////////////////////////
void sfRenderTexture_pushGLStates(sfRenderTexture* renderTexture)
{
    assert(renderTexture);
    renderTexture->pushGLStates();
}


////////////////////////////////////////////////////////////
void sfRenderTexture_popGLStates(sfRenderTexture* renderTexture)
{
    assert(renderTexture);
    renderTexture->popGLStates();
}


////////////////////////////////////////////////////////////
void sfRenderTexture_resetGLStates(sfRenderTexture* renderTexture)
{
    assert(renderTexture);
    renderTexture->resetGLStates();
}


////////////////////////////////////////////////////////////
const sfTexture* sfRenderTexture_getTexture(const sfRenderTexture* renderTexture)
{
    assert(renderTexture);
    return renderTexture->Target.get();
}


////////////////////////////////////////////////////////////
void sfRenderTexture_setSmooth(sfRenderTexture* renderTexture, bool smooth)
{
    assert(renderTexture);
    renderTexture->setSmooth(smooth);
}


////////////////////////////////////////////////////////////
unsigned int sfRenderTexture_getMaximumAntiAliasingLevel()
{
    return sf::RenderTexture::getMaximumAntiAliasingLevel();
}


////////////////////////////////////////////////////////////
bool sfRenderTexture_isSmooth(const sfRenderTexture* renderTexture)
{
    assert(renderTexture);
    return renderTexture->isSmooth();
}

////////////////////////////////////////////////////////////
void sfRenderTexture_setRepeated(sfRenderTexture* renderTexture, bool repeated)
{
    assert(renderTexture);
    renderTexture->setRepeated(repeated);
}


////////////////////////////////////////////////////////////
bool sfRenderTexture_isRepeated(const sfRenderTexture* renderTexture)
{
    assert(renderTexture);
    return renderTexture->isRepeated();
}


////////////////////////////////////////////////////////////
bool sfRenderTexture_generateMipmap(sfRenderTexture* renderTexture)
{
    assert(renderTexture);
    return renderTexture->generateMipmap();
}
