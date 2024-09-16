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
#include <CSFML/Graphics/ConvertRect.hpp>
#include <CSFML/Graphics/View.h>
#include <CSFML/Graphics/ViewStruct.hpp>
#include <CSFML/System/ConvertVector2.hpp>


////////////////////////////////////////////////////////////
sfView* sfView_create()
{
    return new sfView;
}


////////////////////////////////////////////////////////////
sfView* sfView_createFromRect(sfFloatRect rectangle)
{
    return new sfView{sf::View(convertRect(rectangle))};
}


////////////////////////////////////////////////////////////
sfView* sfView_copy(const sfView* view)
{
    assert(view);
    return new sfView(*view);
}


////////////////////////////////////////////////////////////
void sfView_destroy(const sfView* view)
{
    delete view;
}


////////////////////////////////////////////////////////////
void sfView_setCenter(sfView* view, sfVector2f center)
{
    assert(view);
    view->setCenter(convertVector2(center));
}


////////////////////////////////////////////////////////////
void sfView_setSize(sfView* view, sfVector2f size)
{
    assert(view);
    view->setSize(convertVector2(size));
}


////////////////////////////////////////////////////////////
void sfView_setRotation(sfView* view, float angle)
{
    assert(view);
    view->setRotation(sf::degrees(angle));
}


////////////////////////////////////////////////////////////
void sfView_setViewport(sfView* view, sfFloatRect viewport)
{
    assert(view);
    view->setViewport(convertRect(viewport));
}


////////////////////////////////////////////////////////////
void sfView_setScissor(sfView* view, sfFloatRect scissor)
{
    assert(view);
    view->setScissor(convertRect(scissor));
}


////////////////////////////////////////////////////////////
sfVector2f sfView_getCenter(const sfView* view)
{
    assert(view);
    return convertVector2(view->getCenter());
}


////////////////////////////////////////////////////////////
sfVector2f sfView_getSize(const sfView* view)
{
    assert(view);
    return convertVector2(view->getSize());
}


////////////////////////////////////////////////////////////
float sfView_getRotation(const sfView* view)
{
    assert(view);
    return view->getRotation().asDegrees();
}


////////////////////////////////////////////////////////////
sfFloatRect sfView_getViewport(const sfView* view)
{
    assert(view);
    return convertRect(view->getViewport());
}


////////////////////////////////////////////////////////////
sfFloatRect sfView_getScissor(const sfView* view)
{
    assert(view);
    return convertRect(view->getScissor());
}


////////////////////////////////////////////////////////////
void sfView_move(sfView* view, sfVector2f offset)
{
    assert(view);
    view->move(convertVector2(offset));
}


////////////////////////////////////////////////////////////
void sfView_rotate(sfView* view, float angle)
{
    assert(view);
    view->rotate(sf::degrees(angle));
}


////////////////////////////////////////////////////////////
void sfView_zoom(sfView* view, float factor)
{
    assert(view);
    view->zoom(factor);
}
