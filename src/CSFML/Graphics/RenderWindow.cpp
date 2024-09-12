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
#include <CSFML/ConvertEvent.hpp>
#include <CSFML/Graphics/CircleShapeStruct.hpp>
#include <CSFML/Graphics/ConvertColor.hpp>
#include <CSFML/Graphics/ConvertRect.hpp>
#include <CSFML/Graphics/ConvertRenderStates.hpp>
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
    renderWindow->This.create(convertVideoMode(mode), title, style, static_cast<sf::State>(state), params);
    renderWindow->DefaultView.This = renderWindow->This.getDefaultView();
    renderWindow->CurrentView.This = renderWindow->This.getView();

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
    renderWindow->This.create(convertVideoMode(mode),
                              reinterpret_cast<const char32_t*>(title),
                              style,
                              static_cast<sf::State>(state),
                              params);
    renderWindow->DefaultView.This = renderWindow->This.getDefaultView();
    renderWindow->CurrentView.This = renderWindow->This.getView();

    return renderWindow;
}


////////////////////////////////////////////////////////////
sfRenderWindow* sfRenderWindow_createFromHandle(sfWindowHandle handle, const sfContextSettings* settings)
{
    // Convert context settings
    const sf::ContextSettings params = settings ? convertContextSettings(*settings) : sf::ContextSettings();

    // Create the window
    auto* renderWindow = new sfRenderWindow;
    renderWindow->This.create(handle, params);
    renderWindow->DefaultView.This = renderWindow->This.getDefaultView();
    renderWindow->CurrentView.This = renderWindow->This.getView();

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
    renderWindow->This.close();
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_isOpen(const sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    return renderWindow->This.isOpen();
}


////////////////////////////////////////////////////////////
sfContextSettings sfRenderWindow_getSettings(const sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    return convertContextSettings(renderWindow->This.getSettings());
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_pollEvent(sfRenderWindow* renderWindow, sfEvent* event)
{
    assert(renderWindow);
    assert(event);
    return convertEvent(renderWindow->This.pollEvent(), event);
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_waitEvent(sfRenderWindow* renderWindow, sfEvent* event)
{
    assert(renderWindow);
    assert(event);
    return convertEvent(renderWindow->This.waitEvent(), event);
}


////////////////////////////////////////////////////////////
sfVector2i sfRenderWindow_getPosition(const sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    return convertVector2(renderWindow->This.getPosition());
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setPosition(sfRenderWindow* renderWindow, sfVector2i position)
{
    assert(renderWindow);
    renderWindow->This.setPosition(convertVector2(position));
}


////////////////////////////////////////////////////////////
sfVector2u sfRenderWindow_getSize(const sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    return convertVector2(renderWindow->This.getSize());
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_isSrgb(const sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    return renderWindow->This.isSrgb();
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setSize(sfRenderWindow* renderWindow, sfVector2u size)
{
    assert(renderWindow);
    renderWindow->This.setSize(convertVector2(size));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setTitle(sfRenderWindow* renderWindow, const char* title)
{
    assert(renderWindow);
    renderWindow->This.setTitle(title);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setUnicodeTitle(sfRenderWindow* renderWindow, const sfChar32* title)
{
    assert(renderWindow);
    renderWindow->This.setTitle(reinterpret_cast<const char32_t*>(title));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setIcon(sfRenderWindow* renderWindow, sfVector2u size, const uint8_t* pixels)
{
    assert(renderWindow);
    renderWindow->This.setIcon(convertVector2(size), pixels);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setVisible(sfRenderWindow* renderWindow, bool visible)
{
    assert(renderWindow);
    renderWindow->This.setVisible(visible);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setVerticalSyncEnabled(sfRenderWindow* renderWindow, bool enabled)
{
    assert(renderWindow);
    renderWindow->This.setVerticalSyncEnabled(enabled);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setMouseCursorVisible(sfRenderWindow* renderWindow, bool visible)
{
    assert(renderWindow);
    renderWindow->This.setMouseCursorVisible(visible);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setMouseCursorGrabbed(sfRenderWindow* renderWindow, bool grabbed)
{
    assert(renderWindow);
    renderWindow->This.setMouseCursorGrabbed(grabbed);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setMouseCursor(sfRenderWindow* renderWindow, const sfCursor* cursor)
{
    assert(renderWindow);
    assert(cursor);
    renderWindow->This.setMouseCursor(cursor->This);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setKeyRepeatEnabled(sfRenderWindow* renderWindow, bool enabled)
{
    assert(renderWindow);
    renderWindow->This.setKeyRepeatEnabled(enabled);
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_setActive(sfRenderWindow* renderWindow, bool active)
{
    assert(renderWindow);
    return renderWindow->This.setActive(active);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_requestFocus(sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    renderWindow->This.requestFocus();
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_hasFocus(const sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    return renderWindow->This.hasFocus();
}


////////////////////////////////////////////////////////////
void sfRenderWindow_display(sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    renderWindow->This.display();
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setFramerateLimit(sfRenderWindow* renderWindow, unsigned int limit)
{
    assert(renderWindow);
    renderWindow->This.setFramerateLimit(limit);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setJoystickThreshold(sfRenderWindow* renderWindow, float threshold)
{
    assert(renderWindow);
    renderWindow->This.setJoystickThreshold(threshold);
}


////////////////////////////////////////////////////////////
sfWindowHandle sfRenderWindow_getNativeHandle(const sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    return static_cast<sfWindowHandle>(renderWindow->This.getNativeHandle());
}


////////////////////////////////////////////////////////////
void sfRenderWindow_clear(sfRenderWindow* renderWindow, sfColor color)
{
    assert(renderWindow);
    renderWindow->This.clear(convertColor(color));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setView(sfRenderWindow* renderWindow, const sfView* view)
{
    assert(renderWindow);
    assert(view);
    renderWindow->This.setView(view->This);
    renderWindow->CurrentView.This = view->This;
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
    return convertRect(renderWindow->This.getViewport(view->This));
}


////////////////////////////////////////////////////////////
sfVector2f sfRenderWindow_mapPixelToCoords(const sfRenderWindow* renderWindow, sfVector2i point, const sfView* targetView)
{
    assert(renderWindow);

    if (targetView)
        return convertVector2(renderWindow->This.mapPixelToCoords(convertVector2(point), targetView->This));

    return convertVector2(renderWindow->This.mapPixelToCoords(convertVector2(point)));
}


////////////////////////////////////////////////////////////
sfVector2i sfRenderWindow_mapCoordsToPixel(const sfRenderWindow* renderWindow, sfVector2f point, const sfView* targetView)
{
    assert(renderWindow);

    if (targetView)
        return convertVector2(renderWindow->This.mapCoordsToPixel(convertVector2(point), targetView->This));

    return convertVector2(renderWindow->This.mapCoordsToPixel(convertVector2(point)));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_drawSprite(sfRenderWindow* renderWindow, const sfSprite* object, const sfRenderStates* states)
{
    assert(renderWindow);
    assert(object);
    renderWindow->This.draw(object->This, convertRenderStates(states));
}
void sfRenderWindow_drawText(sfRenderWindow* renderWindow, const sfText* object, const sfRenderStates* states)
{
    assert(renderWindow);
    assert(object);
    renderWindow->This.draw(object->This, convertRenderStates(states));
}
void sfRenderWindow_drawShape(sfRenderWindow* renderWindow, const sfShape* object, const sfRenderStates* states)
{
    assert(renderWindow);
    assert(object);
    renderWindow->This.draw(object->This, convertRenderStates(states));
}
void sfRenderWindow_drawCircleShape(sfRenderWindow* renderWindow, const sfCircleShape* object, const sfRenderStates* states)
{
    assert(renderWindow);
    assert(object);
    renderWindow->This.draw(object->This, convertRenderStates(states));
}
void sfRenderWindow_drawConvexShape(sfRenderWindow* renderWindow, const sfConvexShape* object, const sfRenderStates* states)
{
    assert(renderWindow);
    assert(object);
    renderWindow->This.draw(object->This, convertRenderStates(states));
}
void sfRenderWindow_drawRectangleShape(sfRenderWindow* renderWindow, const sfRectangleShape* object, const sfRenderStates* states)
{
    assert(renderWindow);
    assert(object);
    renderWindow->This.draw(object->This, convertRenderStates(states));
}
void sfRenderWindow_drawVertexArray(sfRenderWindow* renderWindow, const sfVertexArray* object, const sfRenderStates* states)
{
    assert(renderWindow);
    assert(object);
    renderWindow->This.draw(object->This, convertRenderStates(states));
}
void sfRenderWindow_drawVertexBuffer(sfRenderWindow* renderWindow, const sfVertexBuffer* object, const sfRenderStates* states)
{
    assert(renderWindow);
    assert(object);
    renderWindow->This.draw(object->This, convertRenderStates(states));
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
    renderWindow->This.draw(object->This, firstVertex, vertexCount, convertRenderStates(states));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_drawPrimitives(sfRenderWindow*       renderWindow,
                                   const sfVertex*       vertices,
                                   size_t                vertexCount,
                                   sfPrimitiveType       type,
                                   const sfRenderStates* states)
{
    assert(renderWindow);
    renderWindow->This.draw(reinterpret_cast<const sf::Vertex*>(vertices),
                            vertexCount,
                            static_cast<sf::PrimitiveType>(type),
                            convertRenderStates(states));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_pushGLStates(sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    renderWindow->This.pushGLStates();
}


////////////////////////////////////////////////////////////
void sfRenderWindow_popGLStates(sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    renderWindow->This.popGLStates();
}


////////////////////////////////////////////////////////////
void sfRenderWindow_resetGLStates(sfRenderWindow* renderWindow)
{
    assert(renderWindow);
    renderWindow->This.resetGLStates();
}


////////////////////////////////////////////////////////////
sfVector2i sfMouse_getPositionRenderWindow(const sfRenderWindow* relativeTo)
{
    if (relativeTo)
        return convertVector2(sf::Mouse::getPosition(relativeTo->This));

    return convertVector2(sf::Mouse::getPosition());
}


////////////////////////////////////////////////////////////
void sfMouse_setPositionRenderWindow(sfVector2i position, const sfRenderWindow* relativeTo)
{
    if (relativeTo)
        sf::Mouse::setPosition(convertVector2(position), relativeTo->This);
    else
        sf::Mouse::setPosition(convertVector2(position));
}


////////////////////////////////////////////////////////////
sfVector2i sfTouch_getPositionRenderWindow(unsigned int finger, const sfRenderWindow* relativeTo)
{
    if (relativeTo)
        return convertVector2(sf::Touch::getPosition(finger, relativeTo->This));

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
    return renderWindow->This.createVulkanSurface(*instance, *surface, allocator);
}
