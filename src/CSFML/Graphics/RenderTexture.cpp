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
#include <CSFML/Graphics/RenderTexture.h>
#include <CSFML/Graphics/RenderTextureStruct.hpp>
#include <CSFML/Graphics/SpriteStruct.hpp>
#include <CSFML/Graphics/TextStruct.hpp>
#include <CSFML/Graphics/ShapeStruct.hpp>
#include <CSFML/Graphics/CircleShapeStruct.hpp>
#include <CSFML/Graphics/ConvexShapeStruct.hpp>
#include <CSFML/Graphics/RectangleShapeStruct.hpp>
#include <CSFML/Graphics/VertexArrayStruct.hpp>
#include <CSFML/Graphics/VertexBufferStruct.hpp>
#include <CSFML/Graphics/ConvertRenderStates.hpp>
#include <CSFML/Internal.hpp>
#include <CSFML/Window/ContextSettingsInternal.hpp>


////////////////////////////////////////////////////////////
sfRenderTexture* sfRenderTexture_create(unsigned int width, unsigned int height, const sfContextSettings* settings)
{
    // Convert context settings
    sf::ContextSettings params;
    if (settings)
    {
        priv::sfContextSettings_writeToCpp(*settings, params);
    }

    // Create the render texture
    sf::RenderTexture renderTexture;
    if (!renderTexture.resize({ width, height }, params))
        return nullptr;

    auto* texture  = new sfTexture(const_cast<sf::Texture*>(&renderTexture.getTexture()));
    const auto defaultView = sfView{renderTexture.getDefaultView()};
    const auto currentView = sfView{renderTexture.getView()};

    return new sfRenderTexture{std::move(renderTexture), texture, defaultView, currentView};
}


////////////////////////////////////////////////////////////
void sfRenderTexture_destroy(sfRenderTexture* renderTexture)
{
    delete renderTexture->Target;
    delete renderTexture;
}


////////////////////////////////////////////////////////////
sfVector2u sfRenderTexture_getSize(const sfRenderTexture* renderTexture)
{
    sfVector2u size = {0, 0};
    CSFML_CHECK_RETURN(renderTexture, size);

    sf::Vector2u sfmlSize = renderTexture->This.getSize();
    size.x = sfmlSize.x;
    size.y = sfmlSize.y;

    return size;
}


////////////////////////////////////////////////////////////
bool sfRenderTexture_isSrgb(const sfRenderTexture* renderTexture)
{
    CSFML_CHECK_RETURN(renderTexture, false);
    return renderTexture->This.isSrgb();
}


////////////////////////////////////////////////////////////
bool sfRenderTexture_setActive(sfRenderTexture* renderTexture, bool active)
{
    CSFML_CALL_RETURN(renderTexture, setActive(active), false);
}


////////////////////////////////////////////////////////////
void sfRenderTexture_display(sfRenderTexture* renderTexture)
{
    CSFML_CALL(renderTexture, display());
}


////////////////////////////////////////////////////////////
void sfRenderTexture_clear(sfRenderTexture* renderTexture, sfColor color)
{
    sf::Color SFMLColor(color.r, color.g, color.b, color.a);

    CSFML_CALL(renderTexture, clear(SFMLColor));
}


////////////////////////////////////////////////////////////
void sfRenderTexture_setView(sfRenderTexture* renderTexture, const sfView* view)
{
    CSFML_CHECK(view);
    CSFML_CALL(renderTexture, setView(view->This));
    renderTexture->CurrentView.This = view->This;
}


////////////////////////////////////////////////////////////
const sfView* sfRenderTexture_getView(const sfRenderTexture* renderTexture)
{
    CSFML_CHECK_RETURN(renderTexture, nullptr);

    return &renderTexture->CurrentView;
}


////////////////////////////////////////////////////////////
const sfView* sfRenderTexture_getDefaultView(const sfRenderTexture* renderTexture)
{
    CSFML_CHECK_RETURN(renderTexture, nullptr);

    return &renderTexture->DefaultView;
}


////////////////////////////////////////////////////////////
sfIntRect sfRenderTexture_getViewport(const sfRenderTexture* renderTexture, const sfView* view)
{
    sfIntRect rect = {{0, 0}, {0, 0}};
    CSFML_CHECK_RETURN(view, rect);
    CSFML_CHECK_RETURN(renderTexture, rect);

    sf::IntRect SFMLrect = renderTexture->This.getViewport(view->This);
    rect.position.x = SFMLrect.position.x;
    rect.position.y = SFMLrect.position.y;
    rect.size.x     = SFMLrect.size.x;
    rect.size.y     = SFMLrect.size.y;

    return rect;
}


////////////////////////////////////////////////////////////
sfVector2f sfRenderTexture_mapPixelToCoords(const sfRenderTexture* renderTexture, sfVector2i point, const sfView* targetView)
{
    sfVector2f result = {0, 0};
    CSFML_CHECK_RETURN(renderTexture, result);

    sf::Vector2f sfmlPoint;
    if (targetView)
        sfmlPoint = renderTexture->This.mapPixelToCoords(sf::Vector2i(point.x, point.y), targetView->This);
    else
        sfmlPoint = renderTexture->This.mapPixelToCoords(sf::Vector2i(point.x, point.y));

    result.x = sfmlPoint.x;
    result.y = sfmlPoint.y;

    return result;
}


////////////////////////////////////////////////////////////
sfVector2i sfRenderTexture_mapCoordsToPixel(const sfRenderTexture* renderTexture, sfVector2f point, const sfView* targetView)
{
    sfVector2i result = {0, 0};
    CSFML_CHECK_RETURN(renderTexture, result);

    sf::Vector2i sfmlPoint;
    if (targetView)
        sfmlPoint = renderTexture->This.mapCoordsToPixel(sf::Vector2f(point.x, point.y), targetView->This);
    else
        sfmlPoint = renderTexture->This.mapCoordsToPixel(sf::Vector2f(point.x, point.y));

    result.x = sfmlPoint.x;
    result.y = sfmlPoint.y;

    return result;
}


////////////////////////////////////////////////////////////
void sfRenderTexture_drawSprite(sfRenderTexture* renderTexture, const sfSprite* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderTexture, draw(object->This, convertRenderStates(states)));
}
void sfRenderTexture_drawText(sfRenderTexture* renderTexture, const sfText* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderTexture, draw(object->This, convertRenderStates(states)));
}
void sfRenderTexture_drawShape(sfRenderTexture* renderTexture, const sfShape* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderTexture, draw(object->This, convertRenderStates(states)));
}
void sfRenderTexture_drawCircleShape(sfRenderTexture* renderTexture, const sfCircleShape* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderTexture, draw(object->This, convertRenderStates(states)));
}
void sfRenderTexture_drawConvexShape(sfRenderTexture* renderTexture, const sfConvexShape* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderTexture, draw(object->This, convertRenderStates(states)));
}
void sfRenderTexture_drawRectangleShape(sfRenderTexture* renderTexture, const sfRectangleShape* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderTexture, draw(object->This, convertRenderStates(states)));
}
void sfRenderTexture_drawVertexArray(sfRenderTexture* renderTexture, const sfVertexArray* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderTexture, draw(object->This, convertRenderStates(states)));
}
void sfRenderTexture_drawVertexBuffer(sfRenderTexture* renderTexture, const sfVertexBuffer* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderTexture, draw(object->This, convertRenderStates(states)));
}


////////////////////////////////////////////////////////////
void sfRenderTexture_drawVertexBufferRange(sfRenderTexture* renderTexture,
                                           const sfVertexBuffer* object, size_t firstVertex,
                                           size_t vertexCount, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderTexture, draw(object->This, firstVertex, vertexCount, convertRenderStates(states)));
}


////////////////////////////////////////////////////////////
void sfRenderTexture_drawPrimitives(sfRenderTexture* renderTexture,
                                    const sfVertex* vertices, size_t vertexCount,
                                    sfPrimitiveType type, const sfRenderStates* states)
{
    CSFML_CALL(renderTexture, draw(reinterpret_cast<const sf::Vertex*>(vertices), vertexCount,
               static_cast<sf::PrimitiveType>(type), convertRenderStates(states)));
}


////////////////////////////////////////////////////////////
void sfRenderTexture_pushGLStates(sfRenderTexture* renderTexture)
{
    CSFML_CALL(renderTexture, pushGLStates());
}


////////////////////////////////////////////////////////////
void sfRenderTexture_popGLStates(sfRenderTexture* renderTexture)
{
    CSFML_CALL(renderTexture, popGLStates());
}


////////////////////////////////////////////////////////////
void sfRenderTexture_resetGLStates(sfRenderTexture* renderTexture)
{
    CSFML_CALL(renderTexture, resetGLStates());
}


////////////////////////////////////////////////////////////
const sfTexture* sfRenderTexture_getTexture(const sfRenderTexture* renderTexture)
{
    CSFML_CHECK_RETURN(renderTexture, nullptr);

    return renderTexture->Target;
}


////////////////////////////////////////////////////////////
void sfRenderTexture_setSmooth(sfRenderTexture* renderTexture, bool smooth)
{
    CSFML_CALL(renderTexture, setSmooth(smooth));
}


////////////////////////////////////////////////////////////
unsigned int sfRenderTexture_getMaximumAntialiasingLevel()
{
    return sf::RenderTexture::getMaximumAntialiasingLevel();
}


////////////////////////////////////////////////////////////
bool sfRenderTexture_isSmooth(const sfRenderTexture* renderTexture)
{
    CSFML_CALL_RETURN(renderTexture, isSmooth(), false);
}

////////////////////////////////////////////////////////////
void sfRenderTexture_setRepeated(sfRenderTexture* renderTexture, bool repeated)
{
    CSFML_CALL(renderTexture, setRepeated(repeated));
}


////////////////////////////////////////////////////////////
bool sfRenderTexture_isRepeated(const sfRenderTexture* renderTexture)
{
    CSFML_CALL_RETURN(renderTexture, isRepeated(), false);
}


////////////////////////////////////////////////////////////
bool sfRenderTexture_generateMipmap(sfRenderTexture* renderTexture)
{
    CSFML_CALL_RETURN(renderTexture, generateMipmap(), false);
}
