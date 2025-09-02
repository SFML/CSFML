////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2025 Laurent Gomila (laurent@sfml-dev.org)
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
#include <CSFML/Window/Touch.h>
#include <CSFML/Window/WindowBaseStruct.hpp>
#include <CSFML/Window/WindowStruct.hpp>

#include <SFML/Window/Touch.hpp>


////////////////////////////////////////////////////////////
bool sfTouch_isDown(unsigned int finger)
{
    return sf::Touch::isDown(finger);
}

////////////////////////////////////////////////////////////
sfVector2i sfTouch_getPosition(unsigned int finger, const sfWindow* relativeTo)
{
    if (relativeTo)
        return convertVector2(sf::Touch::getPosition(finger, *relativeTo));

    return convertVector2(sf::Touch::getPosition(finger));
}

////////////////////////////////////////////////////////////
sfVector2i sfTouch_getPositionWindowBase(unsigned int finger, const sfWindowBase* relativeTo)
{
    if (relativeTo)
        return convertVector2(sf::Touch::getPosition(finger, *relativeTo));

    return convertVector2(sf::Touch::getPosition(finger));
}
