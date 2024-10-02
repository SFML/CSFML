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
#include <CSFML/Graphics/ImageStruct.hpp>
#include <CSFML/Graphics/RectangleShapeStruct.hpp>
#include <CSFML/Graphics/RenderWindow.h>
#include <CSFML/Graphics/RenderWindowStruct.hpp>
#include <CSFML/Graphics/ShapeStruct.hpp>
#include <CSFML/Graphics/SpriteStruct.hpp>
#include <CSFML/Graphics/TextStruct.hpp>
#include <CSFML/Graphics/VertexArrayStruct.hpp>
#include <CSFML/Graphics/VertexBufferStruct.hpp>
#include <CSFML/System/ConvertVector2.hpp>
#include <CSFML/Window/ConvertContextSettings.hpp>
#include <CSFML/Window/ConvertEvent.hpp>
#include <CSFML/Window/ConvertVideoMode.hpp>
#include <CSFML/Window/CursorStruct.hpp>

#include <SFML/Window/Touch.hpp>


////////////////////////////////////////////////////////////
sfRenderWindow* sfRenderWindow_create(sfVideoMode              mode,
                                      const char*              title,
                                      uint32_t                 style,
                                      sfWindowState            state,
                                      const sfContextSettings* settings)
{
    // Convert context settings
    const sf::ContextSettings params = settings ? convertContextSettings(*settings) : sf::ContextSettings();

    // Create the window
    auto* renderWindow = new sfRenderWindow;
    renderWindow->create(convertVideoMode(mode), title, style, static_cast<sf::State>(state), params);
    renderWindow->DefaultView = sfView{renderWindow->getDefaultView()};
    renderWindow->CurrentView = sfView{renderWindow->getView()};

    return renderWindow;
}

////////////////////////////////////////////////////////////
sfRenderWindow* sfRenderWindow_createUnicode(
    sfVideoMode              mode,
    const sfChar32*          title,
    uint32_t                 style,
    sfWindowState            state,
    const sfContextSettings* settings)
{
    // Convert context settings
    const sf::ContextSettings params = settings ? convertContextSettings(*settings) : sf::ContextSettings();

    // Create the window
    auto* renderWindow = new sfRenderWindow;
    renderWindow->create(convertVideoMode(mode),
                         reinterpret_cast<const char32_t*>(title),
                         style,
                         static_cast<sf::State>(state),
                         params);
    renderWindow->DefaultView = sfView{renderWindow->getDefaultView()};
    renderWindow->CurrentView = sfView{renderWindow->getView()};

    return renderWindow;
}


////////////////////////////////////////////////////////////
sfRenderWindow* sfRenderWindow_createFromHandle(sfWindowHandle handle, const sfContextSettings* settings)
{
    // Convert context settings
    const sf::ContextSettings params = settings ? convertContextSettings(*settings) : sf::ContextSettings();

    // Create the window
    auto* renderWindow = new sfRenderWindow;
    renderWindow->create(handle, params);
    renderWindow->DefaultView = sfView{renderWindow->getDefaultView()};
    renderWindow->CurrentView = sfView{renderWindow->getView()};

    return renderWindow;
}


////////////////////////////////////////////////////////////
void sfRenderWindow_destroy(const sfRenderWindow* renderWindow)
{
    delete renderWindow;
}


////////////////////////////////////////////////////////////
void sfRenderWindow_close(sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    renderWindow->close();
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_isOpen(const sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    return renderWindow->isOpen();
}


////////////////////////////////////////////////////////////
sfContextSettings sfRenderWindow_getSettings(const sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    return convertContextSettings(renderWindow->getSettings());
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_pollEvent(sfRenderWindow* renderWindow, sfEvent* event)
{
    assert(renderWindow);
    assert(event);
    return convertEvent(renderWindow->pollEvent(), *event);
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_waitEvent(sfRenderWindow* renderWindow, sfTime timeout, sfEvent* event)
{
    assert(renderWindow);
    assert(event);
    return convertEvent(renderWindow->waitEvent(sf::microseconds(timeout.microseconds)), *event);
}


////////////////////////////////////////////////////////////
sfVector2i sfRenderWindow_getPosition(const sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    return convertVector2(renderWindow->getPosition());
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setPosition(sfRenderWindow* renderWindow, sfVector2i position)
{
    assert(renderWindow);
    renderWindow->setPosition(convertVector2(position));
}


////////////////////////////////////////////////////////////
sfVector2u sfRenderWindow_getSize(const sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    return convertVector2(renderWindow->getSize());
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_isSrgb(const sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    return renderWindow->isSrgb();
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setSize(sfRenderWindow* renderWindow, sfVector2u size)
{
    assert(renderWindow);
    renderWindow->setSize(convertVector2(size));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setTitle(sfRenderWindow* renderWindow, const char* title)
{
    assert(renderWindow);
    renderWindow->setTitle(title);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setUnicodeTitle(sfRenderWindow* renderWindow, const sfChar32* title)
{
    assert(renderWindow);
    renderWindow->setTitle(reinterpret_cast<const char32_t*>(title));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setIcon(sfRenderWindow* renderWindow, sfVector2u size, const uint8_t* pixels)
{
    assert(renderWindow);
    renderWindow->setIcon(convertVector2(size), pixels);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setVisible(sfRenderWindow* renderWindow, bool visible)
{
    assert(renderWindow);
    renderWindow->setVisible(visible);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setVerticalSyncEnabled(sfRenderWindow* renderWindow, bool enabled)
{
    assert(renderWindow);
    renderWindow->setVerticalSyncEnabled(enabled);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setMouseCursorVisible(sfRenderWindow* renderWindow, bool visible)
{
    assert(renderWindow);
    renderWindow->setMouseCursorVisible(visible);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setMouseCursorGrabbed(sfRenderWindow* renderWindow, bool grabbed)
{
    assert(renderWindow);
    renderWindow->setMouseCursorGrabbed(grabbed);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setMouseCursor(sfRenderWindow* renderWindow, const sfCursor* cursor)
{
    assert(renderWindow);
    assert(cursor);
    renderWindow->setMouseCursor(*cursor);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setKeyRepeatEnabled(sfRenderWindow* renderWindow, bool enabled)
{
    assert(renderWindow);
    renderWindow->setKeyRepeatEnabled(enabled);
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_setActive(sfRenderWindow* renderWindow, bool active)
{
    assert(renderWindow);
    return renderWindow->setActive(active);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_requestFocus(sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    renderWindow->requestFocus();
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_hasFocus(const sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    return renderWindow->hasFocus();
}


////////////////////////////////////////////////////////////
void sfRenderWindow_display(sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    renderWindow->display();
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setFramerateLimit(sfRenderWindow* renderWindow, unsigned int limit)
{
    assert(renderWindow);
    renderWindow->setFramerateLimit(limit);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setJoystickThreshold(sfRenderWindow* renderWindow, float threshold)
{
    assert(renderWindow);
    renderWindow->setJoystickThreshold(threshold);
}


////////////////////////////////////////////////////////////
sfWindowHandle sfRenderWindow_getNativeHandle(const sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    return static_cast<sfWindowHandle>(renderWindow->getNativeHandle());
}


////////////////////////////////////////////////////////////
void sfRenderWindow_clear(sfRenderWindow* renderWindow, sfColor color)
{
    assert(renderWindow);
    renderWindow->clear(convertColor(color));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_clearStencil(sfRenderWindow* renderWindow, sfStencilValue stencilValue)
{
    assert(renderWindow);
    renderWindow->clearStencil(convertStencilValue(stencilValue));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_clearColorAndStencil(sfRenderWindow* renderWindow, sfColor color, sfStencilValue stencilValue)
{
    assert(renderWindow);
    renderWindow->clear(convertColor(color), convertStencilValue(stencilValue));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setView(sfRenderWindow* renderWindow, const sfView* view)
{
    assert(renderWindow);
    assert(view);
    renderWindow->setView(*view);
    renderWindow->CurrentView = *view;
}


////////////////////////////////////////////////////////////
const sfView* sfRenderWindow_getView(const sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    return &renderWindow->CurrentView;
}


////////////////////////////////////////////////////////////
const sfView* sfRenderWindow_getDefaultView(const sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    return &renderWindow->DefaultView;
}


////////////////////////////////////////////////////////////
sfIntRect sfRenderWindow_getViewport(const sfRenderWindow* renderWindow, const sfView* view)
{
    assert(renderWindow);
    assert(view);
    return convertRect(renderWindow->getViewport(*view));
}


////////////////////////////////////////////////////////////
sfIntRect sfRenderWindow_getScissor(const sfRenderWindow* renderWindow, const sfView* view)
{
    assert(renderWindow);
    assert(view);
    return convertRect(renderWindow->getScissor(*view));
}


////////////////////////////////////////////////////////////
sfVector2f sfRenderWindow_mapPixelToCoords(const sfRenderWindow* renderWindow, sfVector2i point, const sfView* targetView)
{
    assert(renderWindow);

    if (targetView)
        return convertVector2(renderWindow->mapPixelToCoords(convertVector2(point), *targetView));

    return convertVector2(renderWindow->mapPixelToCoords(convertVector2(point)));
}


////////////////////////////////////////////////////////////
sfVector2i sfRenderWindow_mapCoordsToPixel(const sfRenderWindow* renderWindow, sfVector2f point, const sfView* targetView)
{
    assert(renderWindow);

    if (targetView)
        return convertVector2(renderWindow->mapCoordsToPixel(convertVector2(point), *targetView));

    return convertVector2(renderWindow->mapCoordsToPixel(convertVector2(point)));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_drawSprite(sfRenderWindow* renderWindow, const sfSprite* object, const sfRenderStates* states)
{
    assert(renderWindow);
    assert(object);
    renderWindow->draw(*object, convertRenderStates(states));
}
void sfRenderWindow_drawText(sfRenderWindow* renderWindow, const sfText* object, const sfRenderStates* states)
{
    assert(renderWindow);
    assert(object);
    renderWindow->draw(*object, convertRenderStates(states));
}
void sfRenderWindow_drawShape(sfRenderWindow* renderWindow, const sfShape* object, const sfRenderStates* states)
{
    assert(renderWindow);
    assert(object);
    renderWindow->draw(*object, convertRenderStates(states));
}
void sfRenderWindow_drawCircleShape(sfRenderWindow* renderWindow, const sfCircleShape* object, const sfRenderStates* states)
{
    assert(renderWindow);
    assert(object);
    renderWindow->draw(*object, convertRenderStates(states));
}
void sfRenderWindow_drawConvexShape(sfRenderWindow* renderWindow, const sfConvexShape* object, const sfRenderStates* states)
{
    assert(renderWindow);
    assert(object);
    renderWindow->draw(*object, convertRenderStates(states));
}
void sfRenderWindow_drawRectangleShape(sfRenderWindow* renderWindow, const sfRectangleShape* object, const sfRenderStates* states)
{
    assert(renderWindow);
    assert(object);
    renderWindow->draw(*object, convertRenderStates(states));
}
void sfRenderWindow_drawVertexArray(sfRenderWindow* renderWindow, const sfVertexArray* object, const sfRenderStates* states)
{
    assert(renderWindow);
    assert(object);
    renderWindow->draw(*object, convertRenderStates(states));
}
void sfRenderWindow_drawVertexBuffer(sfRenderWindow* renderWindow, const sfVertexBuffer* object, const sfRenderStates* states)
{
    assert(renderWindow);
    assert(object);
    renderWindow->draw(*object, convertRenderStates(states));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_drawVertexBufferRange(sfRenderWindow*       renderWindow,
                                          const sfVertexBuffer* object,
                                          size_t                firstVertex,
                                          size_t                vertexCount,
                                          const sfRenderStates* states)
{
    assert(renderWindow);
    assert(object);
    renderWindow->draw(*object, firstVertex, vertexCount, convertRenderStates(states));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_drawPrimitives(sfRenderWindow*       renderWindow,
                                   const sfVertex*       vertices,
                                   size_t                vertexCount,
                                   sfPrimitiveType       type,
                                   const sfRenderStates* states)
{
    assert(renderWindow);
    renderWindow->draw(reinterpret_cast<const sf::Vertex*>(vertices),
                       vertexCount,
                       static_cast<sf::PrimitiveType>(type),
                       convertRenderStates(states));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_pushGLStates(sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    renderWindow->pushGLStates();
}


////////////////////////////////////////////////////////////
void sfRenderWindow_popGLStates(sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    renderWindow->popGLStates();
}


////////////////////////////////////////////////////////////
void sfRenderWindow_resetGLStates(sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    renderWindow->resetGLStates();
}


////////////////////////////////////////////////////////////
sfVector2i sfMouse_getPositionRenderWindow(const sfRenderWindow* relativeTo)
{
    if (relativeTo)
        return convertVector2(sf::Mouse::getPosition(*relativeTo));

    return convertVector2(sf::Mouse::getPosition());
}


////////////////////////////////////////////////////////////
void sfMouse_setPositionRenderWindow(sfVector2i position, const sfRenderWindow* relativeTo)
{
    if (relativeTo)
        sf::Mouse::setPosition(convertVector2(position), *relativeTo);
    else
        sf::Mouse::setPosition(convertVector2(position));
}


////////////////////////////////////////////////////////////
sfVector2i sfTouch_getPositionRenderWindow(unsigned int finger, const sfRenderWindow* relativeTo)
{
    if (relativeTo)
        return convertVector2(sf::Touch::getPosition(finger, *relativeTo));

    return convertVector2(sf::Touch::getPosition(finger));
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_createVulkanSurface(sfRenderWindow*              renderWindow,
                                        const VkInstance*            instance,
                                        VkSurfaceKHR*                surface,
                                        const VkAllocationCallbacks* allocator)
{
    assert(renderWindow);
    assert(instance);
    assert(surface);
    return renderWindow->createVulkanSurface(*instance, *surface, allocator);
}
