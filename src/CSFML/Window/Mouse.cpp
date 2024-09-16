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
#include <CSFML/Window/Mouse.h>
#include <CSFML/Window/WindowBaseStruct.hpp>
#include <CSFML/Window/WindowStruct.hpp>

#include <SFML/Window/Mouse.hpp>


////////////////////////////////////////////////////////////
bool sfMouse_isButtonPressed(sfMouseButton button)
{
    return sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(button));
}


////////////////////////////////////////////////////////////
sfVector2i sfMouse_getPosition(const sfWindow* relativeTo)
{
    if (relativeTo)
        return convertVector2(sf::Mouse::getPosition(*relativeTo));

    return convertVector2(sf::Mouse::getPosition());
}


////////////////////////////////////////////////////////////
void sfMouse_setPosition(sfVector2i position, const sfWindow* relativeTo)
{
    if (relativeTo)
        sf::Mouse::setPosition(convertVector2(position), *relativeTo);
    else
        sf::Mouse::setPosition(convertVector2(position));
}


////////////////////////////////////////////////////////////
sfVector2i sfMouse_getPositionWindowBase(const sfWindowBase* relativeTo)
{
    if (relativeTo)
        return convertVector2(sf::Mouse::getPosition(*relativeTo));

    return convertVector2(sf::Mouse::getPosition());
}


////////////////////////////////////////////////////////////
void sfMouse_setPositionWindowBase(sfVector2i position, const sfWindowBase* relativeTo)
{
    if (relativeTo)
        sf::Mouse::setPosition(convertVector2(position), *relativeTo);
    else
        sf::Mouse::setPosition(convertVector2(position));
}
