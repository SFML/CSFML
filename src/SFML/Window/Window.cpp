////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2009 Laurent Gomila (laurent.gom@gmail.com)
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
#include <SFML/Window/Window.h>
#include <SFML/Window/WindowStruct.h>
#include <SFML/Internal.h>
#include <SFML/ConvertEvent.h>


////////////////////////////////////////////////////////////
sfWindow* sfWindow_Create(sfVideoMode mode, const char* title, sfUint32 style, const sfContextSettings* settings)
{
    // Convert video mode
    sf::VideoMode videoMode(mode.Width, mode.Height, mode.BitsPerPixel);

    // Convert context settings
    sf::ContextSettings params;
    if (settings)
    {
        params.DepthBits         = settings->DepthBits;
        params.StencilBits       = settings->StencilBits;
        params.AntialiasingLevel = settings->AntialiasingLevel;
        params.MajorVersion      = settings->MajorVersion;
        params.MinorVersion      = settings->MinorVersion;
    }

    // Create the window
    sfWindow* window = new sfWindow;
    window->This.Create(videoMode, title, style, params);

    return window;
}


////////////////////////////////////////////////////////////
sfWindow* sfWindow_CreateFromHandle(sfWindowHandle handle, const sfContextSettings* settings)
{
    // Convert context settings
    sf::ContextSettings params;
    if (settings)
    {
        params.DepthBits         = settings->DepthBits;
        params.StencilBits       = settings->StencilBits;
        params.AntialiasingLevel = settings->AntialiasingLevel;
        params.MajorVersion      = settings->MajorVersion;
        params.MinorVersion      = settings->MinorVersion;
    }

    // Create the window
    sfWindow* window = new sfWindow;
    window->This.Create(handle, params);

    return window;
}


////////////////////////////////////////////////////////////
void sfWindow_Destroy(sfWindow* window)
{
    delete window;
}

////////////////////////////////////////////////////////////
void sfWindow_Close(sfWindow* window)
{
    CSFML_CALL(window, Close());
}


////////////////////////////////////////////////////////////
sfBool sfWindow_IsOpened(const sfWindow* window)
{
    CSFML_CALL_RETURN(window, IsOpened(), sfFalse);
}


////////////////////////////////////////////////////////////
unsigned int sfWindow_GetWidth(const sfWindow* window)
{
    CSFML_CALL_RETURN(window, GetWidth(), 0)
}


////////////////////////////////////////////////////////////
unsigned int sfWindow_GetHeight(const sfWindow* window)
{
    CSFML_CALL_RETURN(window, GetHeight(), 0)
}


////////////////////////////////////////////////////////////
sfContextSettings sfWindow_GetSettings(const sfWindow* window)
{
    sfContextSettings settings = {0, 0, 0, 0, 0};
    CSFML_CHECK_RETURN(window, settings);

    const sf::ContextSettings& params = window->This.GetSettings();
    settings.DepthBits         = params.DepthBits;
    settings.StencilBits       = params.StencilBits;
    settings.AntialiasingLevel = params.AntialiasingLevel;
    settings.MajorVersion      = params.MajorVersion;
    settings.MinorVersion      = params.MinorVersion;

    return settings;
}


////////////////////////////////////////////////////////////
sfBool sfWindow_PollEvent(sfWindow* window, sfEvent* event)
{
    CSFML_CHECK_RETURN(window, sfFalse);
    CSFML_CHECK_RETURN(event, sfFalse);

    // Get the event
    sf::Event SFMLEvent;
    sfBool ret = window->This.PollEvent(SFMLEvent);

    // No event, return
    if (!ret)
        return sfFalse;

    // Convert the sf::Event event to a sfEvent
    ConvertEvent(SFMLEvent, event);

    return sfTrue;
}


////////////////////////////////////////////////////////////
sfBool sfWindow_WaitEvent(sfWindow* window, sfEvent* event)
{
    CSFML_CHECK_RETURN(window, sfFalse);
    CSFML_CHECK_RETURN(event, sfFalse);

    // Get the event
    sf::Event SFMLEvent;
    sfBool ret = window->This.WaitEvent(SFMLEvent);

    // Error, return
    if (!ret)
        return sfFalse;

    // Convert the sf::Event event to a sfEvent
    ConvertEvent(SFMLEvent, event);

    return sfTrue;
}


////////////////////////////////////////////////////////////
void sfWindow_EnableVerticalSync(sfWindow* window, sfBool enabled)
{
    CSFML_CALL(window, EnableVerticalSync(enabled == sfTrue))
}


////////////////////////////////////////////////////////////
void sfWindow_ShowMouseCursor(sfWindow* window, sfBool show)
{
    CSFML_CALL(window, ShowMouseCursor(show == sfTrue))
}


////////////////////////////////////////////////////////////
void sfWindow_SetPosition(sfWindow* window, int left, int top)
{
    CSFML_CALL(window, SetPosition(left, top))
}


////////////////////////////////////////////////////////////
void sfWindow_SetSize(sfWindow* window, unsigned int width, unsigned int height)
{
    CSFML_CALL(window, SetSize(width, height))
}


////////////////////////////////////////////////////////////
void sfWindow_SetTitle(sfWindow* window, const char* title)
{
    CSFML_CALL(window, SetTitle(title))
}


////////////////////////////////////////////////////////////
void sfWindow_Show(sfWindow* window, sfBool show)
{
    CSFML_CALL(window, Show(show == sfTrue))
}


////////////////////////////////////////////////////////////
void sfWindow_EnableKeyRepeat(sfWindow* window, sfBool enabled)
{
    CSFML_CALL(window, EnableKeyRepeat(enabled == sfTrue))
}


////////////////////////////////////////////////////////////
void sfWindow_SetIcon(sfWindow* window, unsigned int width, unsigned int height, const sfUint8* pixels)
{
    CSFML_CALL(window, SetIcon(width, height, pixels))
}


////////////////////////////////////////////////////////////
sfBool sfWindow_SetActive(sfWindow* window, sfBool active)
{
    CSFML_CALL_RETURN(window, SetActive(active == sfTrue), sfFalse)
}


////////////////////////////////////////////////////////////
void sfWindow_Display(sfWindow* window)
{
    CSFML_CALL(window, Display())
}


////////////////////////////////////////////////////////////
void sfWindow_SetFramerateLimit(sfWindow* window, unsigned int limit)
{
    CSFML_CALL(window, SetFramerateLimit(limit))
}


////////////////////////////////////////////////////////////
sfUint32 sfWindow_GetFrameTime(const sfWindow* window)
{
    CSFML_CALL_RETURN(window, GetFrameTime(), 0)
}


////////////////////////////////////////////////////////////
void sfWindow_SetJoystickThreshold(sfWindow* window, float threshold)
{
    CSFML_CALL(window, SetJoystickThreshold(threshold))
}


////////////////////////////////////////////////////////////
sfWindowHandle sfWindow_GetSystemHandle(const sfWindow* window)
{
    CSFML_CHECK_RETURN(window, NULL);

    return (sfWindowHandle)window->This.GetSystemHandle();
}
