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
#include <CSFML/Audio/Listener.h>
#include <CSFML/System/ConvertVector3.hpp>

#include <SFML/Audio/Listener.hpp>


////////////////////////////////////////////////////////////
// Convert sf::Listener::Cone to sfListenerCone
////////////////////////////////////////////////////////////
[[nodiscard]] inline sfListenerCone convertCone(const sf::Listener::Cone cone)
{
    return {cone.innerAngle.asDegrees(), cone.outerAngle.asDegrees(), cone.outerGain};
}


////////////////////////////////////////////////////////////
// Convert sfVector3f to sf::Vector3f
////////////////////////////////////////////////////////////
[[nodiscard]] inline sf::Listener::Cone convertCone(const sfListenerCone cone)
{
    return {sf::degrees(cone.innerAngle), sf::degrees(cone.outerAngle), cone.outerGain};
}


////////////////////////////////////////////////////////////
void sfListener_setGlobalVolume(float volume)
{
    sf::Listener::setGlobalVolume(volume);
}


////////////////////////////////////////////////////////////
float sfListener_getGlobalVolume()
{
    return sf::Listener::getGlobalVolume();
}


////////////////////////////////////////////////////////////
void sfListener_setPosition(sfVector3f position)
{
    sf::Listener::setPosition(convertVector3(position));
}


////////////////////////////////////////////////////////////
sfVector3f sfListener_getPosition()
{
    return convertVector3(sf::Listener::getPosition());
}


////////////////////////////////////////////////////////////
void sfListener_setDirection(sfVector3f direction)
{
    sf::Listener::setDirection(convertVector3(direction));
}


////////////////////////////////////////////////////////////
sfVector3f sfListener_getDirection()
{
    return convertVector3(sf::Listener::getDirection());
}


////////////////////////////////////////////////////////////
void sfListener_setVelocity(sfVector3f velocity)
{
    sf::Listener::setVelocity(convertVector3(velocity));
}


////////////////////////////////////////////////////////////
sfVector3f sfListener_getVelocity()
{
    return convertVector3(sf::Listener::getVelocity());
}


////////////////////////////////////////////////////////////
void sfListener_setCone(sfListenerCone cone)
{
    sf::Listener::setCone(convertCone(cone));
}


////////////////////////////////////////////////////////////
sfListenerCone sfListener_getCone()
{
    return convertCone(sf::Listener::getCone());
}


////////////////////////////////////////////////////////////
void sfListener_setUpVector(sfVector3f upVector)
{
    sf::Listener::setUpVector(convertVector3(upVector));
}


////////////////////////////////////////////////////////////
sfVector3f sfListener_getUpVector()
{
    return convertVector3(sf::Listener::getUpVector());
}
