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
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Internal.h>
#include <SFML/System/String.hpp>

#include <string.h>


////////////////////////////////////////////////////////////
sfBool sfKeyboard_isKeyPressed(sfKeyCode key)
{
    return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key));
}


////////////////////////////////////////////////////////////
sfBool sfKeyboard_isScancodePressed(sfScancode code)
{
    return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Scancode>(code));
}


////////////////////////////////////////////////////////////
sfKeyCode sfKeyboard_localize(sfScancode code)
{
    return static_cast<sfKeyCode>(sf::Keyboard::localize(static_cast<sf::Keyboard::Scancode>(code)));
}


////////////////////////////////////////////////////////////
sfScancode sfKeyboard_delocalize(sfKeyCode key)
{
    return static_cast<sfScancode>(sf::Keyboard::delocalize(static_cast<sf::Keyboard::Key>(key)));
}


////////////////////////////////////////////////////////////
const char* sfKeyboard_getDescription(sfScancode code)
{
    return strdup(sf::Keyboard::getDescription(static_cast<sf::Keyboard::Scancode>(code)).toAnsiString().c_str());
}


////////////////////////////////////////////////////////////
void sfKeyboard_setVirtualKeyboardVisible(sfBool visible)
{
    sf::Keyboard::setVirtualKeyboardVisible(visible == sfTrue);
}
