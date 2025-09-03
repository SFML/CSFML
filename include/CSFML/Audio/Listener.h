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

#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Audio/Export.h>

#include <CSFML/System/Vector3.h>


////////////////////////////////////////////////////////////
/// \brief Structure defining the properties of a directional cone
///
/// Sounds will play at gain 1 when they are positioned
/// within the inner angle of the cone. Sounds will play
/// at `outerGain` when they are positioned outside the
/// outer angle of the cone. The gain declines linearly
/// from 1 to `outerGain` as the sound moves from the inner
/// angle to the outer angle.
///
////////////////////////////////////////////////////////////
typedef struct
{
    float innerAngle; //!< Inner angle, in degrees
    float outerAngle; //!< Outer angle, in degrees
    float outerGain;  //!< Outer gain
} sfListenerCone;


////////////////////////////////////////////////////////////
/// \brief Change the global volume of all the sounds and musics
///
/// The volume is a number between 0 and 100; it is combined with
/// the individual volume of each sound / music.
/// The default value for the volume is 100 (maximum).
///
/// \param volume New global volume, in the range [0, 100]
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfListener_setGlobalVolume(float volume);

////////////////////////////////////////////////////////////
/// \brief Get the current value of the global volume
///
/// \return Current global volume, in the range [0, 100]
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfListener_getGlobalVolume(void);

////////////////////////////////////////////////////////////
/// \brief Set the position of the listener in the scene
///
/// The default listener's position is (0, 0, 0).
///
/// \param position New position of the listener
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfListener_setPosition(sfVector3f position);

////////////////////////////////////////////////////////////
/// \brief Get the current position of the listener in the scene
///
/// \return The listener's position
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfVector3f sfListener_getPosition(void);

////////////////////////////////////////////////////////////
/// \brief Set the orientation of the forward vector in the scene
///
/// The direction (also called "at vector") is the vector
/// pointing forward from the listener's perspective. Together
/// with the up vector, it defines the 3D orientation of the
/// listener in the scene. The direction vector doesn't
/// have to be normalized.
/// The default listener's direction is (0, 0, -1).
///
/// \param direction New listener's direction
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfListener_setDirection(sfVector3f direction);

////////////////////////////////////////////////////////////
/// \brief Get the current forward vector of the listener in the scene
///
/// \return Listener's forward vector (not normalized)
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfVector3f sfListener_getDirection(void);

////////////////////////////////////////////////////////////
/// \brief Set the velocity of the listener in the scene
///
/// The default listener's velocity is (0, 0, -1).
///
/// \param velocity New listener's velocity
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfListener_setVelocity(sfVector3f velocity);

////////////////////////////////////////////////////////////
/// \brief Get the current forward vector of the listener in the scene
///
/// \return Listener's velocity
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfVector3f sfListener_getVelocity(void);

////////////////////////////////////////////////////////////
/// \brief Set the cone properties of the listener in the audio scene
///
/// The cone defines how directional attenuation is applied.
/// The default cone of a sound is (2 * PI, 2 * PI, 1).
///
/// \param cone Cone properties of the listener in the scene
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfListener_setCone(sfListenerCone cone);

////////////////////////////////////////////////////////////
/// \brief Get the cone properties of the listener in the audio scene
///
/// \return Cone properties of the listener
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfListenerCone sfListener_getCone(void);

////////////////////////////////////////////////////////////
/// \brief Set the upward vector of the listener in the scene
///
/// The up vector is the vector that points upward from the
/// listener's perspective. Together with the direction, it
/// defines the 3D orientation of the listener in the scene.
/// The up vector doesn't have to be normalized.
/// The default listener's up vector is (0, 1, 0). It is usually
/// not necessary to change it, especially in 2D scenarios.
///
/// \param upVector New listener's up vector
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfListener_setUpVector(sfVector3f upVector);

////////////////////////////////////////////////////////////
/// \brief Get the current upward vector of the listener in the scene
///
/// \return Listener's upward vector (not normalized)
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfVector3f sfListener_getUpVector(void);
