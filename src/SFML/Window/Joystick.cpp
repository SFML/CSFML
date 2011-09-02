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
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfBool sfJoystick_IsConnected(unsigned int joystick)
{
    return sf::Joystick::IsConnected(joystick) ? sfTrue : sfFalse;
}


////////////////////////////////////////////////////////////
unsigned int sfJoystick_GetButtonCount(unsigned int joystick)
{
    return sf::Joystick::GetButtonCount(joystick);
}


////////////////////////////////////////////////////////////
sfBool sfJoystick_HasAxis(unsigned int joystick, sfJoystickAxis axis)
{
    return sf::Joystick::HasAxis(joystick, static_cast<sf::Joystick::Axis>(axis)) ? sfTrue : sfFalse;
}


////////////////////////////////////////////////////////////
sfBool sfJoystick_IsButtonPressed(unsigned int joystick, unsigned int button)
{
    return sf::Joystick::IsButtonPressed(joystick, button) ? sfTrue : sfFalse;
}


////////////////////////////////////////////////////////////
float sfJoystick_GetAxisPosition(unsigned int joystick, sfJoystickAxis axis)
{
    return sf::Joystick::GetAxisPosition(joystick, static_cast<sf::Joystick::Axis>(axis));
}


////////////////////////////////////////////////////////////
void sfJoystick_Update(void)
{
    sf::Joystick::Update();
}
