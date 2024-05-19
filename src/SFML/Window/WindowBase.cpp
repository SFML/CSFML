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
#include <SFML/Window/WindowBase.h>
#include <SFML/Window/WindowBaseStruct.h>
#include <SFML/Internal.h>
#include <SFML/Window/CursorStruct.h>
#include <SFML/ConvertEvent.h>


////////////////////////////////////////////////////////////
sfWindowBase* sfWindowBase_create(sfVideoMode mode, const char* title, sfUint32 style)
{
    // Convert video mode
    sf::VideoMode videoMode(mode.width, mode.height, mode.bitsPerPixel);

    // Create the window
    sfWindowBase* windowBase = new sfWindowBase;
    windowBase->This.create(videoMode, title, style);

    return windowBase;
}


////////////////////////////////////////////////////////////
sfWindowBase* sfWindowBase_createUnicode(sfVideoMode mode, const sfUint32* title, sfUint32 style)
{
    // Convert video mode
    sf::VideoMode videoMode(mode.width, mode.height, mode.bitsPerPixel);

    // Create the window
    sfWindowBase* windowBase = new sfWindowBase;
    windowBase->This.create(videoMode, title, style);

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
sfBool sfWindowBase_isOpen(const sfWindowBase* windowBase)
{
    CSFML_CALL_RETURN(windowBase, isOpen(), sfFalse);
}


////////////////////////////////////////////////////////////
sfBool sfWindowBase_pollEvent(sfWindowBase* windowBase, sfEvent* event)
{
    CSFML_CHECK_RETURN(windowBase, sfFalse);
    CSFML_CHECK_RETURN(event, sfFalse);

    // Get the event
    sf::Event sfmlEvent;
    sfBool ret = windowBase->This.pollEvent(sfmlEvent);

    // No event, return
    if (!ret)
        return sfFalse;

    // Convert the sf::Event event to a sfEvent
    convertEvent(sfmlEvent, event);

    return sfTrue;
}


////////////////////////////////////////////////////////////
sfBool sfWindowBase_waitEvent(sfWindowBase* windowBase, sfEvent* event)
{
    CSFML_CHECK_RETURN(windowBase, sfFalse);
    CSFML_CHECK_RETURN(event, sfFalse);

    // Get the event
    sf::Event sfmlEvent;
    sfBool ret = windowBase->This.waitEvent(sfmlEvent);

    // Error, return
    if (!ret)
        return sfFalse;

    // Convert the sf::Event event to a sfEvent
    convertEvent(sfmlEvent, event);

    return sfTrue;
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
void sfWindowBase_setUnicodeTitle(sfWindowBase* windowBase, const sfUint32* title)
{
    CSFML_CALL(windowBase, setTitle(title));
}


////////////////////////////////////////////////////////////
void sfWindowBase_setIcon(sfWindowBase* windowBase, unsigned int width, unsigned int height, const sfUint8* pixels)
{
    CSFML_CALL(windowBase, setIcon(width, height, pixels));
}


////////////////////////////////////////////////////////////
void sfWindowBase_setVisible(sfWindowBase* windowBase, sfBool visible)
{
    CSFML_CALL(windowBase, setVisible(visible == sfTrue));
}


////////////////////////////////////////////////////////////
void sfWindowBase_setMouseCursorVisible(sfWindowBase* windowBase, sfBool visible)
{
    CSFML_CALL(windowBase, setMouseCursorVisible(visible == sfTrue));
}


////////////////////////////////////////////////////////////
void sfWindowBase_setMouseCursorGrabbed(sfWindowBase* windowBase, sfBool grabbed)
{
    CSFML_CALL(windowBase, setMouseCursorGrabbed(grabbed == sfTrue));
}


////////////////////////////////////////////////////////////
void sfWindowBase_setMouseCursor(sfWindowBase* windowBase, const sfCursor* cursor)
{
    CSFML_CHECK(cursor);

    CSFML_CALL(windowBase, setMouseCursor(cursor->This));
}


////////////////////////////////////////////////////////////
void sfWindowBase_setKeyRepeatEnabled(sfWindowBase* windowBase, sfBool enabled)
{
    CSFML_CALL(windowBase, setKeyRepeatEnabled(enabled == sfTrue));
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
sfBool sfWindowBase_hasFocus(const sfWindowBase* windowBase)
{
    CSFML_CALL_RETURN(windowBase, hasFocus(), sfFalse);
}


////////////////////////////////////////////////////////////
sfWindowHandle sfWindowBase_getSystemHandle(const sfWindowBase* windowBase)
{
    CSFML_CHECK_RETURN(windowBase, 0);

    return static_cast<sfWindowHandle>(windowBase->This.getSystemHandle());
}

////////////////////////////////////////////////////////////
sfBool sfWindowBase_createVulkanSurface(sfWindowBase* windowBase, const VkInstance* instance, VkSurfaceKHR* surface, const VkAllocationCallbacks* allocator)
{
    CSFML_CHECK_RETURN(instance, sfFalse);
    CSFML_CHECK_RETURN(surface, sfFalse);
    CSFML_CALL_RETURN(windowBase, createVulkanSurface(*instance, *surface, allocator), sfFalse);
}
