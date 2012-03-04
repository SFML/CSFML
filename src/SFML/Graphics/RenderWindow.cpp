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
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/RenderWindowStruct.h>
#include <SFML/Graphics/ImageStruct.h>
#include <SFML/Graphics/SpriteStruct.h>
#include <SFML/Graphics/TextStruct.h>
#include <SFML/Graphics/ShapeStruct.h>
#include <SFML/Graphics/CircleShapeStruct.h>
#include <SFML/Graphics/ConvexShapeStruct.h>
#include <SFML/Graphics/RectangleShapeStruct.h>
#include <SFML/Graphics/VertexArrayStruct.h>
#include <SFML/Graphics/ConvertRenderStates.hpp>
#include <SFML/Internal.h>
#include <SFML/ConvertEvent.h>


////////////////////////////////////////////////////////////
sfRenderWindow* sfRenderWindow_Create(sfVideoMode mode, const char* title, sfUint32 style, const sfContextSettings* settings)
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
    sfRenderWindow* renderWindow = new sfRenderWindow;
    renderWindow->This.Create(videoMode, title, style, params);
    renderWindow->DefaultView.This = renderWindow->This.GetDefaultView();
    renderWindow->CurrentView.This = renderWindow->This.GetView();

    return renderWindow;
}


////////////////////////////////////////////////////////////
sfRenderWindow* sfRenderWindow_CreateFromHandle(sfWindowHandle handle, const sfContextSettings* settings)
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
    sfRenderWindow* renderWindow = new sfRenderWindow;
    renderWindow->This.Create(handle, params);
    renderWindow->DefaultView.This = renderWindow->This.GetDefaultView();
    renderWindow->CurrentView.This = renderWindow->This.GetView();

    return renderWindow;
}


////////////////////////////////////////////////////////////
void sfRenderWindow_Destroy(sfRenderWindow* renderWindow)
{
    delete renderWindow;
}


////////////////////////////////////////////////////////////
void sfRenderWindow_Close(sfRenderWindow* renderWindow)
{
    CSFML_CALL(renderWindow, Close());
}


////////////////////////////////////////////////////////////
sfBool sfRenderWindow_IsOpen(const sfRenderWindow* renderWindow)
{
    CSFML_CALL_RETURN(renderWindow, IsOpen(), sfFalse);
}


////////////////////////////////////////////////////////////
unsigned int sfRenderWindow_GetWidth(const sfRenderWindow* renderWindow)
{
    CSFML_CALL_RETURN(renderWindow, GetWidth(), 0);
}


////////////////////////////////////////////////////////////
unsigned int sfRenderWindow_GetHeight(const sfRenderWindow* renderWindow)
{
    CSFML_CALL_RETURN(renderWindow, GetHeight(), 0);
}


////////////////////////////////////////////////////////////
sfContextSettings sfRenderWindow_GetSettings(const sfRenderWindow* renderWindow)
{
    sfContextSettings settings = {0, 0, 0, 2, 0};
    CSFML_CHECK_RETURN(renderWindow, settings);

    const sf::ContextSettings& params = renderWindow->This.GetSettings();
    settings.DepthBits         = params.DepthBits;
    settings.StencilBits       = params.StencilBits;
    settings.AntialiasingLevel = params.AntialiasingLevel;

    return settings;
}


////////////////////////////////////////////////////////////
sfBool sfRenderWindow_PollEvent(sfRenderWindow* renderWindow, sfEvent* event)
{
    CSFML_CHECK_RETURN(renderWindow, sfFalse);
    CSFML_CHECK_RETURN(event,        sfFalse);

    // Get the event
    sf::Event SFMLEvent;
    sfBool ret = renderWindow->This.PollEvent(SFMLEvent);

    // No event, return
    if (!ret)
        return sfFalse;

    // Convert the sf::Event event to a sfEvent
    ConvertEvent(SFMLEvent, event);

    return sfTrue;
}


////////////////////////////////////////////////////////////
sfBool sfRenderWindow_WaitEvent(sfRenderWindow* renderWindow, sfEvent* event)
{
    CSFML_CHECK_RETURN(renderWindow, sfFalse);
    CSFML_CHECK_RETURN(event,        sfFalse);

    // Get the event
    sf::Event SFMLEvent;
    sfBool ret = renderWindow->This.WaitEvent(SFMLEvent);

    // Error, return
    if (!ret)
        return sfFalse;

    // Convert the sf::Event event to a sfEvent
    ConvertEvent(SFMLEvent, event);

    return sfTrue;
}


////////////////////////////////////////////////////////////
void sfRenderWindow_EnableVerticalSync(sfRenderWindow* renderWindow, sfBool enabled)
{
    CSFML_CALL(renderWindow, EnableVerticalSync(enabled == sfTrue));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_ShowMouseCursor(sfRenderWindow* renderWindow, sfBool show)
{
    CSFML_CALL(renderWindow, ShowMouseCursor(show == sfTrue));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_SetPosition(sfRenderWindow* renderWindow, int left, int top)
{
    CSFML_CALL(renderWindow, SetPosition(left, top));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_SetSize(sfRenderWindow* renderWindow, unsigned int width, unsigned int height)
{
    CSFML_CALL(renderWindow, SetSize(width, height));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_SetTitle(sfRenderWindow* renderWindow, const char* title)
{
    CSFML_CALL(renderWindow, SetTitle(title));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_Show(sfRenderWindow* renderWindow, sfBool show)
{
    CSFML_CALL(renderWindow, Show(show == sfTrue));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_EnableKeyRepeat(sfRenderWindow* renderWindow, sfBool enabled)
{
    CSFML_CALL(renderWindow, EnableKeyRepeat(enabled == sfTrue));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_SetIcon(sfRenderWindow* renderWindow, unsigned int width, unsigned int height, const sfUint8* pixels)
{
    CSFML_CALL(renderWindow, SetIcon(width, height, pixels));
}


////////////////////////////////////////////////////////////
sfBool sfRenderWindow_SetActive(sfRenderWindow* renderWindow, sfBool active)
{
    CSFML_CALL_RETURN(renderWindow, SetActive(active == sfTrue), sfFalse);
}


////////////////////////////////////////////////////////////
void sfRenderWindow_Display(sfRenderWindow* renderWindow)
{
    CSFML_CALL(renderWindow, Display());
}


////////////////////////////////////////////////////////////
void sfRenderWindow_SetFramerateLimit(sfRenderWindow* renderWindow, unsigned int limit)
{
    CSFML_CALL(renderWindow, SetFramerateLimit(limit));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_SetJoystickThreshold(sfRenderWindow* renderWindow, float threshold)
{
    CSFML_CALL(renderWindow, SetJoystickThreshold(threshold));
}


////////////////////////////////////////////////////////////
sfWindowHandle sfRenderWindow_GetSystemHandle(const sfRenderWindow* renderWindow)
{
    CSFML_CHECK_RETURN(renderWindow, 0);

    return (sfWindowHandle)renderWindow->This.GetSystemHandle();
}


////////////////////////////////////////////////////////////
void sfRenderWindow_Clear(sfRenderWindow* renderWindow, sfColor color)
{
    sf::Color SFMLColor(color.r, color.g, color.b, color.a);

    CSFML_CALL(renderWindow, Clear(SFMLColor));
}


////////////////////////////////////////////////////////////
void sfRenderWindow_SetView(sfRenderWindow* renderWindow, const sfView* view)
{
    CSFML_CHECK(view);
    CSFML_CALL(renderWindow, SetView(view->This));
    renderWindow->CurrentView.This = view->This;
}


////////////////////////////////////////////////////////////
const sfView* sfRenderWindow_GetView(const sfRenderWindow* renderWindow)
{
    CSFML_CHECK_RETURN(renderWindow, NULL);

    return &renderWindow->CurrentView;
}


////////////////////////////////////////////////////////////
const sfView* sfRenderWindow_GetDefaultView(const sfRenderWindow* renderWindow)
{
    CSFML_CHECK_RETURN(renderWindow, NULL);

    return &renderWindow->DefaultView;
}


////////////////////////////////////////////////////////////
sfIntRect sfRenderWindow_GetViewport(const sfRenderWindow* renderWindow, const sfView* view)
{
    sfIntRect rect = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(view, rect);
    CSFML_CHECK_RETURN(renderWindow, rect);

    sf::IntRect SFMLrect = renderWindow->This.GetViewport(view->This);
    rect.Left   = SFMLrect.Left;
    rect.Top    = SFMLrect.Top;
    rect.Width  = SFMLrect.Width;
    rect.Height = SFMLrect.Height;

    return rect;
}


////////////////////////////////////////////////////////////
void sfRenderWindow_ConvertCoords(const sfRenderWindow* renderWindow, unsigned int windowX, unsigned int windowY, float* viewX, float* viewY, const sfView* targetView)
{
    CSFML_CHECK(renderWindow);

    sf::Vector2f point;
    if (targetView)
        point = renderWindow->This.ConvertCoords(windowX, windowY, targetView->This);
    else
        point = renderWindow->This.ConvertCoords(windowX, windowY);

    if (viewX) *viewX = point.x;
    if (viewY) *viewY = point.y;
}


////////////////////////////////////////////////////////////
void sfRenderWindow_DrawSprite(sfRenderWindow* renderWindow, const sfSprite* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderWindow, Draw(object->This, ConvertRenderStates(states)));
}
void sfRenderWindow_DrawText(sfRenderWindow* renderWindow, const sfText* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderWindow, Draw(object->This, ConvertRenderStates(states)));
}
void sfRenderWindow_DrawShape(sfRenderWindow* renderWindow, const sfShape* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderWindow, Draw(object->This, ConvertRenderStates(states)));
}
void sfRenderWindow_DrawCircleShape(sfRenderWindow* renderWindow, const sfCircleShape* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderWindow, Draw(object->This, ConvertRenderStates(states)));
}
void sfRenderWindow_DrawConvexShape(sfRenderWindow* renderWindow, const sfConvexShape* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderWindow, Draw(object->This, ConvertRenderStates(states)));
}
void sfRenderWindow_DrawRectangleShape(sfRenderWindow* renderWindow, const sfRectangleShape* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderWindow, Draw(object->This, ConvertRenderStates(states)));
}
void sfRenderWindow_DrawVertexArray(sfRenderWindow* renderWindow, const sfVertexArray* object, const sfRenderStates* states)
{
    CSFML_CHECK(object);
    CSFML_CALL(renderWindow, Draw(object->This, ConvertRenderStates(states)));
}


////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_DrawPrimitives(sfRenderWindow* renderWindow,
                                             const sfVertex* vertices, unsigned int vertexCount,
                                             sfPrimitiveType type, const sfRenderStates* states)
{
    CSFML_CALL(renderWindow, Draw(reinterpret_cast<const sf::Vertex*>(vertices), vertexCount,
               static_cast<sf::PrimitiveType>(type), ConvertRenderStates(states)));
}


////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_PushGLStates(sfRenderWindow* renderWindow)
{
    CSFML_CALL(renderWindow, PushGLStates());
}


////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_PopGLStates(sfRenderWindow* renderWindow)
{
    CSFML_CALL(renderWindow, PopGLStates());
}


////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_ResetGLStates(sfRenderWindow* renderWindow)
{
    CSFML_CALL(renderWindow, ResetGLStates());
}


////////////////////////////////////////////////////////////
/// Copy the current contents of a window to an image
////////////////////////////////////////////////////////////
sfImage* sfRenderWindow_Capture(const sfRenderWindow* renderWindow)
{
    CSFML_CHECK_RETURN(renderWindow, NULL);

    sfImage* image = new sfImage;
    image->This = renderWindow->This.Capture();

    return image;
}
