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
#include <SFML/Window/WindowBase.h>
#include <SFML/Window/WindowBaseStruct.h>
#include <SFML/Internal.h>
#include <SFML/Window/CursorStruct.h>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/ConvertEvent.h>


////////////////////////////////////////////////////////////
sfWindowBase* sfWindowBase_create(sfVideoMode mode, const char* title, uint32_t style)
{
    // Convert video mode
    sf::VideoMode videoMode({ mode.width, mode.height }, mode.bitsPerPixel);

    // Create the window
    sfWindowBase* windowBase = new sfWindowBase;
    windowBase->This.create(videoMode, title, style);

    return windowBase;
}


////////////////////////////////////////////////////////////
sfWindowBase* sfWindowBase_createUnicode(sfVideoMode mode, const sfChar32* title, uint32_t style)
{
    // Convert video mode
    sf::VideoMode videoMode({ mode.width, mode.height }, mode.bitsPerPixel);

    // Create the window
    sfWindowBase* windowBase = new sfWindowBase;
    windowBase->This.create(videoMode, reinterpret_cast<const char32_t*>(title), style);

    return windowBase;
}


////////////////////////////////////////////////////////////
sfWindowBase* sfWindowBase_createFromHandle(sfWindowHandle handle)
{
    // Create the window
    sfWindowBase* windowBase = new sfWindowBase;
    windowBase->This.create(handle);

    return windowBase;
}


////////////////////////////////////////////////////////////
void sfWindowBase_destroy(sfWindowBase* windowBase)
{
    delete windowBase;
}


////////////////////////////////////////////////////////////
void sfWindowBase_close(sfWindowBase* windowBase)
{
    CSFML_CALL(windowBase, close());
}


////////////////////////////////////////////////////////////
bool sfWindowBase_isOpen(const sfWindowBase* windowBase)
{
    CSFML_CALL_RETURN(windowBase, isOpen(), false);
}


////////////////////////////////////////////////////////////
bool sfWindowBase_pollEvent(sfWindowBase* windowBase, sfEvent* event)
{
    CSFML_CHECK_RETURN(windowBase, false);
    CSFML_CHECK_RETURN(event, false);

    // Get the event
    sf::Event sfmlEvent;
    bool ret = windowBase->This.pollEvent(sfmlEvent);

    // No event, return
    if (!ret)
        return false;

    // Convert the sf::Event event to a sfEvent
    convertEvent(sfmlEvent, event);

    return true;
}


////////////////////////////////////////////////////////////
bool sfWindowBase_waitEvent(sfWindowBase* windowBase, sfEvent* event)
{
    CSFML_CHECK_RETURN(windowBase, false);
    CSFML_CHECK_RETURN(event, false);

    // Get the event
    sf::Event sfmlEvent;
    bool ret = windowBase->This.waitEvent(sfmlEvent);

    // Error, return
    if (!ret)
        return false;

    // Convert the sf::Event event to a sfEvent
    convertEvent(sfmlEvent, event);

    return true;
}


////////////////////////////////////////////////////////////
sfVector2i sfWindowBase_getPosition(const sfWindowBase* windowBase)
{
    sfVector2i position = {0, 0};
    CSFML_CHECK_RETURN(windowBase, position);

    sf::Vector2i sfmlPos = windowBase->This.getPosition();
    position.x = sfmlPos.x;
    position.y = sfmlPos.y;

    return position;
}


////////////////////////////////////////////////////////////
void sfWindowBase_setPosition(sfWindowBase* windowBase, sfVector2i position)
{
    CSFML_CALL(windowBase, setPosition(sf::Vector2i(position.x, position.y)));
}


////////////////////////////////////////////////////////////
sfVector2u sfWindowBase_getSize(const sfWindowBase* windowBase)
{
    sfVector2u size = {0, 0};
    CSFML_CHECK_RETURN(windowBase, size);

    sf::Vector2u sfmlSize = windowBase->This.getSize();
    size.x = sfmlSize.x;
    size.y = sfmlSize.y;

    return size;
}


////////////////////////////////////////////////////////////
void sfWindowBase_setSize(sfWindowBase* windowBase, sfVector2u size)
{
    CSFML_CALL(windowBase, setSize(sf::Vector2u(size.x, size.y)));
}


////////////////////////////////////////////////////////////
void sfWindowBase_setTitle(sfWindowBase* windowBase, const char* title)
{
    CSFML_CALL(windowBase, setTitle(title));
}


////////////////////////////////////////////////////////////
void sfWindowBase_setUnicodeTitle(sfWindowBase* windowBase, const sfChar32* title)
{
    CSFML_CALL(windowBase, setTitle(reinterpret_cast<const char32_t*>(title)));
}


////////////////////////////////////////////////////////////
void sfWindowBase_setIcon(sfWindowBase* windowBase, unsigned int width, unsigned int height, const uint8_t* pixels)
{
    CSFML_CALL(windowBase, setIcon({ width, height }, pixels));
}


////////////////////////////////////////////////////////////
void sfWindowBase_setVisible(sfWindowBase* windowBase, bool visible)
{
    CSFML_CALL(windowBase, setVisible(visible));
}


////////////////////////////////////////////////////////////
void sfWindowBase_setMouseCursorVisible(sfWindowBase* windowBase, bool visible)
{
    CSFML_CALL(windowBase, setMouseCursorVisible(visible));
}


////////////////////////////////////////////////////////////
void sfWindowBase_setMouseCursorGrabbed(sfWindowBase* windowBase, bool grabbed)
{
    CSFML_CALL(windowBase, setMouseCursorGrabbed(grabbed));
}


////////////////////////////////////////////////////////////
void sfWindowBase_setMouseCursor(sfWindowBase* windowBase, const sfCursor* cursor)
{
    CSFML_CHECK(cursor);

    CSFML_CALL(windowBase, setMouseCursor(cursor->This));
}


////////////////////////////////////////////////////////////
void sfWindowBase_setKeyRepeatEnabled(sfWindowBase* windowBase, bool enabled)
{
    CSFML_CALL(windowBase, setKeyRepeatEnabled(enabled));
}


////////////////////////////////////////////////////////////
void sfWindowBase_setJoystickThreshold(sfWindowBase* windowBase, float threshold)
{
    CSFML_CALL(windowBase, setJoystickThreshold(threshold));
}


////////////////////////////////////////////////////////////
void sfWindowBase_requestFocus(sfWindowBase* windowBase)
{
    CSFML_CALL(windowBase, requestFocus());
}


////////////////////////////////////////////////////////////
bool sfWindowBase_hasFocus(const sfWindowBase* windowBase)
{
    CSFML_CALL_RETURN(windowBase, hasFocus(), false);
}


////////////////////////////////////////////////////////////
sfWindowHandle sfWindowBase_getNativeHandle(const sfWindowBase* windowBase)
{
    CSFML_CHECK_RETURN(windowBase, 0);

    return static_cast<sfWindowHandle>(windowBase->This.getNativeHandle());
}

////////////////////////////////////////////////////////////
bool sfWindowBase_createVulkanSurface(sfWindowBase* windowBase, const VkInstance* instance, VkSurfaceKHR* surface, const VkAllocationCallbacks* allocator)
{
    CSFML_CHECK_RETURN(instance, false);
    CSFML_CHECK_RETURN(surface, false);
    CSFML_CALL_RETURN(windowBase, createVulkanSurface(*instance, *surface, allocator), false);
}
