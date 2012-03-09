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
#include <SFML/Audio/Listener.h>
#include <SFML/Audio/Listener.hpp>



////////////////////////////////////////////////////////////
void sfListener_SetGlobalVolume(float volume)
{
    sf::Listener::SetGlobalVolume(volume);
}


////////////////////////////////////////////////////////////
float sfListener_GetGlobalVolume(void)
{
    return sf::Listener::GetGlobalVolume();
}


////////////////////////////////////////////////////////////
void sfListener_SetPosition(sfVector3f position)
{
    sf::Listener::SetPosition(position.x, position.y, position.z);
}


////////////////////////////////////////////////////////////
sfVector3f sfListener_GetPosition()
{
    sf::Vector3f sfmlPos = sf::Listener::GetPosition();
    sfVector3f position = {sfmlPos.x, sfmlPos.y, sfmlPos.z};
    return position;
}


////////////////////////////////////////////////////////////
void sfListener_SetDirection(sfVector3f direction)
{
    sf::Listener::SetDirection(direction.x, direction.y, direction.z);
}


////////////////////////////////////////////////////////////
sfVector3f sfListener_GetDirection()
{
    sf::Vector3f sfmlDirection = sf::Listener::GetDirection();
    sfVector3f direction = {sfmlDirection.x, sfmlDirection.y, sfmlDirection.z};
    return direction;
}
