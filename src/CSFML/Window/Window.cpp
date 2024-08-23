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
#include <CSFML/Window/Window.h>
#include <CSFML/Window/WindowStruct.hpp>
#include <CSFML/Internal.hpp>
#include <CSFML/Window/ConvertContextSettings.hpp>
#include <CSFML/Window/CursorStruct.hpp>
#include <CSFML/Window/ConvertVideoMode.hpp>
#include <CSFML/System/ConvertVector2.hpp>
#include <CSFML/ConvertEvent.hpp>


////////////////////////////////////////////////////////////
sfWindow* sfWindow_create(sfVideoMode mode, const char* title, uint32_t style, sfWindowState state, const sfContextSettings* settings)
{
    // Convert context settings
    const sf::ContextSettings params = settings ? convertContextSettings(*settings) : sf::ContextSettings();

    // Create the window
    sfWindow* window = new sfWindow;
    window->This.create(convertVideoMode(mode), title, style, static_cast<sf::State>(state), params);

    return window;
}

////////////////////////////////////////////////////////////
sfWindow* sfWindow_createUnicode(sfVideoMode mode, const sfChar32* title, uint32_t style, sfWindowState state, const sfContextSettings* settings)
{
    // Convert context settings
    const sf::ContextSettings params = settings ? convertContextSettings(*settings) : sf::ContextSettings();

    // Create the window
    sfWindow* window = new sfWindow;
    window->This.create(convertVideoMode(mode), reinterpret_cast<const char32_t*>(title), style, static_cast<sf::State>(state), params);

    return window;
}


////////////////////////////////////////////////////////////
sfWindow* sfWindow_createFromHandle(sfWindowHandle handle, const sfContextSettings* settings)
{
    // Convert context settings
    const sf::ContextSettings params = settings ? convertContextSettings(*settings) : sf::ContextSettings();

    // Create the window
    sfWindow* window = new sfWindow;
    window->This.create(handle, params);

    return window;
}


////////////////////////////////////////////////////////////
void sfWindow_destroy(sfWindow* window)
{
    delete window;
}

////////////////////////////////////////////////////////////
void sfWindow_close(sfWindow* window)
{
    CSFML_CALL(window, close());
}


////////////////////////////////////////////////////////////
bool sfWindow_isOpen(const sfWindow* window)
{
    CSFML_CALL_RETURN(window, isOpen(), false);
}


////////////////////////////////////////////////////////////
sfContextSettings sfWindow_getSettings(const sfWindow* window)
{
    CSFML_CHECK_RETURN(window, sfContextSettings{});

    return convertContextSettings(window->This.getSettings());
}


////////////////////////////////////////////////////////////
bool sfWindow_pollEvent(sfWindow* window, sfEvent* event)
{
    CSFML_CHECK_RETURN(window, false);
    CSFML_CHECK_RETURN(event, false);

    // Get the event
    const std::optional sfmlEvent = window->This.pollEvent();

    // No event, return
    if (!sfmlEvent)
        return false;

    // Convert the sf::Event event to a sfEvent
    convertEvent(*sfmlEvent, event);

    return true;
}


////////////////////////////////////////////////////////////
bool sfWindow_waitEvent(sfWindow* window, sfEvent* event)
{
    CSFML_CHECK_RETURN(window, false);
    CSFML_CHECK_RETURN(event, false);

    // Get the event
    const std::optional sfmlEvent = window->This.waitEvent();

    // Error, return
    if (!sfmlEvent)
        return false;

    // Convert the sf::Event event to a sfEvent
    convertEvent(*sfmlEvent, event);

    return true;
}


////////////////////////////////////////////////////////////
sfVector2i sfWindow_getPosition(const sfWindow* window)
{
    sfVector2i position = {0, 0};
    CSFML_CHECK_RETURN(window, position);

    return convertVector2(window->This.getPosition());
}


////////////////////////////////////////////////////////////
void sfWindow_setPosition(sfWindow* window, sfVector2i position)
{
    CSFML_CALL(window, setPosition(convertVector2(position)));
}


////////////////////////////////////////////////////////////
sfVector2u sfWindow_getSize(const sfWindow* window)
{
    sfVector2u size = {0, 0};
    CSFML_CHECK_RETURN(window, size);

    return convertVector2(window->This.getSize());
}


////////////////////////////////////////////////////////////
void sfWindow_setSize(sfWindow* window, sfVector2u size)
{
    CSFML_CALL(window, setSize(convertVector2(size)));
}


////////////////////////////////////////////////////////////
void sfWindow_setTitle(sfWindow* window, const char* title)
{
    CSFML_CALL(window, setTitle(title));
}


////////////////////////////////////////////////////////////
void sfWindow_setUnicodeTitle(sfWindow* window, const sfChar32* title)
{
    CSFML_CALL(window, setTitle(reinterpret_cast<const char32_t*>(title)));
}


////////////////////////////////////////////////////////////
void sfWindow_setIcon(sfWindow* window, unsigned int width, unsigned int height, const uint8_t* pixels)
{
    CSFML_CALL(window, setIcon({ width, height }, pixels));
}


////////////////////////////////////////////////////////////
void sfWindow_setVisible(sfWindow* window, bool visible)
{
    CSFML_CALL(window, setVisible(visible));
}


////////////////////////////////////////////////////////////
void sfWindow_setMouseCursorVisible(sfWindow* window, bool visible)
{
    CSFML_CALL(window, setMouseCursorVisible(visible));
}


////////////////////////////////////////////////////////////
void sfWindow_setMouseCursorGrabbed(sfWindow* window, bool grabbed)
{
    CSFML_CALL(window, setMouseCursorGrabbed(grabbed));
}


////////////////////////////////////////////////////////////
void sfWindow_setMouseCursor(sfWindow* window, const sfCursor* cursor)
{
    CSFML_CHECK(cursor);

    CSFML_CALL(window, setMouseCursor(cursor->This));
}

////////////////////////////////////////////////////////////
void sfWindow_setVerticalSyncEnabled(sfWindow* window, bool enabled)
{
    CSFML_CALL(window, setVerticalSyncEnabled(enabled));
}


////////////////////////////////////////////////////////////
void sfWindow_setKeyRepeatEnabled(sfWindow* window, bool enabled)
{
    CSFML_CALL(window, setKeyRepeatEnabled(enabled));
}


////////////////////////////////////////////////////////////
bool sfWindow_setActive(sfWindow* window, bool active)
{
    CSFML_CALL_RETURN(window, setActive(active), false);
}


////////////////////////////////////////////////////////////
void sfWindow_requestFocus(sfWindow* window)
{
    CSFML_CALL(window, requestFocus());
}


////////////////////////////////////////////////////////////
bool sfWindow_hasFocus(const sfWindow* window)
{
    CSFML_CALL_RETURN(window, hasFocus(), false);
}


////////////////////////////////////////////////////////////
void sfWindow_display(sfWindow* window)
{
    CSFML_CALL(window, display());
}


////////////////////////////////////////////////////////////
void sfWindow_setFramerateLimit(sfWindow* window, unsigned int limit)
{
    CSFML_CALL(window, setFramerateLimit(limit));
}


////////////////////////////////////////////////////////////
void sfWindow_setJoystickThreshold(sfWindow* window, float threshold)
{
    CSFML_CALL(window, setJoystickThreshold(threshold));
}


////////////////////////////////////////////////////////////
sfWindowHandle sfWindow_getNativeHandle(const sfWindow* window)
{
    CSFML_CHECK_RETURN(window, 0);

    return static_cast<sfWindowHandle>(window->This.getNativeHandle());
}


////////////////////////////////////////////////////////////
bool sfWindow_createVulkanSurface(sfWindow* window, const VkInstance* instance, VkSurfaceKHR* surface, const VkAllocationCallbacks* allocator)
{
    CSFML_CHECK_RETURN(instance, false);
    CSFML_CHECK_RETURN(surface, false);
    CSFML_CALL_RETURN(window, createVulkanSurface(*instance, *surface, allocator), false);
}
