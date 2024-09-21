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

#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Audio/SoundSourceCone.h>

#include <SFML/Audio/SoundSource.hpp>


////////////////////////////////////////////////////////////
// Convert sf::SoundSource::Cone to sfSoundSourceCone
////////////////////////////////////////////////////////////
[[nodiscard]] inline sfSoundSourceCone convertCone(const sf::SoundSource::Cone cone)
{
    return {cone.innerAngle.asDegrees(), cone.outerAngle.asDegrees(), cone.outerGain};
}


////////////////////////////////////////////////////////////
// Convert sfSoundSourceCone to sf::SoundSource::Cone
////////////////////////////////////////////////////////////
[[nodiscard]] inline sf::SoundSource::Cone convertCone(const sfSoundSourceCone cone)
{
    return {sf::degrees(cone.innerAngle), sf::degrees(cone.outerAngle), cone.outerGain};
}
