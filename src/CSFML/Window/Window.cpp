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
#include <CSFML/System/ConvertVector2.hpp>
#include <CSFML/Window/ConvertContextSettings.hpp>
#include <CSFML/Window/ConvertVideoMode.hpp>
#include <CSFML/Window/CursorStruct.hpp>
#include <CSFML/Window/Window.h>
#include <CSFML/Window/WindowStruct.hpp>


////////////////////////////////////////////////////////////
sfWindow* sfWindow_create(sfVideoMode mode, const char* title, uint32_t style, sfWindowState state, const sfContextSettings* settings)
{
    // Convert context settings
    const sf::ContextSettings params = settings ? convertContextSettings(*settings) : sf::ContextSettings();

    // Create the window
    auto* window = new sfWindow;
    window->This.create(convertVideoMode(mode), title, style, static_cast<sf::State>(state), params);

    return window;
}

////////////////////////////////////////////////////////////
sfWindow* sfWindow_createUnicode(sfVideoMode              mode,
                                 const sfChar32*          title,
                                 uint32_t                 style,
                                 sfWindowState            state,
                                 const sfContextSettings* settings)
{
    // Convert context settings
    const sf::ContextSettings params = settings ? convertContextSettings(*settings) : sf::ContextSettings();

    // Create the window
    auto* window = new sfWindow;
    window->This.create(convertVideoMode(mode),
                        reinterpret_cast<const char32_t*>(title),
                        style,
                        static_cast<sf::State>(state),
                        params);

    return window;
}


////////////////////////////////////////////////////////////
sfWindow* sfWindow_createFromHandle(sfWindowHandle handle, const sfContextSettings* settings)
{
    // Convert context settings
    const sf::ContextSettings params = settings ? convertContextSettings(*settings) : sf::ContextSettings();

    // Create the window
    auto* window = new sfWindow;
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
    assert(window);
    window->This.close();
}


////////////////////////////////////////////////////////////
bool sfWindow_isOpen(const sfWindow* window)
{
    assert(window);
    return window->This.isOpen();
}


////////////////////////////////////////////////////////////
sfContextSettings sfWindow_getSettings(const sfWindow* window)
{
    assert(window);
    return convertContextSettings(window->This.getSettings());
}


////////////////////////////////////////////////////////////
bool sfWindow_pollEvent(sfWindow* window, sfEvent* event)
{
    assert(window);
    assert(event);
    return convertEvent(window->This.pollEvent(), event);
}


////////////////////////////////////////////////////////////
bool sfWindow_waitEvent(sfWindow* window, sfEvent* event)
{
    assert(window);
    assert(event);
    return convertEvent(window->This.waitEvent(), event);
}


////////////////////////////////////////////////////////////
sfVector2i sfWindow_getPosition(const sfWindow* window)
{
    assert(window);
    return convertVector2(window->This.getPosition());
}


////////////////////////////////////////////////////////////
void sfWindow_setPosition(sfWindow* window, sfVector2i position)
{
    assert(window);
    window->This.setPosition(convertVector2(position));
}


////////////////////////////////////////////////////////////
sfVector2u sfWindow_getSize(const sfWindow* window)
{
    assert(window);
    return convertVector2(window->This.getSize());
}


////////////////////////////////////////////////////////////
void sfWindow_setSize(sfWindow* window, sfVector2u size)
{
    assert(window);
    window->This.setSize(convertVector2(size));
}


////////////////////////////////////////////////////////////
void sfWindow_setTitle(sfWindow* window, const char* title)
{
    assert(window);
    window->This.setTitle(title);
}


////////////////////////////////////////////////////////////
void sfWindow_setUnicodeTitle(sfWindow* window, const sfChar32* title)
{
    assert(window);
    window->This.setTitle(reinterpret_cast<const char32_t*>(title));
}


////////////////////////////////////////////////////////////
void sfWindow_setIcon(sfWindow* window, sfVector2u size, const uint8_t* pixels)
{
    assert(window);
    window->This.setIcon(convertVector2(size), pixels);
}


////////////////////////////////////////////////////////////
void sfWindow_setVisible(sfWindow* window, bool visible)
{
    assert(window);
    window->This.setVisible(visible);
}


////////////////////////////////////////////////////////////
void sfWindow_setMouseCursorVisible(sfWindow* window, bool visible)
{
    assert(window);
    window->This.setMouseCursorVisible(visible);
}


////////////////////////////////////////////////////////////
void sfWindow_setMouseCursorGrabbed(sfWindow* window, bool grabbed)
{
    assert(window);
    window->This.setMouseCursorGrabbed(grabbed);
}


////////////////////////////////////////////////////////////
void sfWindow_setMouseCursor(sfWindow* window, const sfCursor* cursor)
{
    assert(window);
    assert(cursor);
    window->This.setMouseCursor(cursor->This);
}

////////////////////////////////////////////////////////////
void sfWindow_setVerticalSyncEnabled(sfWindow* window, bool enabled)
{
    assert(window);
    window->This.setVerticalSyncEnabled(enabled);
}


////////////////////////////////////////////////////////////
void sfWindow_setKeyRepeatEnabled(sfWindow* window, bool enabled)
{
    assert(window);
    window->This.setKeyRepeatEnabled(enabled);
}


////////////////////////////////////////////////////////////
bool sfWindow_setActive(sfWindow* window, bool active)
{
    assert(window);
    return window->This.setActive(active);
}


////////////////////////////////////////////////////////////
void sfWindow_requestFocus(sfWindow* window)
{
    assert(window);
    window->This.requestFocus();
}


////////////////////////////////////////////////////////////
bool sfWindow_hasFocus(const sfWindow* window)
{
    assert(window);
    return window->This.hasFocus();
}


////////////////////////////////////////////////////////////
void sfWindow_display(sfWindow* window)
{
    assert(window);
    window->This.display();
}


////////////////////////////////////////////////////////////
void sfWindow_setFramerateLimit(sfWindow* window, unsigned int limit)
{
    assert(window);
    window->This.setFramerateLimit(limit);
}


////////////////////////////////////////////////////////////
void sfWindow_setJoystickThreshold(sfWindow* window, float threshold)
{
    assert(window);
    window->This.setJoystickThreshold(threshold);
}


////////////////////////////////////////////////////////////
sfWindowHandle sfWindow_getNativeHandle(const sfWindow* window)
{
    assert(window);
    return static_cast<sfWindowHandle>(window->This.getNativeHandle());
}


////////////////////////////////////////////////////////////
bool sfWindow_createVulkanSurface(sfWindow*                    window,
                                  const VkInstance*            instance,
                                  VkSurfaceKHR*                surface,
                                  const VkAllocationCallbacks* allocator)
{
    assert(window);
    assert(instance);
    assert(surface);
    return window->This.createVulkanSurface(*instance, *surface, allocator);
}
