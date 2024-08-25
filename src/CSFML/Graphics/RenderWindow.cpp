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
#include <CSFML/ConvertEvent.hpp>
#include <CSFML/Graphics/CircleShapeStruct.hpp>
#include <CSFML/Graphics/ConvertRenderStates.hpp>
#include <CSFML/Graphics/ConvexShapeStruct.hpp>
#include <CSFML/Graphics/ConvertColor.hpp>
#include <CSFML/Graphics/ConvertRect.hpp>
#include <CSFML/Graphics/ImageStruct.hpp>
#include <CSFML/Graphics/RectangleShapeStruct.hpp>
#include <CSFML/Graphics/RenderWindow.h>
#include <CSFML/Graphics/RenderWindowStruct.hpp>
#include <CSFML/Graphics/ShapeStruct.hpp>
#include <CSFML/Graphics/SpriteStruct.hpp>
#include <CSFML/Graphics/TextStruct.hpp>
#include <CSFML/Graphics/VertexArrayStruct.hpp>
#include <CSFML/Graphics/VertexBufferStruct.hpp>
#include <CSFML/Internal.hpp>
#include <CSFML/Window/ConvertContextSettings.hpp>
#include <CSFML/Window/CursorStruct.hpp>
#include <CSFML/Window/ConvertVideoMode.hpp>
#include <CSFML/System/ConvertVector2.hpp>
#include <SFML/Window/Touch.hpp>


////////////////////////////////////////////////////////////
sfRenderWindow* sfRenderWindow_create(sfVideoMode mode, const char* title, uint32_t style, sfWindowState state, const sfContextSettings* settings)
{
    // Convert context settings
    const sf::ContextSettings params = settings ? convertContextSettings(*settings) : sf::ContextSettings();

    // Create the window
    sfRenderWindow* renderWindow = new sfRenderWindow;
    renderWindow->This.create(convertVideoMode(mode), title, style, static_cast<sf::State>(state), params);
    renderWindow->DefaultView.This = renderWindow->This.getDefaultView();
    renderWindow->CurrentView.This = renderWindow->This.getView();

    return renderWindow;
}

////////////////////////////////////////////////////////////
sfRenderWindow* sfRenderWindow_createUnicode(sfVideoMode mode, const sfChar32* title, uint32_t style, sfWindowState state, const sfContextSettings* settings)
{
    // Convert context settings
    const sf::ContextSettings params = settings ? convertContextSettings(*settings) : sf::ContextSettings();

    // Create the window
    sfRenderWindow* renderWindow = new sfRenderWindow;
    renderWindow->This.create(convertVideoMode(mode), reinterpret_cast<const char32_t*>(title), style, static_cast<sf::State>(state), params);
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
    sfRenderWindow* renderWindow = new sfRenderWindow;
    renderWindow->This.create(handle, params);
    renderWindow->DefaultView.This = renderWindow->This.getDefaultView();
    renderWindow->CurrentView.This = renderWindow->This.getView();

    return renderWindow;
}


////////////////////////////////////////////////////////////
void sfRenderWindow_destroy(sfRenderWindow* renderWindow)
{
    delete renderWindow;
}


////////////////////////////////////////////////////////////
void sfRenderWindow_close(sfRenderWindow* renderWindow)
{
    CSFML_CALL(renderWindow, close());
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_isOpen(const sfRenderWindow* renderWindow)
{
    CSFML_CALL_RETURN(renderWindow, isOpen(), false);
}


////////////////////////////////////////////////////////////
sfContextSettings sfRenderWindow_getSettings(const sfRenderWindow* renderWindow)
{
    CSFML_CHECK_RETURN(renderWindow, sfContextSettings{});

    return convertContextSettings(renderWindow->This.getSettings());
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_pollEvent(sfRenderWindow* renderWindow, sfEvent* event)
{
    CSFML_CHECK_RETURN(renderWindow, false);
    CSFML_CHECK_RETURN(event,        false);

    // Get the event
    const std::optional sfmlEvent = renderWindow->This.pollEvent();

    // No event, return
    if (!sfmlEvent)
        return false;

    // Convert the sf::Event event to a sfEvent
    convertEvent(*sfmlEvent, event);

    return true;
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_waitEvent(sfRenderWindow* renderWindow, sfEvent* event)
{
    CSFML_CHECK_RETURN(renderWindow, false);
    CSFML_CHECK_RETURN(event,        false);

    // Get the event
    const std::optional sfmlEvent = renderWindow->This.waitEvent();

    // Error, return
    if (!sfmlEvent)
        return false;

    // Convert the sf::Event event to a sfEvent
    convertEvent(*sfmlEvent, event);

    return true;
}


////////////////////////////////////////////////////////////
sfVector2i sfRenderWindow_getPosition(const sfRenderWindow* renderWindow)
{
    CSFML_CHECK_RETURN(renderWindow, {});

    return convertVector2(renderWindow->This.getPosition());;
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setPosition(sfRenderWindow* renderWindow, sfVector2i position)
{
    CSFML_CALL(renderWindow, setPosition(convertVector2(position)));
}


////////////////////////////////////////////////////////////
sfVector2u sfRenderWindow_getSize(const sfRenderWindow* renderWindow)
{
    CSFML_CHECK_RETURN(renderWindow, {});

    return convertVector2(renderWindow->This.getSize());
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_isSrgb(const sfRenderWindow* renderWindow)
{
    CSFML_CHECK_RETURN(renderWindow, false);
    return renderWindow->This.isSrgb();
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setSize(sfRenderWindow* renderWindow, sfVector2u size)
{
    CSFML_CALL(renderWindow, setSize(convertVector2(size)));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setTitle(sfRenderWindow* renderWindow, const char* title)
{
    CSFML_CALL(renderWindow, setTitle(title));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setUnicodeTitle(sfRenderWindow* renderWindow, const sfChar32* title)
{
    CSFML_CALL(renderWindow, setTitle(reinterpret_cast<const char32_t*>(title)));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setIcon(sfRenderWindow* renderWindow, unsigned int width, unsigned int height, const uint8_t* pixels)
{
    CSFML_CALL(renderWindow, setIcon({ width, height }, pixels));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setVisible(sfRenderWindow* renderWindow, bool visible)
{
    CSFML_CALL(renderWindow, setVisible(visible));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setVerticalSyncEnabled(sfRenderWindow* renderWindow, bool enabled)
{
    CSFML_CALL(renderWindow, setVerticalSyncEnabled(enabled));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setMouseCursorVisible(sfRenderWindow* renderWindow, bool visible)
{
    CSFML_CALL(renderWindow, setMouseCursorVisible(visible));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setMouseCursorGrabbed(sfRenderWindow* renderWindow, bool grabbed)
{
    CSFML_CALL(renderWindow, setMouseCursorGrabbed(grabbed));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setMouseCursor(sfRenderWindow* window, const sfCursor* cursor)
{
    CSFML_CHECK(cursor);

    CSFML_CALL(window, setMouseCursor(cursor->This));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setKeyRepeatEnabled(sfRenderWindow* renderWindow, bool enabled)
{
    CSFML_CALL(renderWindow, setKeyRepeatEnabled(enabled));
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_setActive(sfRenderWindow* renderWindow, bool active)
{
    CSFML_CALL_RETURN(renderWindow, setActive(active), false);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_requestFocus(sfRenderWindow* renderWindow)
{
    CSFML_CALL(renderWindow, requestFocus());
}


////////////////////////////////////////////////////////////
bool sfRenderWindow_hasFocus(const sfRenderWindow* renderWindow)
{
    CSFML_CALL_RETURN(renderWindow, hasFocus(), false);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_display(sfRenderWindow* renderWindow)
{
    CSFML_CALL(renderWindow, display());
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setFramerateLimit(sfRenderWindow* renderWindow, unsigned int limit)
{
    CSFML_CALL(renderWindow, setFramerateLimit(limit));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setJoystickThreshold(sfRenderWindow* renderWindow, float threshold)
{
    CSFML_CALL(renderWindow, setJoystickThreshold(threshold));
}


////////////////////////////////////////////////////////////
sfWindowHandle sfRenderWindow_getNativeHandle(const sfRenderWindow* renderWindow)
{
    CSFML_CHECK_RETURN(renderWindow, 0);

    return static_cast<sfWindowHandle>(renderWindow->This.getNativeHandle());
}


////////////////////////////////////////////////////////////
void sfRenderWindow_clear(sfRenderWindow* renderWindow, sfColor color)
{
    CSFML_CALL(renderWindow, clear(convertColor(color)));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_setView(sfRenderWindow* renderWindow, const sfView* view)
{
    CSFML_CHECK(view);
    CSFML_CALL(renderWindow, setView(view->This));
    renderWindow->CurrentView.This = view->This;
}


////////////////////////////////////////////////////////////
const sfView* sfRenderWindow_getView(const sfRenderWindow* renderWindow)
{
    CSFML_CHECK_RETURN(renderWindow, nullptr);

    return &renderWindow->CurrentView;
}


////////////////////////////////////////////////////////////
const sfView* sfRenderWindow_getDefaultView(const sfRenderWindow* renderWindow)
{
    CSFML_CHECK_RETURN(renderWindow, nullptr);

    return &renderWindow->DefaultView;
}


////////////////////////////////////////////////////////////
sfIntRect sfRenderWindow_getViewport(const sfRenderWindow* renderWindow, const sfView* view)
{
    CSFML_CHECK_RETURN(view, {});
    CSFML_CHECK_RETURN(renderWindow, {});

    return convertRect(renderWindow->This.getViewport(view->This));
}


////////////////////////////////////////////////////////////
sfVector2f sfRenderWindow_mapPixelToCoords(const sfRenderWindow* renderWindow, sfVector2i point, const sfView* targetView)
{
    CSFML_CHECK_RETURN(renderWindow, {});

    if (targetView)
        return convertVector2(renderWindow->This.mapPixelToCoords(convertVector2(point), targetView->This));

    return convertVector2(renderWindow->This.mapPixelToCoords(convertVector2(point)));
}


////////////////////////////////////////////////////////////
sfVector2i sfRenderWindow_mapCoordsToPixel(const sfRenderWindow* renderWindow, sfVector2f point, const sfView* targetView)
{
    CSFML_CHECK_RETURN(renderWindow, {});

    if (targetView)
        return convertVector2(renderWindow->This.mapCoordsToPixel(convertVector2(point), targetView->This));

    return convertVector2(renderWindow->This.mapCoordsToPixel(convertVector2(point)));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_drawSprite(sfRenderWindow* renderWindow, const sfSprite* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderWindow, draw(object->This, convertRenderStates(states)));
}
void sfRenderWindow_drawText(sfRenderWindow* renderWindow, const sfText* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderWindow, draw(object->This, convertRenderStates(states)));
}
void sfRenderWindow_drawShape(sfRenderWindow* renderWindow, const sfShape* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderWindow, draw(object->This, convertRenderStates(states)));
}
void sfRenderWindow_drawCircleShape(sfRenderWindow* renderWindow, const sfCircleShape* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderWindow, draw(object->This, convertRenderStates(states)));
}
void sfRenderWindow_drawConvexShape(sfRenderWindow* renderWindow, const sfConvexShape* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderWindow, draw(object->This, convertRenderStates(states)));
}
void sfRenderWindow_drawRectangleShape(sfRenderWindow* renderWindow, const sfRectangleShape* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderWindow, draw(object->This, convertRenderStates(states)));
}
void sfRenderWindow_drawVertexArray(sfRenderWindow* renderWindow, const sfVertexArray* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderWindow, draw(object->This, convertRenderStates(states)));
}
void sfRenderWindow_drawVertexBuffer(sfRenderWindow* renderWindow, const sfVertexBuffer* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderWindow, draw(object->This, convertRenderStates(states)));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_drawVertexBufferRange(sfRenderWindow* renderWindow,
                                          const sfVertexBuffer* object, size_t firstVertex,
                                          size_t vertexCount, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderWindow, draw(object->This, firstVertex, vertexCount, convertRenderStates(states)));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_drawPrimitives(sfRenderWindow* renderWindow,
                                   const sfVertex* vertices, size_t vertexCount,
                                   sfPrimitiveType type, const sfRenderStates* states)
{
    CSFML_CALL(renderWindow, draw(reinterpret_cast<const sf::Vertex*>(vertices), vertexCount,
               static_cast<sf::PrimitiveType>(type), convertRenderStates(states)));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_pushGLStates(sfRenderWindow* renderWindow)
{
    CSFML_CALL(renderWindow, pushGLStates());
}


////////////////////////////////////////////////////////////
void sfRenderWindow_popGLStates(sfRenderWindow* renderWindow)
{
    CSFML_CALL(renderWindow, popGLStates());
}


////////////////////////////////////////////////////////////
void sfRenderWindow_resetGLStates(sfRenderWindow* renderWindow)
{
    CSFML_CALL(renderWindow, resetGLStates());
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
bool sfRenderWindow_createVulkanSurface(sfRenderWindow* renderWindow, const VkInstance* instance, VkSurfaceKHR* surface, const VkAllocationCallbacks* allocator)
{
    CSFML_CHECK_RETURN(instance, false);
    CSFML_CHECK_RETURN(surface, false);
    CSFML_CALL_RETURN(renderWindow, createVulkanSurface(*instance, *surface, allocator), false);
}
