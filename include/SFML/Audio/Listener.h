////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2013 Laurent Gomila (laurent.gom@gmail.com)
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

#ifndef SFML_LISTENER_H
#define SFML_LISTENER_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Audio/Export.h>
#include <SFML/System/Vector3.h>


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
CSFML_AUDIO_API sfVector3f sfListener_getPosition();

////////////////////////////////////////////////////////////
/// \brief Set the orientation of the listener in the scene
///
/// The orientation defines the 3D axes of the listener
/// (left, up, front) in the scene. The orientation vector
/// doesn't have to be normalized.
/// The default listener's orientation is (0, 0, -1).
///
/// \param position New direction of the listener
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfListener_setDirection(sfVector3f orientation);

////////////////////////////////////////////////////////////
/// \brief Get the current orientation of the listener in the scene
///
/// \return The listener's direction
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfVector3f sfListener_getDirection();


#endif // SFML_LISTENER_H
