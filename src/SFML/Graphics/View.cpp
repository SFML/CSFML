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
#include <SFML/Graphics/View.h>
#include <SFML/Graphics/ViewStruct.h>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfView* sfView_Create(void)
{
    return new sfView;
}


////////////////////////////////////////////////////////////
sfView* sfView_CreateFromRect(sfFloatRect rectangle)
{
    sfView* view = new sfView;
    sfView_Reset(view, rectangle);

    return view;
}


////////////////////////////////////////////////////////////
sfView* sfView_Copy(sfView* view)
{
    CSFML_CHECK_RETURN(view, NULL);

    return new sfView(*view);
}


////////////////////////////////////////////////////////////
void sfView_Destroy(sfView* view)
{
    delete view;
}


////////////////////////////////////////////////////////////
void sfView_SetCenter(sfView* view, float x, float y)
{
    CSFML_CALL(view, SetCenter(x, y));
}


////////////////////////////////////////////////////////////
void sfView_SetSize(sfView* view, float width, float height)
{
    CSFML_CALL(view, SetSize(width, height));
}


////////////////////////////////////////////////////////////
void sfView_SetRotation(sfView* view, float angle)
{
    CSFML_CALL(view, SetRotation(angle));
}


////////////////////////////////////////////////////////////
void sfView_SetViewport(sfView* view, sfFloatRect viewport)
{
    CSFML_CALL(view, SetViewport(sf::FloatRect(viewport.Left, viewport.Top, viewport.Width, viewport.Height)));
}


////////////////////////////////////////////////////////////
void sfView_Reset(sfView* view, sfFloatRect rectangle)
{
    CSFML_CALL(view, Reset(sf::FloatRect(rectangle.Left, rectangle.Top, rectangle.Width, rectangle.Height)));
}


////////////////////////////////////////////////////////////
void sfView_GetCenter(const sfView* view, float* x, float* y)
{
    CSFML_CHECK(view);

    sf::Vector2f center = view->This.GetCenter();
    if (x)
        *x = center.x;
    if (y)
        *y = center.y;
}


////////////////////////////////////////////////////////////
void sfView_GetSize(const sfView* view, float* width, float* height)
{
    CSFML_CHECK(view);

    sf::Vector2f size = view->This.GetSize();
    if (width)
        *width = size.x;
    if (height)
        *height = size.y;
}


////////////////////////////////////////////////////////////
float sfView_GetRotation(const sfView* view)
{
    CSFML_CALL_RETURN(view, GetRotation(), 0.f);
}


////////////////////////////////////////////////////////////
sfFloatRect sfView_GetViewport(const sfView* view)
{
    sfFloatRect rect = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(view, rect);

    sf::FloatRect SFMLRect = view->This.GetViewport();
    rect.Left   = SFMLRect.Left;
    rect.Top    = SFMLRect.Top;
    rect.Width  = SFMLRect.Width;
    rect.Height = SFMLRect.Height;

    return rect;
}


////////////////////////////////////////////////////////////
void sfView_Move(sfView* view, float offsetX, float offsetY)
{
    CSFML_CALL(view, Move(offsetX, offsetY));
}


////////////////////////////////////////////////////////////
void sfView_Rotate(sfView* view, float angle)
{
    CSFML_CALL(view, Rotate(angle));
}


////////////////////////////////////////////////////////////
void sfView_Zoom(sfView* view, float factor)
{
    CSFML_CALL(view, Zoom(factor));
}
