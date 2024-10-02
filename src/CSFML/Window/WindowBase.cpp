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
#include <CSFML/System/ConvertVector2.hpp>
#include <CSFML/Window/ConvertEvent.hpp>
#include <CSFML/Window/ConvertVideoMode.hpp>
#include <CSFML/Window/CursorStruct.hpp>
#include <CSFML/Window/WindowBase.h>
#include <CSFML/Window/WindowBaseStruct.hpp>

#include <SFML/Window/VideoMode.hpp>


////////////////////////////////////////////////////////////
sfWindowBase* sfWindowBase_create(sfVideoMode mode, const char* title, uint32_t style, sfWindowState state)
{
    // Create the window
    auto* windowBase = new sfWindowBase;
    windowBase->create(convertVideoMode(mode), title, style, static_cast<sf::State>(state));

    return windowBase;
}


////////////////////////////////////////////////////////////
sfWindowBase* sfWindowBase_createUnicode(sfVideoMode mode, const sfChar32* title, uint32_t style, sfWindowState state)
{
    // Create the window
    auto* windowBase = new sfWindowBase;
    windowBase->create(convertVideoMode(mode), reinterpret_cast<const char32_t*>(title), style, static_cast<sf::State>(state));

    return windowBase;
}


////////////////////////////////////////////////////////////
sfWindowBase* sfWindowBase_createFromHandle(sfWindowHandle handle)
{
    // Create the window
    auto* windowBase = new sfWindowBase;
    windowBase->create(handle);

    return windowBase;
}


////////////////////////////////////////////////////////////
void sfWindowBase_destroy(const sfWindowBase* windowBase)
{
    delete windowBase;
}


////////////////////////////////////////////////////////////
void sfWindowBase_close(sfWindowBase* windowBase)
{
    assert(windowBase);
    windowBase->close();
}


////////////////////////////////////////////////////////////
bool sfWindowBase_isOpen(const sfWindowBase* windowBase)
{
    assert(windowBase);
    return windowBase->isOpen();
}


////////////////////////////////////////////////////////////
bool sfWindowBase_pollEvent(sfWindowBase* windowBase, sfEvent* event)
{
    assert(windowBase);
    assert(event);
    return convertEvent(windowBase->pollEvent(), *event);
}


////////////////////////////////////////////////////////////
bool sfWindowBase_waitEvent(sfWindowBase* windowBase, sfTime timeout, sfEvent* event)
{
    assert(windowBase);
    assert(event);
    return convertEvent(windowBase->waitEvent(sf::microseconds(timeout.microseconds)), *event);
}


////////////////////////////////////////////////////////////
sfVector2i sfWindowBase_getPosition(const sfWindowBase* windowBase)
{
    assert(windowBase);
    return convertVector2(windowBase->getPosition());
}


////////////////////////////////////////////////////////////
void sfWindowBase_setPosition(sfWindowBase* windowBase, sfVector2i position)
{
    assert(windowBase);
    windowBase->setPosition(convertVector2(position));
}


////////////////////////////////////////////////////////////
sfVector2u sfWindowBase_getSize(const sfWindowBase* windowBase)
{
    assert(windowBase);
    return convertVector2(windowBase->getSize());
}


////////////////////////////////////////////////////////////
void sfWindowBase_setSize(sfWindowBase* windowBase, sfVector2u size)
{
    assert(windowBase);
    windowBase->setSize(convertVector2(size));
}


////////////////////////////////////////////////////////////
void sfWindowBase_setTitle(sfWindowBase* windowBase, const char* title)
{
    assert(windowBase);
    windowBase->setTitle(title);
}


////////////////////////////////////////////////////////////
void sfWindowBase_setUnicodeTitle(sfWindowBase* windowBase, const sfChar32* title)
{
    assert(windowBase);
    windowBase->setTitle(reinterpret_cast<const char32_t*>(title));
}


////////////////////////////////////////////////////////////
void sfWindowBase_setIcon(sfWindowBase* windowBase, sfVector2u size, const uint8_t* pixels)
{
    assert(windowBase);
    windowBase->setIcon(convertVector2(size), pixels);
}


////////////////////////////////////////////////////////////
void sfWindowBase_setVisible(sfWindowBase* windowBase, bool visible)
{
    assert(windowBase);
    windowBase->setVisible(visible);
}


////////////////////////////////////////////////////////////
void sfWindowBase_setMouseCursorVisible(sfWindowBase* windowBase, bool visible)
{
    assert(windowBase);
    windowBase->setMouseCursorVisible(visible);
}


////////////////////////////////////////////////////////////
void sfWindowBase_setMouseCursorGrabbed(sfWindowBase* windowBase, bool grabbed)
{
    assert(windowBase);
    windowBase->setMouseCursorGrabbed(grabbed);
}


////////////////////////////////////////////////////////////
void sfWindowBase_setMouseCursor(sfWindowBase* windowBase, const sfCursor* cursor)
{
    assert(windowBase);
    assert(cursor);
    windowBase->setMouseCursor(*cursor);
}


////////////////////////////////////////////////////////////
void sfWindowBase_setKeyRepeatEnabled(sfWindowBase* windowBase, bool enabled)
{
    assert(windowBase);
    windowBase->setKeyRepeatEnabled(enabled);
}


////////////////////////////////////////////////////////////
void sfWindowBase_setJoystickThreshold(sfWindowBase* windowBase, float threshold)
{
    assert(windowBase);
    windowBase->setJoystickThreshold(threshold);
}


////////////////////////////////////////////////////////////
void sfWindowBase_requestFocus(sfWindowBase* windowBase)
{
    assert(windowBase);
    windowBase->requestFocus();
}


////////////////////////////////////////////////////////////
bool sfWindowBase_hasFocus(const sfWindowBase* windowBase)
{
    assert(windowBase);
    return windowBase->hasFocus();
}


////////////////////////////////////////////////////////////
sfWindowHandle sfWindowBase_getNativeHandle(const sfWindowBase* windowBase)
{
    assert(windowBase);
    return static_cast<sfWindowHandle>(windowBase->getNativeHandle());
}

////////////////////////////////////////////////////////////
bool sfWindowBase_createVulkanSurface(sfWindowBase*                windowBase,
                                      const VkInstance*            instance,
                                      VkSurfaceKHR*                surface,
                                      const VkAllocationCallbacks* allocator)
{
    assert(windowBase);
    assert(instance);
    assert(surface);
    return windowBase->createVulkanSurface(*instance, *surface, allocator);
}
